#pragma once
namespace milu
{
	//�����ַ��������飬������ɾ���
	//�ַ�������Ľ�β��'\0'
	//֧����ɾ���
	class string
	{
	public:
		typedef char* iterator;
		typedef char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		//���캯��
		//string(const char* str = "")
		//	:_str(new char[strlen(str)+1]) //+1��Ϊ'\0'���ٵ�
		//{
		//	strcpy(_str, str);
		//}
		string(const char* str = "")
		{
			
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		//����
		//at���ú�operator[]���ƣ�Խ�����쳣
		//ֻ��
		const char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}

		//�ɶ���д
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}

		//���ռ䣬��չcapacity
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strncpy(tmp, _str, _size + 1);//����'\0'
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		//���ռ�+��ʼ������չcapacity ���ҳ�ʼ���ռ䣬sizeҲҪ��
		//1��n<_szie
		//2��_size<n<_capacity
		//3��n>_capacity
		void resize(size_t n,char val='\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = val;
				}
				_str[n] = '\0';
				_size = n;
			}
			
		}

		string& insert(size_t pop,char ch)
		{
			assert(pop <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			//����size_t��-1���ɺܴ��ֵ
			/*size_t end = _size;
			while (end >= pop)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//ǿ��ת��һ�¾Ͳ����������,���Ƽ�
			/*int end = _size;
			while (end >= (int)pop)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			//���߻�������ָ��
			/*size_t end = _size + 1;
			while (end > pop)
			{
				_str[end] = _str[end - 1];
				--end;
			}*/

			char* end = _str + _size;
			while (end >= _str + pop)
			{
				*(end + 1) = *end;
				end--;
			}
			_str[pop] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pop, const char*str)
		{
			assert(pop <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			//�ƶ�����
			char* end = _str + _size;
			while (end >= _str + pop)
			{
				*(end + len) = *end;
				end--;
			}
			strncpy(_str + pop, str, len);
			_size = _size + len;
			return *this;
		}
		//β��һ���ַ�
		void push_back(char ch)
		{
			/*if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			++_size;*/

			insert(_size, ch);
		}

		//�����ַ���
		void append(const char* str)
		{
			/*size_t len = _size + strlen(str);
			if (len < _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;*/

			insert(_size, str);
		}

		//s1+='x'
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		//s1+="xxxx"
		string& operator+=(const char*ch)
		{
			append(ch);
			return *this;
		}

		//1��ʣ����ַ�����С��Ҫɾ�ĳ��� ������ȫ��ɾ�꣩
		//2��ʣ����ַ����ȴ���Ҫɾ�ĳ���
		string&erase(size_t pos,size_t len = npos)
		{
			assert(pos < _size);
			size_t leftlen = _size - pos;
			if (len > leftlen)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char*str, size_t pos = 0)
		{
			assert(pos < _size);

			const char*ret = strstr(_str + pos, str);
			if (ret)
			{
				return ret - _str;
			}
			else
			{
				return npos;
			}
		}

		size_t size()const
		{
			return _size;
		}

		////��ͳд��
		////s2(s1)
		//string(const string& s)
		//	:_str(new char[strlen(s._str)+1])
		//{
		//	strcpy(_str, s._str);
		//}
		////s2=s1
		//string& operator=(const string& s)
		//{
		//	//��ֹ���Ҹ�ֵ
		//	if (this != &s)
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}

		
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		//�ִ�д��
		//s2(s1)
		string(const string& s)
			:_str(nullptr) //s2._str��û��ʼ���������ֵ����������󣬻ص����������������
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			//swap(_size, tmp._size);
			//swap(_capacity, tmp._capacity);
			//swap(_str, tmp._str);
			swap(tmp);
		}
		//�е���ޣ����Լ����Լ���ֵʱ���ܽ��
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}


		//��ȡ�׵�ַ
		const char* c_str()const
		{
			return _str;
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};
	const size_t string::npos = -1;

	inline bool operator < (const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	inline bool operator == (const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	inline bool operator <= (const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	inline bool operator > (const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	inline bool operator >= (const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	inline bool operator != (const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto e : s)
		{
			out << e;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	istream& getline(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}

	void test_string1()
	{
		string s1("hello xiaohui");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("hello hui");
		s1 = s3;
		cout << s1.c_str() << endl;
		
		//C++98��C++11��������ֵ���õ��ƶ����壬�Ż���swap����ģ��
		//swap(s1, s2);  Ч�ʵ���  �������
		//s2.swap(s1);   Ч�ʸ�    ֱ�ӽ���
	}
	void test_string2()
	{
		string s1("hello xiaohui");
		s1[0] = 'x';
		cout << s1[1] << endl;
		cout << s1.c_str() << endl;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}
	void test_string3()
	{
		string s1("hello xiaohui");
		string::iterator it=s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		//�����������棬����ԭ��ܼ򵥣������Χfor�ᱻ�������滻�ɵ�������ʽ
		//Ҳ����˵��Χfor���е�����֧�ֵ�
		for (auto e: s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_string4()
	{
		string s1("hello xiaohui");
		s1 += 'w';
		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;

		s1 += "oxihuanni";
		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;

	}
	void test_string5()
	{
		string s1("hello");
		s1 += '!';
		s1.resize(8,'x');
		cout << s1.c_str() << endl;
		s1.resize(15, 'y');
		cout << s1.c_str() << endl;
		s1.resize(3);
		cout << s1.c_str() << endl;
	}
	void test_string6()
	{
		string s1("hello");
		s1.insert(0,'x');
		cout << s1.c_str() << endl;
		s1.insert(0, "!!!!!");
		cout << s1.c_str() << endl;
		s1 += 'a';
		s1 += "aaa";
		cout << s1.c_str() << endl;
		s1.erase(6, 4);
		cout << s1.c_str() << endl;
		s1.erase(2);
		cout << s1.c_str() << endl;
	}
	void test_string7()
	{
		string s1("hello world");
		//cout << s1.find('w',7) << endl;
		//cout << s1.find("d") << endl;

		//cout << s1.find("wod") << endl;
		//cout << s1.find("wor") << endl;

		string s2("hello world");
		//cin >>s2;
		////�ж��ٸ���������ٸ�
		//cout << s2 << endl;

		//����'\0'��ֹ
		//cout << s2.c_str() << endl;
		string line;
		getline(cin, line);
		cout << line << endl;
	}
}
