#include"contact.h"
void Initcontact(struct contact* p)
{
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;
}

void addcontact(struct contact* p)
{
	if (p->size == max)
	{
		printf("通讯录已满，不能存入\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", p->data[p->size].name);
		printf("请输入年龄：");
		scanf("%d", &(p->data[p->size].age));
		printf("请输入性别：");
		scanf("%s", p->data[p->size].sex);
		printf("请输入电话：");
		scanf("%s", p->data[p->size].tele);
		printf("请输入住址：");
		scanf("%s", p->data[p->size].addr);
		p->size++;
		printf("添加成功！\n");
	}
}
void showcontact(const struct contact* p)
{
	if (p->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字","年龄","性别","电话","住址");
		for (i = 0; i < p->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", 
				p->data[i].name,
				p->data[i].age,
				p->data[i].sex,
				p->data[i].tele,
				p->data[i].addr );
		}
	}
}
static int findname(const struct contact*p,char name[max_name])
{
	int i = 0;
	for (i=0;i<p->size;i++)
	{
		if (strcmp(p->data[i].name , name)==0)
		{
			return i;
		}
	}
	return -1;
}
void delcontact(struct contact* p)
{
	char name[max_name];
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	int ret=findname(p, name);
	if (ret == -1)
	{
		printf("要删除的联系人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < p->size-1; j++)
		{
			p->data[j] = p->data[j + 1];
		}
		p->size--;
		printf("删除成功！\n");
	}
}
void searchcontact(const struct contact* p)
{
	char name[max_name];
	printf("请输入要查找人的姓名：");
	scanf("%s", name);
	int ret = findname(p, name);
	if (ret == -1)
	{
		printf("要查找的联系人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			p->data[ret].name,
			p->data[ret].age,
			p->data[ret].sex,
			p->data[ret].tele,
			p->data[ret].addr);
	}
}
void moidfycontact(struct contact* p)
{
	char name[max_name];
	printf("请输入要修改人的姓名：");
	scanf("%s", name);
	int ret = findname(p, name);
	if (ret == -1)
	{
		printf("要修改的人不存在！\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", p->data[ret].name);
		printf("请输入年龄：");
		scanf("%d", &(p->data[ret].age));
		printf("请输入性别：");
		scanf("%s", p->data[ret].sex);
		printf("请输入电话：");
		scanf("%s", p->data[ret].tele);
		printf("请输入住址：");
		scanf("%s", p->data[ret].addr);
		printf("修改成功！\n");
	}
}
void sortcontact(struct contact* p)
{
	if (p->size == 0)
	{
		printf("通讯录没有可排序的联系人\n");
	}
	else
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < p->size-1; i++)
		{
			for (j = 0; j < p->size - 1-i; j++)
			{
				if (p->data[j].age > p->data[j + 1].age)
				{
					struct peoinfo tmp = p->data[j];
					p->data[j] = p->data[j + 1];
					p->data[j + 1]= tmp;
				}
			}
		}
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		for (i = 0; i < p->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				p->data[i].name,
				p->data[i].age,
				p->data[i].sex,
				p->data[i].tele,
				p->data[i].addr);
		}
		printf("排序成功！");
	}
}
