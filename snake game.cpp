#include <iostream>
#include <conio.h> // provide console input / output
#include <windows.h> // declarations for all of the functions in the Windows API
#include <cstdlib> // for the random funtion


using namespace std;

// main varibale
bool gameOver;
const int width = 20;
const int height = 20;
int Score, x, y, FruitX, FruitY;
int tailX[100], tailY[100], nTail;
int poisen_FruitX, poisen_FruitY;

// for the direction
enum eDirection { STOP = 0, UP, DOWN, LEFT, RIGHT };
eDirection dir;

// main classes for the stack functions
class Fruit
{
private:
	int x, y, fruit_x, fruit_y;
public:
	int get_x()
	{
		x = width / 2;
		return x;
	}
	int get_y()
	{
		y = height / 2;
		return y;
	}
	int get_fruit_x()
	{
		fruit_x = rand() % width;
		return fruit_x;
	}
	int get_fruit_y()
	{
		fruit_y = rand() % height;
		return fruit_y;
	}
};

class Snake
{
	int nTail;
public:
	Snake()
	{
		nTail = 0;
	}
	int n_Tail()
	{
		return nTail;
	}
	string push()
	{
		return "o";
	}
	string pop()
	{
		return " ";
	}
};

// main functios of the game
void setup();
void Draw();
void Input();
void Logic();
void Logic2();
void Logic3();
void poisen();
void poisen_draw();
void level1()
{
	setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic3();
		Sleep(60);
	}
};
void level2()
{
	setup();
	while (!gameOver) {
		poisen_draw();
		Input();
		Logic2();
		Sleep(60);
	}
}
void level3()
{
	setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic3();
		Sleep(60);
	}
}

int main()
{

	 cout<<endl<<endl<<endl;
   for(int i=1; i <= 3; i++){
       cout<<"  ";
       for( int j=1; j<=100; j++)
       {
           cout<<"#";
       }
       cout<<endl;
   }
   
   cout<<"  ";
   cout<<"##";
   cout<<"                                         Snake Game                                             ";
   cout<<"##";
   cout<<endl;
   for(int i=1; i <= 3; i++){
       cout<<"  ";
       for( int j=1; j<=100; j++)
       {
           cout<<"#";
       }
       cout<<endl;
   }
   
   cout<<endl<<endl<<endl;

	system("color 4E");
	char check;

	cout << "levels: " << endl;
	cout << "level 1" << endl;
	cout << "level 2" << endl;
	// cout << "level 3" << endl;
	cout << "\n";

	cout << "Enter the level: ";
	cin >> check;

	switch (check)
	{
	case '1':
		level2();
		break;
	case '2':
		level3();
		break;
		/*case '3':
			level3();
			break;*/
	default:
		main();
		break;
	}
	return 0;
}

// implement the fuctions code
void setup()
{
	gameOver = false;
	Fruit f1;
	x = f1.get_x();
	y = f1.get_y();
	FruitX = f1.get_fruit_x();
	FruitY = f1.get_fruit_y();
}

void Draw()
{
	system("CLS");
	Snake s1;
	// for upper wall
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << endl;

	// for the Right and left wall
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == (width - 1))
				cout << "#";
			else if (i == y && j == x)
				cout << "O";
			else if (i == FruitY && j == FruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (i == tailY[k] && j == tailX[k])
						cout << s1.push();
				}
				if (!print)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	// for lower wall
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << endl;

	cout << "Score: " << Score << endl;

}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'W':
			dir = UP;
			break;
		case 'A':
			dir = LEFT;
			break;
		case 'S':
			dir = DOWN;
			break;
		case 'D':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		default:
			dir = STOP;
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	int prev2X, prev2Y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}

	if (x < 0 || x > width || y < 0 || y > height)
	{
		gameOver = true;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameOver = true;
		}
	}

	if (x == FruitX && y == FruitY)
	{
		Score = Score + 10;
		FruitX = rand() % width;
		FruitY = rand() % height;
		nTail++; // push�function
	}
}

void Logic2()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	int prev2X, prev2Y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}

	if (x < 0)
	{
		x = width - 1;
	}
	else if (x > width)
	{
		x = 1;
	}
	else if (y < 0)
	{
		y = height - 1;
	}
	else if (y > height)
	{
		y = 1;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameOver = true;
		}
	}

	if (x == FruitX && y == FruitY)
	{
		Score = Score + 10;
		FruitX = rand() % width;
		FruitY = rand() % height;
		nTail++; // push�function
	}
}

void Logic3()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	int prev2X, prev2Y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}

	if (x < 0)
	{
		x = width - 1;
	}
	else if (x > width)
	{
		x = 1;
	}
	else if (y < 0)
	{
		y = height - 1;
	}
	else if (y > height)
	{
		y = 1;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameOver = true;
		}
	}

	if (x == FruitX && y == FruitY)
	{
		Score = Score + 10;
		FruitX = rand() % width;
		FruitY = rand() % height;
		nTail++; // push�function
		poisen();
	}

	// poisen();
}

void poisen()
{
	poisen_FruitX = rand() % width;
	poisen_FruitY = rand() % height;
}

void poisen_draw()
{
	system("CLS");
	Snake s1;
	// for upper wall
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << endl;

	// for the Right and left wall
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == (width - 1))
				cout << "#";
			else if (i == y && j == x)
				cout << "O";
			else if (i == FruitY && j == FruitX)
				cout << "F";
			else if (i == poisen_FruitY && j == poisen_FruitX)
				cout << "@";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (i == tailY[k] && j == tailX[k])
						cout << s1.push();
					else if (i == tailY[k] && j == tailX[k])
						cout << s1.pop();
				}
				if (!print)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	// for lower wall
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << endl;

	cout << "Score: " << Score << endl;
}