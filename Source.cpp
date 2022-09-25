#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Action.cpp" // conection file 'action.cpp'.

void edit_size_map(int* size_map);
void edit_speed_game(int* speed);
void start_game();

class menu
{
public :
	void Menu(int* size_map, int* speed)
	{
		while (true)
		{
			system("cls");
			std::cout << "1 - Start game\n2 - Setting\n3 - Score\n\nEsc - Exit";
			char key = _getch();
			if (key == '1')
			{
				system("cls");
				start_game();
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
						std::cout << "Current map size : " << param.map_size << std::endl;
						edit_size_map(size_map);
					}
					else if (key == '2')
					{
						system("cls");
						GetInfoSpeed(param.speed);
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
private : 
	void GetInfoSpeed(int i)
	{
		std::cout << "Current game speed : ";
		if (i == 200) std::cout << "x1" << std::endl;
		else if (i == 100) std::cout << "x2" << std::endl;
		else if (i == 50) std::cout << "x5" << std::endl;
		else if (i == 10) std::cout << "x10" << std::endl;
	}
};

int main() {
	menu m;
	m.Menu(&param.map_size, &param.speed);
	return 0;
}
