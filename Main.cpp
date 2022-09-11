#include <iostream>
#include <windows.h>
#include <conio.h>

enum move_sides {
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	MOVE_STOP
} direction;

const int map_size = 20;

int head[1][2];
int body[map_size * map_size][2];
bool game_over = false;
int fruit_cord[1][2];
int lenth_snake;

void fruit_generation() {
again:
	fruit_cord[0][0] = rand() % map_size + 1;
	fruit_cord[0][1] = rand() % map_size + 1;
	for (int i = 0; i < lenth_snake; i++) {
		if (fruit_cord[0][0] == body[i][0] && fruit_cord[0][1] == body[i][1] || fruit_cord[0][0] == head[i][0] && fruit_cord[0][1] == head[i][1]) {
			goto again;
		}
	}
}

void preset() {
	fruit_generation();
	head[0][0] = map_size / 2; 
	head[0][1] = head[0][0];
	direction = MOVE_STOP;
	lenth_snake = 0;
}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			direction = MOVE_UP;
			break;

		case 's':
			direction = MOVE_DOWN;
			break;

		case 'a':
			direction = MOVE_LEFT;
			break;

		case 'd':
			direction = MOVE_RIGHT;
			break;
		}
	}
}

void logic() {
	bool ismoved = false;
	int iteration = lenth_snake;
	if (head[0][0] == fruit_cord[0][0] && head[0][1] == fruit_cord[0][1]) {
		fruit_generation();
		if (lenth_snake == 0) {
			body[lenth_snake][0] = head[0][0]; body[lenth_snake][1] = head[0][1];
		}
		else {
			body[lenth_snake][0] = body[lenth_snake - 1][0]; body[lenth_snake][1] = body[lenth_snake - 1][1];
		}
		ismoved = true;
		lenth_snake++;
	}

	if (ismoved == true) {
		iteration--;
	}

	for (int i = iteration; i >= 0; i--) {
		if (i == 0) {
			body[0][0] = head[0][0]; body[0][1] = head[0][1];
		}
		else {
			body[i][0] = body[i - 1][0]; body[i][1] = body[i - 1][1];
		}
	}

	switch (direction)
	{
	case MOVE_UP:
		head[0][1]--;
		break;
	case MOVE_DOWN:
		head[0][1]++;
		break;
	case MOVE_RIGHT:
		head[0][0]++;
		break;
	case MOVE_LEFT:
		head[0][0]--;
		break;
	}
}

void drаw() {
	for (int i = 0; i < map_size + 2; i++) {
		for (int j = 0; j < map_size + 2; j++) {

			if (j == 0 || i == 0 || j == map_size + 1 || i == map_size + 1) {
				std::cout << "#";
			}
			else if (j == head[0][0] && i == head[0][1]) {
				std::cout << "@";
			}
			else if (j == fruit_cord[0][0] && i == fruit_cord[0][1]) {
				std::cout << "F";
			}
			else {
				bool isBody = false;
				for (int k = 0; k < lenth_snake; k++) {
					if (body[k][0] == j && body[k][1] == i) {
						std::cout << "o";
						isBody = true;
					}
				}
				if (isBody == false) {
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}
	if (direction == MOVE_LEFT || direction == MOVE_RIGHT) {
		Sleep(100);
	}
	else {
		Sleep(200);
	}
	system("cls");
}

int main() {
	preset();
	while (game_over == false) {
		drаw();
		logic();
		input();
	}
	return 0;
}
