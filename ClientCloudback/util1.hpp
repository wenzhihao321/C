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
        //��ȡ�ļ����һ�η���ʱ��
        time_t LastAccTime()
        {
            struct stat st;   //�ļ�����
            //��ȡ�ļ�����
            if (stat(filename.c_str(), &st) < 0)
            {
                std::cout << "Get LastAccTime failed" << std::endl;
                return -1;
            }
            //�ɹ���ȡ
            return  st.st_atime;
        }
        //��ȡ�ļ����һ���޸�ʱ�� 
        time_t LastModTime()
        {
            struct stat st;   //�ļ�����
            //��ȡ�ļ�����
            if (stat(filename.c_str(), &st) < 0)
            {
                std::cout << "Get LastModTime failed" << std::endl;
                return -1;
            }
            //�ɹ���ȡ
            return  st.st_mtime;
        }
        std::string Getfilename()
        {
            size_t pos = filename.find_last_of("\\");//��ȡ���һ��'/'��λ��
            if (pos == std::string::npos)
            {
                //ʧ��
                return filename;
            }
            //����ֱ�ӵ���ϵͳ�ӿ�
            // return fs::path(filename).filename().string();
            return filename.substr(pos + 1);//��ȡposλ�ú���ַ�
        }
        size_t GetFilesize()
        {
            struct stat st;   //�ļ�����
            //��ȡ�ļ�����
            if (stat(filename.c_str(), &st) < 0)
            {
                std::cout << "Get filenamesize failed" << std::endl;
                return -1;
            }
            //�ɹ���ȡ
            return  st.st_size;
        }
        bool GetPosLen(std::string* body, size_t pos, size_t len)
        {
            size_t fsize = this->GetFilesize();
            //�жϸ���pos�Ƿ񳬳��ļ���С
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
            //�����ݶ��������ж϶����Ƿ�����
            if (ifs.good() == false)
            {
                std::cout << "get file content failed!" << std::endl;
                ifs.close();
                return false;
            }
            ifs.close();
            return true;
        }

        //��ȡ�ļ�ȫ������
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
        //�ļ��Ƿ����
        bool Exists()
        {
            return fs::exists(filename);
        }

        //����Ŀ¼
        bool CreateDirectory()
        {
            if (this->Exists())
            {
                return true;
            }
            //�����ھʹ���һ��Ŀ¼
            return fs::create_directories(filename);
        }

        //�鿴Ŀ¼
        bool ScanDirectory(std::vector<std::string>* arry)
        {
            this->CreateDirectory();
            //����Ŀ¼
            for (auto& p : fs::directory_iterator(filename))
            {
                if (fs::is_directory(p) == true)
                {
                    //�����Ŀ¼����������һ��Ŀ¼
                    continue;
                }
                //���ļ�����Ŀ¼  relative_path����·�����ļ���
                arry->push_back(fs::path(p).relative_path().string());
            }
            return  true;
        }
    };
}
#endif
