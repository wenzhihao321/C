#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
const char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cur = p1;
	if (*p2 == '\0')
	{
		return (char*)p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = p2;
		while (*s1  && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;//找到子串
		}
		if (*s1 == '\0')
		{
			return NULL;//找到子串
		}
		cur++;
	}
	return NULL;//找不到子串
}
int main()
{
	//strncmp-字符串比较
	const char* p1 = "maxiaohuiwoxihuanni";
	const char* p2 = "xiaohui";
	//int ret=strcmp(p1,p2);
	const char* ret = my_strstr(p1, p2);
	//int ret = strncmp(p1, p2, 4);
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n",ret);
	}
	return 0;
}