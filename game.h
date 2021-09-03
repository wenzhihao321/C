//É¨À×ÓÎÏ·
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void Initboard(char board[ROWS][COLS], int rows, int cols,char set);
void Displayboard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);





//Èý×ÓÆå
//#define ROW 3
//#define COL 3
//  
//void InitBoard(char board[ROW][COL], int row, int col);
//void DisplayBoard(char board[ROW][COL], int row,int col);
//void PlayMove(char board[ROW][COL], int row, int col);
//void ComputerMove(char board[ROW][COL], int row, int col);
//char IsWin(char board[ROW][COL], int row, int col);

