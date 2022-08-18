#include "util.hpp"
#include "config.hpp"
#include "data.hpp"
#include "hot.hpp"
#include "service.hpp"
#include <thread>

void UtilTest(const std:: string &filename ){
  /*
    cloud::FileUtil fu( filename ) ;
    std:: cout << fu.FileSize( ) << std::endl;
    std:: cout < fu.LastMTime( ) << std::endl;
    std:: cout << fu.LastATime( ) << std::endl;
    std:: cout < fu.FileName( ) << std::endl;
  
    cloud::FileUtil fu(filename);
    std:: string body;
    fu.Getcontent(&body);

    cloud::FileUtil nfu("./hello.cpp");
    nfu.Setcontent(body);
  */ 
  /*  
    std:: string packname = filename + ".lz";
    cloud::FileUtil fu(filename);
    fu.Compress(packname);

    cloud::FileUtil nfu(packname);
    nfu.Uncompress("./hello.txt");
  */
    cloud::FileUtil fu(filename);
    fu.CreateDirectory();
    std::vector<std::string> arry;
    fu.ScanDirectory(&arry);
    for(auto &it : arry)
    {
      std::cout<<it<<std::endl;
    }
    return;
}
void Jsontest()
{
  const char*name = "姓名";
  int age = 21;
  float score[] = {99,100,99.9};
  Json::Value root;
  root["姓名"] = name;
  root["年龄"] = age;
  root["成绩"].append(score[0]);
  root["成绩"].append(score[1]);
  root["成绩"].append(score[2]);
  std::string str;
  cloud::jsonutil::Serialize(root,&str);
  std::cout<<str<<std::endl;

  Json::Value ret;
  cloud::jsonutil::Unserialize(str,&ret);
  std::cout<<ret["姓名"].asString()<<std::endl;
  std::cout<<ret["年龄"].asInt()<<std::endl;
  for(int i = 0; i < ret["成绩"].size();i++)
  {
    std::cout<<ret["成绩"][i].asFloat()<<std::endl;
  }
}
void Configtest()
{
  cloud::Config *config = cloud::Config::GetInstance();
  std::cout<<config->GetHotTime()<<std::endl;
  std::cout<<config->GetServerPort()<<std::endl;
  std::cout<<config->GetServerIp()<<std::endl;
  std::cout<<config->GetDownloadPrefix()<<std::endl;
  std::cout<<config->GetPackSuffix()<<std::endl;
  std::cout<<config->GetPackDir()<<std::endl;
  std::cout<<config->GetBackDir()<<std::endl;
  std::cout<<config->GetBackupFile()<<std::endl;
}
void datatest(const std::string &filename)
{
/* 
  cloud::DateManager dm;
  std::vector<cloud::BackupInfo> arry;
  dm.GetAll(&arry);
  for(auto &a : arry)
  {
    std:: cout << a.pack_flag << std:: endl;
    std:: cout << a.fsize<< std:: endl;                                                                                                              
    std:: cout << a.mtime<< std::endl;                                                                                                               
    std:: cout << a.atime<< std::endl;                                                                                                               
    std:: cout << a.real_path << std::endl;                                                                                                          
    std:: cout << a.pack_path << std::endl;                                                                                                          
    std:: cout << a.url << std::endl;                                                                                                                  
  }
*/
  
  cloud::BackupInfo info;
  info.NewBackupInfo(filename);
  cloud::DateManager dm;
  dm.Insert(info);
  
  cloud::BackupInfo tmp;
  dm.GetOneURL(info.url,&tmp);
  std:: cout << tmp.pack_flag << std:: endl;
  std:: cout << tmp.fsize<< std:: endl;
  std:: cout << tmp.mtime<< std::endl;
  std:: cout << tmp.atime<< std::endl;
  std:: cout << tmp.real_path << std::endl;
  std:: cout << tmp.pack_path << std::endl;
  std:: cout << tmp.url << std::endl;
  std:: cout << "-------插入-------"<< std::endl;

  tmp.pack_flag = true;
  dm.Updata(tmp);
  std:: cout << tmp.pack_flag << std:: endl;                                                                                                         
  std:: cout << tmp.fsize<< std:: endl;                                                                                                              
  std:: cout << tmp.mtime<< std::endl;                                                                                                               
  std:: cout << tmp.atime<< std::endl;                                                                                                               
  std:: cout << tmp.real_path << std::endl;                                                                                                          
  std:: cout << tmp.pack_path << std::endl;                                                                                                          
  std:: cout << tmp.url << std::endl;                                                                                                                
  std:: cout << "-------更新-------"<< std::endl;  

  std::vector<cloud::BackupInfo> arry;
  dm.GetAll(&arry);
  
  for(auto &a : arry)
  {
    std:: cout << a.pack_flag << std:: endl;
    std:: cout << a.fsize<< std:: endl;                                                                                                              
    std:: cout << a.mtime<< std::endl;                                                                                                               
    std:: cout << a.atime<< std::endl;                                                                                                               
    std:: cout << a.real_path << std::endl;                                                                                                          
    std:: cout << a.pack_path << std::endl;                                                                                                          
    std:: cout << a.url << std::endl;                                                                                                                  
  }
  dm.Storage();
  
}


cloud::DateManager *_data;
void HotTest()
{
  cloud::HotManager hot;
  hot.RunModule();
}
void Servicetest()
{
  cloud::Service srv;
  srv.RunModule();
}

int main(int argc,char*argv[])
{
  _data = new cloud::DateManager();
  //UtilTest(argv[1]);
  //Jsontest();
  //Configtest(); 
  //datatest(argv[1]);
  //HotTest();
  //Servicetest();
  std::thread thread_hot_manager(HotTest);
  std::thread thread_service(Servicetest);
  thread_hot_manager.join();
  thread_service.join();
  return 0;
}

