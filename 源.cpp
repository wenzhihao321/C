#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include"game.h"
using namespace std;
//ɨ����Ϸ
void menu()
{
	cout << "*****************************************" << endl;
	cout << "*********       1.  play       **********" << endl;
	cout << "*********       0.  exit       **********" << endl;
	cout << "*****************************************" << endl;
}
void game()
{
	//1.���ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.�ų��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS,'*');
	//��ӡ����
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	Displayboard(mine, ROW, COL);
	//ɨ��
	FindMine(mine,show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		cout << "��ѡ��:";
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "�˳���Ϸ" << endl;
			break;
		default:
			cout << "ѡ��������������룡" << endl;
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}

////������������Ϸ
//void menu()
//{
//	cout << "*******************************" << endl;
//	cout << "*****   1.play   0.exit   *****" << endl;
//	cout << "*******************************" << endl;
//}
//void game()
//{
//	char ret = 0;
//	//����-����߳���������Ϣ
//	char board[ROW][COL] = { 0 };
//	//��ʼ������
//	InitBoard(board, ROW, COL);
//	//��ӡ����
//	DisplayBoard(board,ROW,COL);
//	while (1)
//	{
//		//�������
//		PlayMove(board, ROW, COL);
//		DisplayBoard(board, ROW, COL);
//		ret = IsWin(board,ROW,COL);
//		if (ret != 'C')
//		{
//			break;
//		}
//		//��������
//		ComputerMove(board, ROW, COL);
//		DisplayBoard(board, ROW, COL);
//		ret = IsWin(board, ROW, COL);
//		if (ret != 'C')
//		{
//			break;
//		}
//	}
//	if(ret=='*')
//	{
//		cout << "���Ӯ" << endl;
//	}
//	else if (ret == '#')
//	{
//		cout << "����Ӯ" << endl;
//	}
//	else
//	{
//		cout << "ƽ��" << endl;
//	}
//}
//void test()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		cout << "��ѡ��";
//		cin >> input;
//		switch (input)
//		{
//		case 1:
//			cout << "������" << endl;
//			game();
//			break;
//		case 0:
//			cout << "�˳���Ϸ" << endl;
//			break;
//		default:
//			cout << "�������,������ѡ��" << endl;
//			break;
//		}
//	} while (input);
//}
//int main()
//{
//	test();
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3 };//����ȫ��ʼ����ʣ�µ�Ԫ��Ĭ�ϳ�ʼ��Ϊ0
//	char arr2[5] = {'a','b'};
//	return 0;
//}
////��ŵ������
////������̨��
////�ݹ��������
////��ѭ������������쳲�������
////쳲�������
////1 1 2 3 5 8 13 21 34 55....ǰ��������� 
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	cin >> n;
//	ret = Fib(n);
//	cout << ret << endl;
//	return 0;
//}
////�ǵݹ�n�Ľ׳�
//int fac1(int k)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= k; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
////�ݹ�n�Ľ׳�
//int fac2(int k)
//{
//	if (k <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return k * fac2(k - 1);
//	}
//}
//int main()
//{
//	int k = 1;
//	int ret = 0;
//	cin >> k;
//	ret = fac1(k);
//	cout << ret<<endl;
//	ret = fac2(k);
//	cout << ret;
//	return 0;
//}

//û����ʱ���������С
//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen(arr+1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "wenzhihao";
//	int ret = my_strlen(arr);
//	cout << "��С" << ret << endl;
//	return 0;
//}

//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "wenzhihao";
//	int ret=my_strlen(arr);
//	cout <<"��СΪ"<< ret << endl;
//	return 0;
//}

////�����ݹ�
//void print(int k)
//{
//	if (k > 9)
//	{
//		print(k / 10);
//	}
//	cout << k % 10 << " " ;
//}
//int main()
//{
//	unsigned int num = 0;
//	cin >> num;
//	print(num);
//	return 0;
//}

////��һ�κ�����һ
//void fun(int*k)
//{
//	(*k)++;
//}
//int main()
//{
//	int num = 0;
//	int i = 0;
//	for (i = 0; i <10; i++)
//	{
//		fun(&num);
//		cout << num << endl;
//	}
//	return 0;
//}

////�ú����Ҹ���ֵ
//int binary_search(int arr[], int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid]<k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid]>k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//		int sz = sizeof(arr) / sizeof(arr[0]);
//		int k = 7;
//		int ret = binary_search(arr, k, sz);
//		if (-1 == ret)
//		{
//			cout << "û�ҵ�";
//		}
//		else
//		{
//			cout << "�ҵ���,�±���"<<ret<<endl;
//		}
//		return 0;
//}

////дһ���������Ƿ�Ϊ����
//int is_leap_year(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//	
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year) == 1)
//		{
//			cout << year <<"  ";
//		}		
//	}
//	return 0;
//}

//�ж��Ƿ�Ϊ����
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j < n; j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//		return 1;
//	}
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			cout << i <<"������" << endl;
//		}
//	}
//	return 0;
//}

////��������ֵ
//void Swap(int* pa, int* pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 20;
//	int b = 40;
//	cout << "a=" << a << "b=" << b << endl;
//	Swap(&a,&b);
//	cout << "a=" << a << "b=" << b << endl;
//	return 0;
//}

//�Ƚ��������Ĵ�С
//int get_max(int x, int y)
//{
//	if (x > y)
//	{
//		return x;
//	}
//	else
//	{
//		return y;
//	}
//}
//int main()
//{
//	int a = 10;
//	int b = 90;
//	int max=get_max(a,b);
//	cout << max;
//	return 0;
//}

//��������Ϸ
//void mune()
//{
//	printf("*****************************************\n");
//	printf("******    1. play     0.exit      *******\n");
//	printf("*****************************************\n");
//
//}
//void game()
//{
//	//1.���������
//	int ret = 0;
//	int guess = 0;
//	ret=rand()%100+1;//����������ĺ���
//	//2.������
//	cout<<"���һ����"<<endl;
//	while (1)
//	{
//		//20 
//		cin>>guess;
//		if (guess > ret)
//		{
//			cout << "�´���" << endl;
//		}
//		else if (guess < ret)
//		{
//			cout << "��С��"<<endl ;
//		}
//		else
//		{
//			cout << "������¶���" << endl;
//			break;
//		}
//	}
//}
////RAND_MAX��0��32767֮��
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(nullptr));
//	do
//	{
//		mune();
//		printf("��ѡ��");
//		cin >> input;
//		switch (input)
//		{
//		case 1:
//				game();
//				break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//�۰����
//int main()
//{
//	int arr[] = { 2,4,6,8,12,32,45,67,87 };
//	int k = 9;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	
//	while(left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ����ˣ�%d\n", arr[mid]);
//			break;
//		}
//	}
//	if (right < left)
//	{
//		cout << "δ�ҵ�" << endl;
//
//	}
//	return 0;
//}

//��ӡ�˷��ھ���
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//ʮ���������ֵ
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i =1; i < sz; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d\n", max);
//	return 0;
//}

//1/1-1/2+1/3-1/4...+1/99-1/100�ĺ�
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag * 1. / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

//��1��100�г����˶��ٸ�����9
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i % 9 == 10)
//		{
//			count++;
//		}
//	}
//	cout << "��1��100�г�����" << count << "������9";
//	return 0;
//}
//���1��100֮�䣬3�ı���
//void shuchu()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			cout << i << " ";
//		}
//	}
//}
//int main()
//{
//	shuchu();
//	return 0;
//}

//�Ӵ�С���
//void bijiao()
//{
//	int a,b,c;
//	cin >> a >> b >> c;//4 5 6 
//	if (a < b)
//	{
//		int tem = a;
//		a = b;
//		b = tem;
//	}
//	if (a < c)
//	{
//		int tem = a;
//		a = c;
//		c = tem;
//	}
//	if (b < c)
//	{
//		int tem = b;
//		b = c;
//		c = tem;
//	}
//	cout << a << b << c;
//}
//int main()
//{
//	bijiao();
//	return 0;
//}


//void _if3num(int a,int b, int c)
//{
//	int tempmax;
//	int tempin;
//	int tempmin;
//	if (a < b)
//	{
//		if (b < c)
//		{	`
//			tempmax = c;
//			tempin = b;
//			tempmin = a;
//		}
//		else if(c<a)
//		{
//			tempmax = b;
//			tempin = a;
//			tempmin = c;
//		}
//		else
//		{
//			tempmax = b;
//			tempin = c;
//			tempmin = a;
//		}
//	}
//	else//a>b
//	{
//		if (a < c)
//		{
//			tempmax = c;
//			tempin = a;
//			tempmin = b;
//		}
//		else if (c < b)
//		{
//			tempmax = a;
//			tempin = b;
//			tempmin = c;
//		}
//		else
//		{
//			tempmax = a;
//			tempin = c;
//			tempmin = b;
//		}
//	}
//	cout << tempmax << tempin << tempmin;
//}
//int main()
//{
//	_if3num(1, 5, 8);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("�������룺");
//		scanf("%s", password);
//		if (strcmp(password, "123456")==0)//==���������Ƚ������ַ����Ƿ���ȣ�Ӧ��ʹ��һ���⺯��-strcmp
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//	}
//	if (i == 3)
//	{
//		printf("��������������˳�����\n");
//	}
//	return 0;
//}



//int main()
//{
//	char arr1[] = "welcome to china!!!!!!";
//	char arr2[] = "**********************";
//	int left = 0;
//	//int right=sizeof(arr1)/sizeof(sizeof(arr1[0])-2;
//	//""�������\0
//	//{}�����治����\0
//	//sizeof���ֻ��\0�����ȥ����strlen�������\0
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");//ִ��ϵͳ�����һ������-cls-�����Ļ
//		left++;
//		right--;
//	}
//	return 0;
//}


//�۰�����㷨
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while(left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ����ˣ��±��ǣ�%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}

////дһ�����룬��arr���飨�������飩���ҵ�7
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i <= 10; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("�ҵ������ˣ��±��ǣ�%d\n", i);
//			break;
//		}
//		
//	}
//	if (i == sz)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//		int n = 0;
//		int ret = 1;
//		int sum = 0;
//		for (n = 1; n <= 3; n++)//���������Ż�
//		{
//			ret = ret * n;
//			sum = sum + ret;
//		}
//		printf("sum=%d\n",sum);
//	return 0;
//}


//1��+2��+3����������+n��
//int main()
//{
//	int i = 0;
//		int n = 0;
//		
//		int sum = 0;
//		for (n = 1; n <= 3; n++)
//		{
//			int ret = 1;
//			for (i = 1; i <= n; i++)
//			{
//				ret = ret * i;
//			}
//			sum = sum + ret;
//		}
//		
//		printf("sum=%d\n",sum);
//	return 0;
//}

//���n�Ľ׳�
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret=ret*i;
//		
//	}
//	printf("ret=%d\n", ret);
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)//����ѭ��0�Σ�0Ϊ��ѭ������ȥ
//	{
//		k++;
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	int ret = 0;
//	char password[20] = { 0 };
//	printf("���������룺");
//	scanf("%s", password);
//	while ((ch=getchar()) != '\n')
//	{
//		;
//	}
//	printf("��ȷ�ϣ�Y/N��");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//}

//int main()
//{
//	int day=0;
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekday\n");
//		break;
//	}
//	return 0;
//}


//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:m++;
//	case 2:n++;
//	case 3:
//		switch (n)
//		{
//		case 1:n++;
//		case 2:m++;
//			n++;
//			break;
//		}
//	case 4:m++;
//		break;
//	default:
//		break;
//	}
//	printf("m=%d,n=%d\n", m, n);
//	return 0;
//}



//int main()
//{
//	int i =1;
//	while (i <= 100)
//	{
//		if (i % 2 == 1)
//			printf("%d ",i);
//		i++;
//	}


//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//	}
//	else
//		printf("haha\n");
//}


//int main()
//{ 
//	typedef unsigned int u_int;
//	unsigned int num1 = -1;
//	u_int num2 = -2;
//	printf("%d%d\n", num1,num2);
//	return 0;
//}


//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("��ע���ˣ���ĵ��Խ���һ�����ڹػ���������룺��������ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	while (1)
//	{
//		printf("��ע���ˣ���ĵ��Խ���һ�����ڹػ���������룺����С��������ȡ���ػ�\n");
//		cout<< "�����룺";
//		scanf("%s", input);
//		if (strcmp(input, "����С����") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}