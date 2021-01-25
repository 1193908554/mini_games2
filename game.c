#define _CRT_SECURE_NO_WARNINGS 1//���ں�����ȫ����
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//��ʼ��
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	//��ӡ�к�
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------\n");
}


void SetMine(char board[ROWS][COLS], int row, int col)//������
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//0-8 + 1 => 1-9
		int y = rand() % col + 1;//0-8 + 1 => 1-9
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_min_count(char mine[ROWS][COLS], int x, int y)//�����׵ĸ���
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - '0' * 8;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("�������Ų��׵�����:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')//����
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//������
			{
				int count = get_min_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;

			}
		}
		else//���ݷǷ�
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�������׳ɹ���");
		DisplayBoard(mine, row, col);
	}
}