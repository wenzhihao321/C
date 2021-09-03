#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include"game.h"
using namespace std;
//扫雷游戏
void menu()
{
	cout << "*****************************************" << endl;
	cout << "*********       1.  play       **********" << endl;
	cout << "*********       0.  exit       **********" << endl;
	cout << "*****************************************" << endl;
}
void game()
{
	//1.布置好雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.排除雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS,'*');
	//打印棋盘
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	Displayboard(mine, ROW, COL);
	//扫雷
	FindMine(mine,show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		cout << "请选择:";
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "退出游戏" << endl;
			break;
		default:
			cout << "选择错误，请重新输入！" << endl;
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}

////测试三子棋游戏
//void menu()
//{
//	cout << "*******************************" << endl;
//	cout << "*****   1.play   0.exit   *****" << endl;
//	cout << "*******************************" << endl;
//}
//void game()
//{
//	char ret = 0;
//	//数组-存放走出的棋盘信息
//	char board[ROW][COL] = { 0 };
//	//初始化棋盘
//	InitBoard(board, ROW, COL);
//	//打印棋盘
//	DisplayBoard(board,ROW,COL);
//	while (1)
//	{
//		//玩家下棋
//		PlayMove(board, ROW, COL);
//		DisplayBoard(board, ROW, COL);
//		ret = IsWin(board,ROW,COL);
//		if (ret != 'C')
//		{
//			break;
//		}
//		//电脑下棋
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
//		cout << "玩家赢" << endl;
//	}
//	else if (ret == '#')
//	{
//		cout << "电脑赢" << endl;
//	}
//	else
//	{
//		cout << "平局" << endl;
//	}
//}
//void test()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		cout << "请选择：";
//		cin >> input;
//		switch (input)
//		{
//		case 1:
//			cout << "三子棋" << endl;
//			game();
//			break;
//		case 0:
//			cout << "退出游戏" << endl;
//			break;
//		default:
//			cout << "输入错误,请重新选择" << endl;
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
//	int arr[10] = { 1,2,3 };//不完全初始化，剩下的元素默认初始化为0
//	char arr2[5] = {'a','b'};
//	return 0;
//}
////汉诺塔问题
////青蛙跳台阶
////递归会出现溢出
////用循环（迭代）求斐波那契数
////斐波那契数
////1 1 2 3 5 8 13 21 34 55....前两个数相加 
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
////非递归n的阶乘
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
////递归n的阶乘
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

//没有临时变量的求大小
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
//	cout << "大小" << ret << endl;
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
//	cout <<"大小为"<< ret << endl;
//	return 0;
//}

////函数递归
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

////用一次函数加一
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

////用函数找给定值
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
//			cout << "没找到";
//		}
//		else
//		{
//			cout << "找到了,下标是"<<ret<<endl;
//		}
//		return 0;
//}

////写一个函数找是否为闰年
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

//判断是否为素数
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
//			cout << i <<"是素数" << endl;
//		}
//	}
//	return 0;
//}

////交换两个值
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

//比较两个数的大小
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

//猜数字游戏
//void mune()
//{
//	printf("*****************************************\n");
//	printf("******    1. play     0.exit      *******\n");
//	printf("*****************************************\n");
//
//}
//void game()
//{
//	//1.生成随机数
//	int ret = 0;
//	int guess = 0;
//	ret=rand()%100+1;//生成随机数的函数
//	//2.猜数字
//	cout<<"请猜一个数"<<endl;
//	while (1)
//	{
//		//20 
//		cin>>guess;
//		if (guess > ret)
//		{
//			cout << "猜大了" << endl;
//		}
//		else if (guess < ret)
//		{
//			cout << "猜小了"<<endl ;
//		}
//		else
//		{
//			cout << "宝贝你猜对了" << endl;
//			break;
//		}
//	}
//}
////RAND_MAX是0到32767之间
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(nullptr));
//	do
//	{
//		mune();
//		printf("请选择：");
//		cin >> input;
//		switch (input)
//		{
//		case 1:
//				game();
//				break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//折半查找
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
//			printf("找到你了：%d\n", arr[mid]);
//			break;
//		}
//	}
//	if (right < left)
//	{
//		cout << "未找到" << endl;
//
//	}
//	return 0;
//}

//打印乘法口诀表
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

//十个数中最大值
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

//1/1-1/2+1/3-1/4...+1/99-1/100的和
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

//在1到100中出现了多少个数字9
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
//	cout << "在1到100中出现了" << count << "个数字9";
//	return 0;
//}
//输出1到100之间，3的倍数
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

//从大到小输出
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
//		printf("输入密码：");
//		scanf("%s", password);
//		if (strcmp(password, "123456")==0)//==不能用来比较两个字符串是否相等，应该使用一个库函数-strcmp
//		{
//			printf("登录成功\n");
//			break;
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码均错误，退出程序\n");
//	}
//	return 0;
//}



//int main()
//{
//	char arr1[] = "welcome to china!!!!!!";
//	char arr2[] = "**********************";
//	int left = 0;
//	//int right=sizeof(arr1)/sizeof(sizeof(arr1[0])-2;
//	//""里面包括\0
//	//{}这里面不包括\0
//	//sizeof这种会把\0计算进去，而strlen不会计算\0
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");//执行系统命令的一个函数-cls-清空屏幕
//		left++;
//		right--;
//	}
//	return 0;
//}


//折半查找算法
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
//			printf("找到你了，下标是：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

////写一个代码，在arr数组（有序数组）中找到7
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
//			printf("找到了你了，下标是：%d\n", i);
//			break;
//		}
//		
//	}
//	if (i == sz)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//		int n = 0;
//		int ret = 1;
//		int sum = 0;
//		for (n = 1; n <= 3; n++)//下面代码的优化
//		{
//			ret = ret * n;
//			sum = sum + ret;
//		}
//		printf("sum=%d\n",sum);
//	return 0;
//}


//1！+2！+3！。。。。+n！
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

//求解n的阶乘
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
//	for (i = 0, k = 0; k = 0; i++, k++)//代码循环0次，0为假循环进不去
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
//	printf("请输入密码：");
//	scanf("%s", password);
//	while ((ch=getchar()) != '\n')
//	{
//		;
//	}
//	printf("请确认（Y/N：");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
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
//	printf("请注意了，你的电脑将在一分钟内关机，如果输入：我是猪，就取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
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
//		printf("请注意了，你的电脑将在一分钟内关机，如果输入：我是小笨蛋，就取消关机\n");
//		cout<< "请输入：";
//		scanf("%s", input);
//		if (strcmp(input, "我是小笨蛋") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}