#define _CRT_SECURE_NO_WARNINGS 1
#include"RBTree.h"
#include"map.h"
#include"set.h"
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<string>

using  namespace std;


//int main()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	t.InOrder();
//	cout << t.CheckBlance() << endl;
//	return 0;
//}

int main()
{
	wzh::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(6, 6));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(7, 7));
	
	wzh::map<int, int>::iterator mit = m.begin();
	while (mit != m.end())
	{
		cout << (*mit).first << ":" << (*mit).second << endl;
		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;

	wzh::map<int, int>::reverse_iterator rmit = m.rbegin();
	while (rmit != m.rend())
	{
		cout << (*rmit).first << ":" << (*rmit).second << endl;
		cout << rmit->first << ":" << rmit->second << endl;
		++rmit;
	}
	cout << endl;


	wzh::map<string, string> dict;
	dict["sort"];
	dict["dreamboat"] = "梦中人";
	dict["dreamboat"] = "梦中人，爱人";
	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	/*wzh::set<int, int> s;
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(13);
	s.insert(0);
	s.insert(15);
	s.insert(18);

	wzh::set<int, int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;*/
	return 0; 
}