#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(&board[0][0], ' ', row*col*sizeof(board[0][0]));
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		if (i < row - 1)
			printf("---------------\n");

	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);

		//判断是否越界
		if (x >= row && x <= 1 && y >= col && y <= 1)
		{
			printf("输入错误！请重新输入：\n");
		}
		//如果用户选择的坐标为空，则将空格改为X，否则提示输入错误
		if (board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = 'X';
			break;
		}
		else
		{
			printf("输入错误，请重新输入：\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	char ch = 0;
	int a = 0;

	//判断每一行是否一样
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == 'X')
		{
			return 'X';
		}
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '0')
		{
			return '0';
		}
		
		
	}
	
	//判断每一列是否一样
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == 'X')
		{
			return 'X';
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == '0')
		{
			return '0';
		}
		
	}
	
	//判断对角线是否满足相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'X')
	{
		return 'X';
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'X')
	{
		return 'X';
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == '0')
	{
		return '0';
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == '0')
	{
		return '0';
	}
	

	//若board数组被填满，则为平局返回’Q'
	ch = IsFull(board, row, col);
	if (ch == 'Q')
	{
		return 'Q';
	}
}

char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'C';
			}
		}
	}
	return 'Q';
}