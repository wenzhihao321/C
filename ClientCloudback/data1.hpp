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
        std::string _backup_file;//备份信息的持久化存储文件
        //读写锁
        std::unordered_map<std::string, std::string> _table;
    public:
        DateManager(const std::string& backup_file)
            :_backup_file(backup_file)
        {
            InitLoad();
        }

        bool Storage()
        {
            //1、获取所有的备份信息
            std::stringstream ss;
            auto a = _table.begin();
            for (; a != _table.end(); ++a)
            {
                //2.将所有信息进行指定持续化格式存储
                ss << a->first << " " << a->second << std::endl;
            }
            //3.持久化存储
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
                // find(要查找的字符, 从哪里开始查找的偏移量)
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
                // substr(截取起始位置，长度)
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
            //1、从文件中读取所有数据
            FileUtil fu(_backup_file);
            std::string body;
            fu.Getcontent(&body);
            //2、进行数据解析，添加到表中
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

        //插入文件数据
        bool Insert(const std::string& key, const std::string& val)
        {
            _table[key] = val;
            Storage();
            return true;
        }
        //更新修改后的数据
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

