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
		printf("ͨѶ¼���������ܴ���\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", p->data[p->size].name);
		printf("���������䣺");
		scanf("%d", &(p->data[p->size].age));
		printf("�������Ա�");
		scanf("%s", p->data[p->size].sex);
		printf("������绰��");
		scanf("%s", p->data[p->size].tele);
		printf("������סַ��");
		scanf("%s", p->data[p->size].addr);
		p->size++;
		printf("���ӳɹ���\n");
	}
}
void showcontact(const struct contact* p)
{
	if (p->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����","����","�Ա�","�绰","סַ");
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
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	int ret=findname(p, name);
	if (ret == -1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < p->size-1; j++)
		{
			p->data[j] = p->data[j + 1];
		}
		p->size--;
		printf("ɾ���ɹ���\n");
	}
}
void searchcontact(const struct contact* p)
{
	char name[max_name];
	printf("������Ҫ�����˵�������");
	scanf("%s", name);
	int ret = findname(p, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("������Ҫ�޸��˵�������");
	scanf("%s", name);
	int ret = findname(p, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲����ڣ�\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", p->data[ret].name);
		printf("���������䣺");
		scanf("%d", &(p->data[ret].age));
		printf("�������Ա�");
		scanf("%s", p->data[ret].sex);
		printf("������绰��");
		scanf("%s", p->data[ret].tele);
		printf("������סַ��");
		scanf("%s", p->data[ret].addr);
		printf("�޸ĳɹ���\n");
	}
}
void sortcontact(struct contact* p)
{
	if (p->size == 0)
	{
		printf("ͨѶ¼û�п��������ϵ��\n");
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
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		for (i = 0; i < p->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				p->data[i].name,
				p->data[i].age,
				p->data[i].sex,
				p->data[i].tele,
				p->data[i].addr);
		}
		printf("����ɹ���");
	}
}