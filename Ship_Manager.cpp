#include "Ship_Manager.h"
#include <iostream>
#include <ctime>
using namespace std;
void Ship_Manager::creating_ships()
{
	int p = 0;
	for (int i = 0; i < colvo1; i++)
	{
		Ship new_ship(1);
		ships.push_back(new_ship);
		ships[p].creating_ship();
		p++;
	}

	for (int i = 0; i < colvo2; i++)
	{
		Ship new_ship(2);
		ships.push_back(new_ship);
		ships[p].creating_ship();
		p++;
	}

	for (int i = 0; i < colvo3; i++)
	{
		Ship new_ship(3);
		ships.push_back(new_ship);
		ships[p].creating_ship();
		p++;
	}

	for (int i = 0; i < colvo4; i++)
	{
		Ship new_ship(4);
		ships.push_back(new_ship);
		ships[p].creating_ship();
		p++;
	}
}

void Ship_Manager::placing_ships(Map* map)
{
	int colvo = colvo1 + colvo2 + colvo3 + colvo4;
	int x3, y3, positioning;
	for (int i = 0; i < colvo; i++)
	{
		std::cout << "Введите координаты корабля и его позицию (горизонтально - 0, вертикально - 1), сначала расставляются короткие корабли.\n";
		std::cin >> x3 >> y3 >> positioning;
		int switchy = 1;
		switchy = (*map).placing_ship((&(ships[i])), &x3, &y3, &positioning);
		if (switchy != 0) {
			cout << "Введите координаты заново!\n";
			i--;
		}
		else
		{
			x_coords.push_back(x3);
			y_coords.push_back(y3);
			pos_coords.push_back(positioning);
		}
	}
}

void Ship_Manager::placing_ships_random(Map* map)
{
	int colvo = colvo1 + colvo2 + colvo3 + colvo4;
	int x3, y3, positioning;
	srand(time(0));
	for (int i = 0; i < colvo; i++)
	{
		int switchy = 1;
		x3 = rand() % (*map).width;
		y3 = rand() % (*map).height;
		positioning = rand() % 2;
		switchy = (*map).placing_ship((&(ships[i])), &x3, &y3, &positioning);
		if (switchy != 0) {
			i--;
		}
		else
		{
			x_coords.push_back(x3);
			y_coords.push_back(y3);
			pos_coords.push_back(positioning);
		}
	}
}

int Ship_Manager::killed_ships()
{
	int death_count = 0;
	for (int i = 0; i < colvo1 + colvo2 + colvo3 + colvo4; i++)
	{
		int life = 0;
		for (int j = 0; j < ships[i].length; j++)
		{
			if (ships[i].segments[j].state == Ship::Segment::states::whole || ships[i].segments[j].state == Ship::Segment::states::damaged)
				life = 1;
		}
		if (life == 0)
			death_count += 1;
	}
	return death_count;
}