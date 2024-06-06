#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int width = 20, height = 20;
int x, y, fruitX, fruitY, score, gameOver;
int flag;
int tailX[100], tailY[100], countTail = 0;

void setup()
{
	gameOver = 0;
	x = width / 2;
	y = height / 2;

label1:
	fruitX = rand() % 20;
	if (fruitX == 0)
	{
		goto label1;
	}

label2:
	fruitY = rand() % 20;
	if (fruitY == 0)
	{
		goto label2;
	}
	score = 0;
}

void draw()
{
	system("cls");
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				printf("*");
			}
			else
			{
				if (x == i && y == j)
				{
					printf("O");
				}
				else if (i == fruitX && j == fruitY)
				{
					printf("F");
				}
				else
				{
					int ch = 0;
					for (int k = 0; k < countTail; k++)
					{
						if (i == tailX[k] && j == tailY[k])
						{
							printf("o");
							ch = 1;
						}
					}
					if (ch == 0)
						printf(" ");
				}
			}
		}
		printf("\n");
	}
}

void input()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'a':
			flag = 1;
			break;
		case 'd':
			flag = 2;
			break;
		case 'w':
			flag = 3;
			break;
		case 's':
			flag = 4;
			break;
		case 'q':
			gameOver = 1;
			break;
		}
	}
}

void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < countTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (flag)
	{
	case 1:
		y--;
		break;
	case 2:
		y++;
		break;
	case 3:
		x--;
		break;
	case 4:
		x++;
		break;
	default:
		break;
	}

	if (x < 0 || x > width || y < 0 || y > height)
	{
		gameOver = 1;
	}
	for (int i = 0; i < countTail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameOver = 1;
		}
	}
	if (x == fruitX && y == fruitY)
	{
	label3:
		fruitX = rand() % 20;
		if (fruitX == 0)
		{
			goto label3;
		}

	label4:
		fruitY = rand() % 20;
		if (fruitY == 0)
		{
			goto label4;
		}
		score += 10;
		countTail++;
	}
}

int main()
{
label5:
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();

		for (int n = 0; n < 10000; n++)
		{
			for (int m = 0; m < 10000; m++)
			{
			}
		}
	}
	char c;
	printf("Press Y to play the game again : ");
	scanf("%c", &c);
	if (c == 'y' || c == 'Y')
	{
		goto label5;
	}
	return 0;
}