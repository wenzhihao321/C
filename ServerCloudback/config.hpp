#ifndef _MY_CONFIG_
#define _MY_CONFIG_
#include "util.hpp"

namespace cloud
{
#define Config_file "./cloud.conf"
  class Config{
      private:
        static std::mutex _mutex;
        static Config *_instance;
        Config(){
          LoadConfigFile();
        }
      private:
        //热点时间
        int _hot_time;
        //服务器端口号
        int _server_port;
        //服务器ip
        std::string _server_ip;
        //下载的URL前缀路径
        std::string _download_prefix; 
        //压缩包后缀名称
        std::string _packfile_suffix;
        //压缩包目录
        std::string _pack_dir;
        //备份文件目录
        std::string _back_dir;
        //存放数据信息存放文件
        std::string _backup_file;
        bool LoadConfigFile()
        {
          std::string body;
          FileUtil fu(Config_file); 
          //获取配置文件数据
          if(fu.Getcontent(&body) == false)
          {
            std::cout<<"load config content failed!"<<std::endl;
            return false;
          }
          //加载配置文件信息
          Json::Value root;
          if(jsonutil::Unserialize(body,&root) == false)
          {
            std::cout<<"get config content failed!"<<std::endl;
            return false;
          }
          _hot_time = root["hot_time"].asInt();
          _server_port = root["server_port"].asInt();
          _server_ip = root["server_ip"].asString();
          _download_prefix = root["download_prefix"].asString();
          _packfile_suffix = root["packfile_suffix"].asString();
          _pack_dir = root["pack_dir"].asString();
          _back_dir = root["back_dir"].asString();
          _backup_file = root["backup_file"].asString();
          return true;
        }
      public:
        static Config* GetInstance()
        {
            if(_instance == nullptr)
            {
              _mutex.lock();
              if(_instance == nullptr)
              {
                  _instance = new Config();
              }
              _mutex.unlock();
            }
            return _instance;
        }
        int GetHotTime()
        {
          return _hot_time;
        }
        int GetServerPort()
        {
          return _server_port;
        }
        std::string GetServerIp()
        {
          return _server_ip;
        }
        std::string GetDownloadPrefix()
        {
          return _download_prefix;
        }
        std::string GetPackSuffix()
        {
          return _packfile_suffix;
        }
        std::string GetPackDir()
        {
          return _pack_dir;
        }
        std::string GetBackDir()
        {
          return _back_dir;
        }
        std::string GetBackupFile()
        {
          return _backup_file;
        }
  };
std::mutex Config::_mutex;
Config* Config::_instance = nullptr;
}
#endif
