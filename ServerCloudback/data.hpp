#ifndef _MY_DATA_
#define _MY_DATA_
#include <unordered_map>
#include <pthread.h>
#include <vector>
#include "util.hpp"
#include "config.hpp"

namespace cloud 
{
  typedef struct BackupInfo{
        bool pack_flag;
        size_t fsize;
        time_t atime;
        time_t mtime;
        std::string real_path;
        std::string pack_path;
        std::string url;
        bool NewBackupInfo(const std::string &realpath)
        {
          FileUtil fu(realpath);
          if(fu.Exists() == false)
          {
            std::cout<<"new backupInfo failed!"<<std::endl;
            return false;
          }
          Config *config = Config::GetInstance();
          std::string downloadprefix = config->GetDownloadPrefix();
          std::string packfilesuffix = config->GetPackSuffix();
          std::string packdir = config->GetPackDir();
          this->pack_flag = false;
          this->fsize = fu.GetFilesize();
          this->atime = fu.LastAccTime();
          this->mtime = fu.LastModTime();
          this->real_path = realpath;
          // ./packdir/a.txt  -> ./packdir/a.txt.lz 
          this->pack_path = packdir + fu.Getfilename() + packfilesuffix;
          // /download/a.txt  
          this->url = downloadprefix + fu.Getfilename();
          return true;
        }
  }BackupInfo;
  class DateManager
  {
    private:
      std::string _backup_file;
      //读写锁
      pthread_rwlock_t _rwlock;
      std::unordered_map<std::string,BackupInfo> _table;
    public:
      DateManager()
      {
        _backup_file = Config::GetInstance()->GetBackupFile();
        pthread_rwlock_init(&_rwlock,nullptr);//初始化读写锁
        InitLoad();
      }
      ~DateManager()
      {
        pthread_rwlock_destroy(&_rwlock);//销毁读写锁
      }
      //插入文件数据
      bool Insert(const BackupInfo &info)
      {
        pthread_rwlock_wrlock(&_rwlock);
        _table[info.url] = info;
        pthread_rwlock_unlock(&_rwlock);
        Storage();
        return true;
      }
      //更新修改后的数据
      bool Updata(const BackupInfo &info)
      {
        pthread_rwlock_wrlock(&_rwlock);                                            
        _table[info.url] = info;                                                    
        pthread_rwlock_unlock(&_rwlock);
        Storage();                                            
        return true;
      }
      bool GetOneURL(const std::string &url,BackupInfo *info)
      {
        pthread_rwlock_wrlock(&_rwlock);             
        auto it = _table.find(url);
        if(it == _table.end())
        {
          pthread_rwlock_unlock(&_rwlock);
          return false;
        }
        *info = it->second;
        pthread_rwlock_unlock(&_rwlock);                                            
        return true;
      }
      bool GetOneRealPath(const std::string &realpath,BackupInfo *info)
      {
        pthread_rwlock_wrlock(&_rwlock);
        auto it = _table.begin();
        for(;it != _table.end();++it)
        {
          if(it->second.real_path == realpath)
          {
            *info = it->second;
            pthread_rwlock_unlock(&_rwlock);
            return true;
          }
        }
        pthread_rwlock_unlock(&_rwlock);
        return false;
      }
      bool GetAll(std::vector<BackupInfo> *arry)
      {
        pthread_rwlock_wrlock(&_rwlock);                                              
        auto it = _table.begin();                                                     
        for(;it != _table.end();++it)                                                 
        {
          arry->push_back(it->second);
        }                                                                             
        pthread_rwlock_unlock(&_rwlock);
        return true;
      }
      bool Storage()
      {
        //1、获取数据
        std::vector<BackupInfo> arry;
        this->GetAll(&arry);
        //2、添加到Json::Value
        Json::Value root;
        for(int i= 0; i < arry.size(); ++i)
        {
          Json::Value tmp;
          tmp["pack_flag"] = arry[i].pack_flag;
          tmp["fsize"] = (Json::Int64)arry[i].fsize;
          tmp["atime"] = (Json::Int64)arry[i].atime;
          tmp["mtime"] = (Json::Int64)arry[i].mtime;
          tmp["real_path"] = arry[i].real_path;
          tmp["pack_path"] = arry[i].pack_path;
          tmp["url"] = arry[i].url;
          root.append(tmp);//添加数组元素
        }
        //3、将Json::Value序列化
        std::string body;
        jsonutil::Serialize(root,&body);
        //4、写入文件
        FileUtil fu(_backup_file);
        fu.Setcontent(body);
        return true;
      }
      bool InitLoad()
      {
        //1、将数据文件中的数据读取出来
        FileUtil fu(_backup_file);
        if(fu.Exists() == false)
        {
          return true;
        }
        std::string body;
        fu.Getcontent(&body);
        
        //2、反序列化
        Json::Value root;
        jsonutil::Unserialize(body,&root);
        
        //3、将反序列化数据添加到table
        for(int i = 0;i < root.size(); i++)
        {
          BackupInfo tmp;
          tmp.pack_flag = root[i]["pack_flag"].asBool();
          tmp.fsize = root[i]["fsize"].asInt();
          tmp.atime = root[i]["atime"].asInt();
          tmp.mtime = root[i]["mtime"].asInt();
          tmp.real_path = root[i]["real_path"].asString();
          tmp.pack_path = root[i]["pack_path"].asString();
          tmp.url = root[i]["url"].asString();
          Insert(tmp);
        }
        return true;
      }
  };
}
#endif
