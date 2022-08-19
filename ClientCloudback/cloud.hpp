#ifndef __MY_CLOUD__
#define __MY_CLOUD__
#endif

#include "data1.hpp"
#include "httplib.h"
#include <windows.h>

namespace cloud
{
#define SERVER_ADDR "106.55.160.195"
#define SERVER_POST 9090
	class Backup {
	private:
		std::string _back_dir;
		DateManager* _data;
	public:
		Backup(const std::string& back_dir, const std::string& back_file)
			:_back_dir(back_dir)
		{
			_data = new DateManager(back_file);
		}

		std::string GetFileIdentifier(const std::string& filename)
		{
			//a.txt-fsize-mtime
			FileUtil fu(filename);
			std::stringstream ss;
			ss << fu.Getfilename() << "-" << fu.GetFilesize() << "-" << fu.LastModTime();
			return ss.str();
		}
		bool Upload(const std::string& filename)
		{
			//1����ȡ�ļ�����
			FileUtil fu(filename);
			std::string body;
			fu.Getcontent(&body);
			//2���http�ͻ����ϴ��ļ�����
			httplib::Client client(SERVER_ADDR, SERVER_POST);
			httplib::MultipartFormData item;
			item.content = body;
			item.filename = fu.Getfilename();
			item.name = "file";
			item.content_type = "application/octet-stream";
			httplib::MultipartFormDataItems items;
			items.push_back(item);
			auto res = client.Post("/upload", items);
			if (!res || res->status != 200)
			{
				return false;
			}
			return true;
		}
		bool IsNeedUpload(const std::string& filename)
		{
			//��Ҫ�ϴ����ļ����ж��������ļ��������ģ������������Ǳ��޸Ĺ�
			//�ļ��ǲ��������ģ���һ����û����ʷ������Ϣ
			//�����������Ǳ��޸Ĺ�������ʷ��Ϣ��������ʷ��Ψһ��ʶ�뵱ǰ���µ�Ψһ��ʶ��һ��
			std::string id;
			if (_data->GetOneKey(filename, &id) != false)
			{
				//����ʷ��Ϣ
				std::string newid = GetFileIdentifier(filename);
				if (newid == id)
				{
					return false;//����Ҫ���ϴ�-�ϴ��ϴ���û�б��޸Ĺ�
				}
			}
			//һ���ļ��Ƚϴ���������Ŀ��������Ŀ¼�£�������Ҫһ������
			//���ÿ�α����򶼻��жϱ�ʶ��һ����Ҫ�ϴ�һ����ʮG���ļ����ϴ��ϰٴ�
			//���Ӧ���ж�һ���ļ�һ��ʱ�䶼û�б��޸Ĺ��ˣ�������ϴ�
			FileUtil fu(filename);
			//3���Ӷ��Ѿ�û�б��޸Ĺ�
			if (time(nullptr) - fu.LastAccTime() < 3)
			{
				return false;
			}
			std::cout << filename << "-> need upload!\n";

			return true;
		}
		bool Runmodule()
		{
			while (1)
			{
				//1��������ȡָ���ļ����������ļ�
				FileUtil fu(_back_dir);
				std::vector<std::string> arry;
				fu.ScanDirectory(&arry);
				//2�������ж��ļ��Ƿ���Ҫ�ϴ�
				for (auto& a : arry)
				{
					if (IsNeedUpload(a) == false)
					{
						continue;
					}
					//3�������Ҫ�ϴ����ϴ��ļ�
					if (Upload(a) == true)
					{
						//�����ļ�����
						_data->Insert(a, GetFileIdentifier(a));
						std::cout << a << "-> upload success!\n";
					}
				}
				Sleep(1);
			}
		}
	};
}
