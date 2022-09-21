#include <iostream>
#include <conio.h>

class setting
{
public :
	void edit_size_map(int *size_map)
	{
		system("cls");
		//std::cout << "Current map size : " << size_map << std::endl;
		std::cout << std::endl << "Enter new size (number must be integer): " ;
		
		std::cin >> *size_map;
		system("cls");
	}

	void edit_speed_game(int* speed)
	{
		system("cls");
		std::cout << std::endl << "Enter new game speed : \n\n1 - Slow\n2 - Normal\n3 - Fast\n\nEsc - Leave unchanged";
		while (true)
		{
			char key = _getch();
			if (key == '1')
				*speed = 1;
			else if (key == '2')
				*speed = 2;
			else if (key == '3')
				*speed = 3;
			else if (key == 27)
				break;
		}
		system("cls");
	}

	void menu(int *size_map , int* speed)
	{
		while (true)
		{
			system("cls");
			std::cout << "1 - Start game\n2 - Setting\n3 - Score\n\nEsc - Exit";
			char key = _getch();
			if (key == '1')
			{
				std::cout << "start game";
			}
			else if (key == '2')
			{
				while (true)
				{
					system("cls");
					std::cout << "1 - Edit size map \n2 - Edit game speed\n\nEsc - Exit";
					key = _getch();
					if (key == '1')
					{
						system("cls");
						std::cout << "Current map size : " << size_map << std::endl;
						edit_size_map(size_map);
					}
					else if (key == '2')
					{
						system("cls");
						std::cout << "Current game speed : " << size_map << std::endl;
						edit_speed_game(speed);
					}
					else if (key == 27)
						break;
				}

			}
			else if (key == '3')
			{
				std::cout << "score";
			}
			else if (key == 27)
				break;
		}
	}
};

class menu
{

};