#ifndef _MY_SERVICE_
#define _MY_SERVICE_ 
#include "data.hpp"
#include "httplib.h"

extern cloud::DateManager *_data;
namespace cloud 
{
  class Service{
    private:
      int _server_port;
      std::string _server_ip;
      std::string _download_prefix;
      httplib::Server _server;
    private:
      static void UpLoad(const httplib::Request &req,httplib::Response &rsp)
      {
        //post /upload  文件数据在正文中（正文并不全是文件数据）
        //判断有没有文件上传
        auto ret = req.has_file("file");
        if(ret == false)
        {
          rsp.status = 400;
          return;
        }
        const auto& file = req.get_file_value("file");
        std::string back_dir = Config::GetInstance()->GetBackDir();
        //realpath  ==  ./backdir/a.txt
        std::string realpath = back_dir + FileUtil(file.filename).Getfilename();
        FileUtil fu(realpath);
        //将数据写入文件中
        fu.Setcontent(file.content);
        BackupInfo info;
        //创建文件的备份信息实体
        info.NewBackupInfo(realpath);
        //将备份信息插入数据管理模块中
        _data->Insert(info);
        return;
      }
      static std::string TimeToStr(time_t t)
      {
        std::string tmp = std::ctime(&t);
        return tmp;
      }
      static void ListShow(const httplib::Request &req,httplib::Response &rsp)
      {
        //1.获取所有的文件备份信息
        std::vector<BackupInfo> arry;
        _data->GetAll(&arry);
        //2.根据所有备份信息，组织html
        std::stringstream ss;
        ss << "<html><head><title>Download</title></head>";
        ss << "<body><h1>Download</h1><table>";
        for (auto &a : arry ){
          ss << "<tr>";
          std:: string filename = FileUtil(a.real_path).Getfilename();
          ss << "<td><a href='" << a.url << "'>" << filename << "</a></td>";
          ss << "<td align='right'>" << TimeToStr(a.mtime) << "</td>";
          ss << "<td align='right'>" << a.fsize / 1024 << "k</td>" ;
          ss << "</tr>";
        }
          ss << "</table></body></html>" ;
          rsp.body = ss.str();
          rsp.set_header("Content-Type","text/html");
          rsp.status = 200;
          return;
      }
      static std::string GetETag(const BackupInfo &info)
      {
        // etg : filename-fszie-mtime 
        FileUtil fu(info.real_path);
        std::string etag =fu.Getfilename();
        etag += "-";
        etag += std::to_string(info.fsize);
        etag += "-";
        etag += std::to_string(info.mtime);
        return etag;
      }
      static void DownLoad(const httplib::Request &req,httplib::Response &rsp)
      {
        //1.获取客户端请求的资源路径path    req.path == /download/a.txt
        //2.根据资源路径，获取文件备份信息
        BackupInfo info;
        _data->GetOneURL(req.path,&info);
        //3.判断文件是否被压缩，如果被压缩，要先解压缩
        if(info.pack_flag == true)
        {
          FileUtil fu(info.pack_path);
          fu.Uncompress(info.real_path);
          //4删除压缩包，修改备份信息（已经没有被压缩）
          fu.ReMove();
          info.pack_flag = false;
          _data->Updata(info);
        }
        
        //用来标识是否断点续传
        bool Ifrange = false;
        std::string old_etag;        
        //If-Range用于服务端判断这个文件与原先下载的文件是否一致
        if(req.has_header("If-Range")) //判断是否有If-Range字段
        {
          //有则获取文件唯一标识：filename-fszie-mtime
          old_etag = req.get_header_value("If-Range");
          //判断这个字段的值与请求文件的最新etag一致则符合断点续传
          if(old_etag == GetETag(info))
          {
            Ifrange = true;
          }
        }
        
        //4.读取文件数据，放入rsp.body中
        FileUtil fu1(info.real_path); //   ./backdir/a.txt

        //false则正常下载全文
        if(Ifrange == false)
        {
          fu1.Getcontent(&rsp.body);
          //5.设置响应头部字段：ETag  ，  Accept-Ranges：bytes
          rsp.set_header("Accept-Ranges","bytes");  //告诉客户端服务器支持断点续传功能
          rsp.set_header("ETag",GetETag(info));   //客户端收到响应会保存这个信息
          rsp.set_header("Content-Type","application/octet-stream");
          rsp.status = 200;          
          return;
        }
        //断点续传
        else
        {
          //httplib内部实现了对于区间请求也就是断点续传请求的处理
          //只需要我们用户将文件所有数据读取到rsp.body中，它内部会自动根据请求区间，
          //从body中取出指定区间数据进行响应
          //如果内部没有处理则需要std::string range = req.get_header_val("Range");   bytes=start-end
          //获得start-end的数据放入body中
          fu1.Getcontent(&rsp.body);
          rsp.set_header("Accept-Ranges","bytes");
          rsp.set_header("ETag",GetETag(info));
          //rsp.set_header("Content-Range", "bytes start-end/fsize");
          rsp.set_header("Content-Type","application/octet-stream");
          rsp.status = 206; //区间请求响应的是206****
        }
      }
    public:
      Service()
      {
        Config *config = Config::GetInstance();
        _server_port = config->GetServerPort();
        _server_ip = config->GetServerIp();
        _download_prefix = config->GetDownloadPrefix();
      }
      bool RunModule()     
      {
        _server.Post("/upload",UpLoad); 
        _server.Get("/listshow",ListShow);
        _server.Get("/",ListShow);
        _server.Get("/download/(.*)",DownLoad);
        _server.listen(_server_ip.c_str(),_server_port);
        return true;
      }
  };
}




#endif 
