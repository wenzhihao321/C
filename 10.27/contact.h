#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define max 1000

#define max_name 20
#define max_sex 5
#define max_tele 12
#define max_addr 30
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};
struct peoinfo
{
	char name[max_name];
	int age;
	char sex[max_sex];
	char tele[max_tele];
	char addr[max_addr];
};
struct contact
{
	int size;//记录当前已有的元素个数
	struct peoinfo data[max];//存放一千个元素 
};
void Initcontact(struct contact* p);
void addcontact(struct contact* p);
void showcontact(const struct contact*p);
void delcontact(struct contact*p);
void searchcontact(const struct contact*p);
void moidfycontact(struct contact*p);
void sortcontact(struct contact*p);