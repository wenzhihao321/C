#ifndef _MY_DATA_
#define _MY_DATA_
#include "util1.hpp"
#include <sstream>
#include <unordered_map>
namespace cloud
{
    class DateManager
    {
    private:
        std::string _backup_file;//������Ϣ�ĳ־û��洢�ļ�
        //��д��
        std::unordered_map<std::string, std::string> _table;
    public:
        DateManager(const std::string& backup_file)
            :_backup_file(backup_file)
        {
            InitLoad();
        }

        bool Storage()
        {
            //1����ȡ���еı�����Ϣ
            std::stringstream ss;
            auto a = _table.begin();
            for (; a != _table.end(); ++a)
            {
                //2.��������Ϣ����ָ����������ʽ�洢
                ss << a->first << " " << a->second << std::endl;
            }
            //3.�־û��洢
            FileUtil fu(_backup_file);
            fu.Setcontent(ss.str());
            return true;
        }
        int split(const std::string& str, const std::string& sep, std::vector<std::string>* arry)
        {
            int count = 0;
            size_t pos = 0, idx = 0;
            while (1)
            {
                // abc bcd  def
                // find(Ҫ���ҵ��ַ�, �����￪ʼ���ҵ�ƫ����)
                pos = str.find(sep, idx);
                if (pos == std::string::npos)
                {
                    break;
                }
                if (pos == idx)
                {
                    idx = pos + sep.size();
                    continue;
                }
                // substr(��ȡ��ʼλ�ã�����)
                std::string tmp = str.substr(idx, pos - idx);
                arry->push_back(tmp);
                count++;
                idx = pos + sep.size();
            }
            if (idx < str.size())
            {
                arry->push_back(str.substr(idx));
                count++;
            }
            return count;
        }
        bool InitLoad()
        {
            //1�����ļ��ж�ȡ��������
            FileUtil fu(_backup_file);
            std::string body;
            fu.Getcontent(&body);
            //2���������ݽ�������ӵ�����
            std::vector<std::string> arry;
            split(body, "\n", &arry);
            for (auto& a : arry)
            {
                // b.txt b.txtx-34657-345636
                std::vector<std::string> tmp;
                split(a, " ", &tmp);
                if (tmp.size() != 2)
                {
                    continue;
                }
                _table[tmp[0]] = tmp[1];
            }
            return true;
        }

        //�����ļ�����
        bool Insert(const std::string& key, const std::string& val)
        {
            _table[key] = val;
            Storage();
            return true;
        }
        //�����޸ĺ������
        bool Updata(const std::string& key, const std::string& val)
        {
            _table[key] = val;
            Storage();
            return true;
        }
        bool GetOneKey(const std::string& key, std::string* val)
        {
            auto it = _table.find(key);
            if (it == _table.end())
            {
                return false;
            }
            *val = it->second;
            return true;
        }
    };
}
#endif

