#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#ifndef _MY_UTIL_
#define _MY_UTIL_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <experimental/filesystem>
#include <sys/stat.h>



namespace cloud
{
    namespace fs = std::experimental::filesystem;
    class FileUtil {
    private:
        std::string filename;

    public:
        FileUtil(const std::string& fn)
            :filename(fn)
        {}
        bool Setcontent(const std::string& body)
        {
            std::ofstream ofs;
            ofs.open(filename, std::ios::binary);
            if (ofs.is_open() == false)
            {
                std::cout << "write file failed!" << std::endl;
                return false;
            }
            ofs.write(&body[0], body.size());
            if (ofs.good() == false)
            {
                std::cout << "write file content failed!" << std::endl;
                ofs.close();
                return false;
            }
            ofs.close();
            return true;
        }
        //获取文件最后一次访问时间
        time_t LastAccTime()
        {
            struct stat st;   //文件属性
            //获取文件属性
            if (stat(filename.c_str(), &st) < 0)
            {
                std::cout << "Get LastAccTime failed" << std::endl;
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
            if (stat(filename.c_str(), &st) < 0)
            {
                std::cout << "Get LastModTime failed" << std::endl;
                return -1;
            }
            //成功获取
            return  st.st_mtime;
        }
        std::string Getfilename()
        {
            size_t pos = filename.find_last_of("\\");//获取最后一个'/'的位置
            if (pos == std::string::npos)
            {
                //失败
                return filename;
            }
            //可以直接调用系统接口
            // return fs::path(filename).filename().string();
            return filename.substr(pos + 1);//获取pos位置后的字符
        }
        size_t GetFilesize()
        {
            struct stat st;   //文件属性
            //获取文件属性
            if (stat(filename.c_str(), &st) < 0)
            {
                std::cout << "Get filenamesize failed" << std::endl;
                return -1;
            }
            //成功获取
            return  st.st_size;
        }
        bool GetPosLen(std::string* body, size_t pos, size_t len)
        {
            size_t fsize = this->GetFilesize();
            //判断给的pos是否超出文件大小
            if (pos + len > fsize)
            {
                std::cout << "get file len is error" << std::endl;
            }

            std::ifstream ifs;
            ifs.open(filename, std::ios::binary);
            if (ifs.is_open() == false)
            {
                std::cout << "read file failed!" << std::endl;
                return false;
            }
            ifs.seekg(pos, std::ios::beg);
            body->resize(len);
            ifs.read(&(*body)[0], fsize);
            //把数据读出来后判断读流是否正常
            if (ifs.good() == false)
            {
                std::cout << "get file content failed!" << std::endl;
                ifs.close();
                return false;
            }
            ifs.close();
            return true;
        }

        //获取文件全部数据
        bool Getcontent(std::string* body)
        {
            size_t fsize = this->GetFilesize();
            return GetPosLen(body, 0, fsize);
        }
        bool ReMove()
        {
            if (this->Exists() == false)
            {
                return true;
            }
            remove(filename.c_str());
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
            if (this->Exists())
            {
                return true;
            }
            //不存在就创建一个目录
            return fs::create_directories(filename);
        }

        //查看目录
        bool ScanDirectory(std::vector<std::string>* arry)
        {
            this->CreateDirectory();
            //遍历目录
            for (auto& p : fs::directory_iterator(filename))
            {
                if (fs::is_directory(p) == true)
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
}
#endif
