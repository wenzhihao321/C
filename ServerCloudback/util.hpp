#ifndef _MY_UTIL_
#define _MY_UTIL_
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <experimental/filesystem>
#include <jsoncpp/json/json.h>
#include <sys/stat.h>
#include "bundle.h"

namespace cloud
{
  namespace fs = std::experimental::filesystem;
  class FileUtil{
      private:
        std::string filename;
      
      public:
        FileUtil(const std::string &fn)
          :filename(fn)
        {}
        bool ReMove()
        {
            if(this->Exists() == false)
            {
              return true;
            }
            remove(filename.c_str());
            return true;
        }
        //获取文件大小
        int64_t GetFilesize()
        {
          struct stat st;   //文件属性
          //获取文件属性
          if( stat( filename.c_str(),&st) < 0)
          {
              std::cout<<"Get filenamesize failed"<<std::endl;
              return -1;
          }
          //成功获取
          return  st.st_size; 
        }   
        
        //获取文件最后一次访问时间
       time_t LastAccTime()
       {
          struct stat st;   //文件属性
          //获取文件属性
          if( stat( filename.c_str(),&st) < 0)
          {
              std::cout<<"Get LastAccTime failed"<<std::endl;
              return -1;
          }
          //成功获取
          return  st.st_atime; 
       }
        //获取文件最后一次修改时间 
       time_t LastModTime()
       {
          struct stat st;   //文件属性
          //获取文件属性
          if( stat( filename.c_str(),&st) < 0)
          {
              std::cout<<"Get LastModTime failed"<<std::endl;
              return -1;
          }
          //成功获取
          return  st.st_mtime; 
       }
        //获取文件名
       std::string Getfilename()
       {
         size_t pos = filename.find_last_of("/");//获取最后一个'/'的位置
         if(pos == std::string::npos)
         {
           //失败
           return filename;
         }
         return filename.substr(pos + 1);//获取pos位置后的字符
       }
       //获取指定位置的文件数据
       bool GetPosLen(std::string *body,size_t pos,size_t len)
       {
          size_t fsize = this->GetFilesize();
          //判断给的pos是否超出文件大小
          if(pos + len > fsize)
          {
            std::cout<<"get file len is error"<<std::endl;
          }

          std::ifstream ifs;
          ifs.open(filename,std::ios::binary);
          if(ifs.is_open() == false)
          {
            std::cout<<"read file failed!"<<std::endl;
            return false;
          }
          ifs.seekg(pos,std::ios::beg);
          body->resize(len);
          ifs.read(&(*body)[0],fsize);
          //把数据读出来后判断读流是否正常
          if(ifs.good() == false)
          {
            std::cout<<"get file content failed!"<<std::endl;
            ifs.close();
            return false;
          }
          ifs.close();
          return true;
       }
       
       //获取文件全部数据
       bool Getcontent(std::string *body)
       {
         size_t fsize = this->GetFilesize();
         return GetPosLen(body,0,fsize);
       }
       
       //将文件数据写入新文件,如果没有body会新建一个body文件
       bool Setcontent(const std::string &body)
       {
         std::ofstream ofs;
         ofs.open(filename,std::ios::binary);
         if(ofs.is_open() == false)
         {
           std::cout<<"write file failed!"<<std::endl;
           return false;
         }
         ofs.write(&body[0],body.size());
         if(ofs.good() == false)
         {
            std::cout<<"write file content failed!"<<std::endl;
            ofs.close();
            return false;
         }
         ofs.close();
         return true;
       }

       //压缩文件
       bool Compress(const std::string &packname)
       {
         //获取文件数据
         std::string body;
         //body是文件数据的拷贝
         if(this->Getcontent(&body) == false)
         {
            std::cout<<"get file content failed!"<<std::endl;
            return false;
         }
        
         //将获取的数据压缩
         std::string packed = bundle::pack(bundle::LZIP,body);
         
         //将压缩的数据存到压缩文件中
         FileUtil p(packname);
         if(p.Setcontent(packed) == false)
         {
            std::cout<<"compress file failed!"<<std::endl;
            return false;
         }
         return true;
       }
       
       //解压文件
      bool Uncompress(const std::string &unpackname)
      {
        //压缩包的数据读取出来
        std::string body;
        if(this->Getcontent(&body) == false)
         {
            std::cout<<"uncompress get file content failed!"<<std::endl;
            return false;
         }
        
        //对压缩数据进行解压
        std::string unpacked = bundle::unpack(body);
        //将解压的数据写入新文件中
        FileUtil up(unpackname);
        if(up.Setcontent(unpacked) == false)
         {
            std::cout<<"uncompress file failed!"<<std::endl;
            return false;
         }
        return true;
      }
      
      //文件是否存在
      bool Exists()
      {
        return fs::exists(filename);
      }

      //创建目录
      bool CreateDirectory()
      {
        if(this->Exists())
        {
          return true;
        }
        //不存在就创建一个目录
        return fs::create_directories(filename);
      }

      //查看目录
      bool ScanDirectory(std::vector<std::string> *arry)
      {
        //遍历目录
        for(auto& p : fs::directory_iterator(filename))
        {
          if(fs::is_directory(p) == true)
          {
            //如果是目录继续遍历下一个目录
            continue;
          }
          //将文件放入目录  relative_path带有路径的文件名
          arry->push_back(fs::path(p).relative_path().string());
        }
        return  true;
      }
  };
  class jsonutil
  {
    public:
      //序列化
      static bool Serialize(const Json::Value &root,std::string *str)
      {
        Json::StreamWriterBuilder swb;
        std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
        //从string对象中读取字符或字符串
        std::stringstream ss;
        //成功则返回0
        if(sw->write(root,&ss) != 0)
        {
          std::cout<<"Json write failed!"<<std::endl;
          return false;
        }
        *str = ss.str();
        return true;
      }
      //反序列化
      static bool Unserialize(const std::string &str, Json::Value *root)
      {
        Json::CharReaderBuilder crb;
        std::unique_ptr<Json::CharReader> cr(crb.newCharReader());
        std:: string error;
        bool ret = cr->parse(str.c_str(),str.c_str() + str.size(), root, &error);
        //成功返回1，失败返回0
        if(ret == 0)
        {
          std::cout<<"Json read failed!"<<std::endl;
          return false;
        }
        return true;
      }
  };
}
#endif
