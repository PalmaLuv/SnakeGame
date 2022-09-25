#include <iostream>
#include <conio.h>

/* game speed modes and max size map */
#define SPEADX1		200
#define SPEADX2		100
#define SPEADX5		50
#define SPEADX10	10
#define MAXSIZEMAP	100

/* funcion edit size map [max size : 100 | min size : 10]*/
void edit_size_map(int *size_map)
{
	while (true)
	{
		std::cout << std::endl << "Enter new size (number must be integer): ";
		std::cin >> *size_map;
		system("cls");
		if (*size_map <= MAXSIZEMAP) break;
		if (*size_map < 10) std::cout << "The number cannot be less than 10." << std::endl;
	}
}

/* funcion edit speed game , mode : [x1|x2|x5|x10]*/
void edit_speed_game(int* speed)
{
	std::cout << std::endl << "Enter new game speed : \n\n1 - x1\n2 - x2\n3 - x5\n4 - x10\n\nEsc - Leave unchanged";
	while (true)
	{
		char key = _getch();
		if (key == '1')
		{
			*speed = SPEADX1;
			break;
		}
		else if (key == '2')
		{
			*speed = SPEADX2;
			break;
		}
		else if (key == '3')
		{
			*speed = SPEADX5;
			break;
		}
		else if (key == '4')
		{
			*speed = SPEADX10;
			break;
		}
		else if (key == 27)
			break;
	}
	system("cls");
}
