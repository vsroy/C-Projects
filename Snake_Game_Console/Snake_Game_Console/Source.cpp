//Porgram to implement a snake game in the console
#include<iostream>
#include<conio.h>
using namespace std;

const int width = 20; const int height = 20;
int snakeX; int snakeY; int foodX; int foodY;
bool gameOver; int score = 0;
enum Direction{STOP = 0, LEFT, RIGHT, UP, DOWN}dir;

void Setup()
{
	srand(time_t(NULL));
	gameOver = false; score = 0;
	snakeX = width / 2;
	snakeY = height / 2;
	foodX = rand() % width;
	foodY = rand() % width;
	dir = STOP;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == snakeX && j == snakeY)
				cout << "0";
			else if (i == foodX && j == foodY)
				cout << "F";
			else
				cout << " ";
			
			if (j == width - 1)
				cout << "#";	
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score = " << score;
}

void Input()
{
	if (_kbhit)
	{
		switch (_getch())
		{
		case 's':
			dir = DOWN;
			break;

		case 'd':
			dir = RIGHT;
			break;

		case 'w':
			dir = UP;
			break;

		case 'a':
			dir = LEFT;
			break;

		default:
			gameOver = true;
			break;
		}
	}
}


void Logic()
{
	switch (dir)
	{
	case LEFT:
		snakeX--;
		break;
	case RIGHT:
		snakeX++;
		break;
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	default:
		break;
	}

	if (snakeX > width || snakeX < 0 || snakeY > height || snakeY < 0)
		gameOver = true;

	if (snakeX == foodX && snakeY == foodY)
	{
		score += 10;
		foodX = rand() % width;
		foodY = rand() % width;
	}
}


int main()
{
	Setup();
	while (gameOver != true)
	{
		Draw();
		Input();
		Logic();
	}
	return 0;
}