#ifndef _MY_HOT_
#define _MY_HOT_ 
#include <unistd.h>
#include "data.hpp"
extern cloud::DateManager *_data;


namespace cloud
{
  class HotManager
  {
    private:
      std::string _pack_dir;
      std::string _back_dir;
      std::string _pack_suffix;
      int _hot_time;
    private:
      //非热点文件--返回真，热点文件--返回假
      bool HotJudge(std::string &filename)
      {
        FileUtil fu(filename);
        time_t lastatime = fu.LastAccTime();
        time_t curtime = time(nullptr);
        if(curtime - lastatime > _hot_time)
        {
          return true;
        }
        return false;
      }
    public:
      HotManager()
      {
        Config *config = Config::GetInstance();
        _pack_dir = config->GetPackDir();
        _back_dir = config->GetBackDir();
        _pack_suffix = config->GetPackSuffix();
        _hot_time = config->GetHotTime();
        FileUtil fu1(_pack_dir);
        FileUtil fu2(_back_dir);
        fu1.CreateDirectory();
        fu2.CreateDirectory();
      }

      bool RunModule()
      {
        while(1)
        {
          //1.遍历文件备份目录,获取所有文件名
          FileUtil fu(_back_dir);
          std::vector<std::string> arry;
          fu.ScanDirectory(&arry);
          //2.遍历判断文件是否为非热点文件
          for(auto &a :arry)
          {
            if(HotJudge(a) == false)
            {
              //热点文件则不需要特别处理
              continue;
            }
            //3.获取备份文件信息
            BackupInfo info;
            if(_data->GetOneRealPath(a,&info) == false)
            {
              //现在有一个文件存在，但是没有备份信息
              info.NewBackupInfo(a);//设置一个新的备份信息
            }
            //非热点文件进行压缩
            FileUtil tmp(a);
            tmp.Compress(info.pack_path);
            //4.删除源文件，修改备份信息
            tmp.ReMove();
            info.pack_flag = true;
            _data->Updata(info);
          }
          usleep(1000);//避免空目录循环遍历，消耗cpu资源过高
        }
        return true;
      }
  };
}




#endif
