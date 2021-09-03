#include"game.h"
#include<iostream>
using namespace std;
//扫雷游戏
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印序列号
	for (i = 0; i <= col; i++)
	{
		cout << i<<" ";
	}
	cout << endl;
	for (i = 1; i <= row; i++)
	{
		cout << i << " ";
		for (j = 1; j <= col; j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout << endl;
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//'1'-'0'=1
//'3'-'0'=3
int get_mine_count(char mine[ROWS][COLS], int x,int y)
{
	int i = 0, j = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			 count =count+ mine[i][j];
		}
	}
	return count - 9 * '0';
}

void ShowBoard(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (show[i][j] != ' ' && i >= 1 && i <= ROW && j >= 1 && j <= COL)
			{
				int temp = get_mine_count(mine, i, j);
				show[i][j] = temp + '0';
				if (show[i][j] == '0')
				{
					show[x][y] = ' ';
					ShowBoard(mine, show, i, j);//递归实现扫雷的扩展
				}
			}
		}
	}
}
int Remain(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
				count++;
		}
	}
	return count;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win!=EASY_COUNT)
	{
		int x = 0;
		int y = 0;
		cout << "请输入排查雷的坐标：";
		cin >> x >> y;
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				cout << "你踩雷了，你被炸死了" << endl;
				Displayboard(mine, row, col);
				break;
			}
			else//mine[x][y]=='0'
			{
				show[x][y] =get_mine_count(mine, x, y) + '0';
				if (show[x][y] == '0')
				{
					show[x][y] = ' ';
					ShowBoard(mine, show, x, y);
				}
				Displayboard(mine, row, col);
				Displayboard(show, row, col);
			}
		}
		else
		{
			cout << "输入坐标错误，请重新输入！" << endl;
		}
		win = Remain(show, row, col);
	}
	if (win == EASY_COUNT)
	{
		cout << "恭喜你，排雷成功" << endl;
	}
}

//展开功能的时候-递归



//三子棋
//void InitBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i=0;i<row;i++)
//	{
//		for (j=0;j<col;j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j=0;j<col;j++)
//		{
//			//打印数据
//			cout << " " << board[i][j] << " ";
//			if (j < col - 1)
//			{
//				cout << "|";
//			}
//		}
//		cout << endl;
//		//打印分隔行
//		if (i< row - 1)
//		{
//			for (j = 0; j < col; j++)
//			{
//				cout << "---";
//				if (j < col - 1)
//				{
//					cout << "|";
//				}
//			}
//		}
//		cout << endl;
//	}
//}
//void PlayMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	cout << "玩家走：" ;
//	cin >> x >> y;
//	while (1)
//	{
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				cout << "输入错误，该区域被占用" << endl;
//			}
//		}
//		else
//		{
//			cout << "坐标输入错误，请重新输入！"<<endl;
//		}
//	}
//}
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	cout << "电脑走：" << endl;
//	while (1)
//	{
//		x = rand() % row;
//		y = rand() % col;
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//	
//}
////返回1表示棋盘满了
////返回0表示棋盘没满
//
//int IsFull(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//			{
//				return 0;//没满了
//			}
//		}
//	}
//	return 1;//满了
//
//}
//char IsWin(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	//横三行
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0]== board[i][1] && board[i][1]== board[i][2] && board[i][0] != ' ')
//		{
//			return board[i][0];
//		}
//	}
//	//竖三列
//	for (i = 0; i < col; i++)
//	{
//		if (board[0][i]== board[1][i] && board[1][i]== board[2][i] && board[0][i] != ' ')
//		{
//			return board[0][i];
//		}
//	}
//	//两个对角线
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//	{
//		return  board[1][1];
//	}
//	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
//	{
//		return  board[1][1];
//	}
//	//判断棋盘是否平局
//	if (1 == IsFull(board, ROW, COL))
//	{
//		return 'Q';
//	}
//	return 'C';
//}
