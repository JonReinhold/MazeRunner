#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;
char inputKey;

int mapArrayOne [16][33] =
{
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},
 {1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1},
 {1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1},
 {1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
 {1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,1,1,1,0,0,1,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1},
 {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
 {1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1}
};

void drawMaze();
void gotoXY(int, int);
void movement();

int main()
{     
	drawMaze();
	movement();
	system("pause");
	return 0;

}

void drawMaze()
{
	for(int counter = 0; counter < 16; counter++)
	{
		for(int newCounter = 0; newCounter < 33; newCounter++)
		{
			switch(mapArrayOne[counter][newCounter])
			{
		case 0:
			cout << " ";
			break;
		case 1:
			cout << char(219);
			break;
		case 2:
			cout << " ";
			break;
			}
		}
	cout << " " << endl;

	}

}

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y =y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	
}

void movement()
{
	int x =1;
	int y =1;
	int xbefore = 1;
	int ybefore =1;

	
	while(true)
	{
	gotoXY(xbefore, ybefore);
	cout << " ";
	gotoXY(x,y);
	cout << char(64);
	inputKey = _getch();

	if (x == 30 && y == 15)
		cout << "You Win!" << endl;	
		cout << "Congratulations, visit https://github.com/JonReinhold to complain that this was too easy." <<endl;
	xbefore =x;
	ybefore =y;
	
	if (inputKey == 'w')
		y -=1;
	else if (inputKey == 's')
		y +=1;
	else if (inputKey == 'a')
		x-=1;
	else if (inputKey == 'd')
		x+=1;

	if(mapArrayOne[y][x] == 1)
	{
		x = xbefore;
		y = ybefore;
	}
	}

}

