#include "Map.h"
#include "Ship.h"
#include <iostream>
#include "Exception_Wrong_Cell.h"
#include "Exception_Ship_Wreck.h"
using namespace std;
int Map::placing_ship(Ship* ship, int* x1, int* y1, int* position) {
	(*x1) -= 1;
	(*y1) -= 1;
	try
	{
		if ((*x1) < 0 || (*y1) < 0 || (*x1) >= width || (*y1) >= height)
		{
			throw Exception_Wrong_Cell{"Недопустимые координаты! Клетки не существует."};
		}

		if ((*position) == 1 && ((*y1) + (*ship).length - 1 >= height))
		{
			throw Exception_Wrong_Cell{"Недопустимые координаты! Корабль выйдет за пределы поля."};
		}

		if ((*position) == 0 && ((*x1) + (*ship).length - 1 >= width))
		{
			throw Exception_Wrong_Cell{"Недопустимые координаты! Корабль выйдет за пределы поля."};
		}
	}
	catch (const Exception_Wrong_Cell& err)
	{
		if (enemy == 0)
			cout << err.what() << "\n";
		return 1;
	}
	try
	{
		for (int i = 0; i < (*ship).length; i++) {
			if ((*position) == 1)
			{
				if ((cells[(*x1)][(*y1) + i].state == Cell::states::ship || (cells[(*x1)][(*y1) + i].state == Cell::states::unknown_ship)))
					throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*x1) + 1 < width)
					if (cells[(*x1) + 1][(*y1) + i].state == Cell::states::ship || cells[(*x1) + 1][(*y1) + i].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*x1) - 1 >= 0)
					if (cells[(*x1) - 1][(*y1) + i].state == Cell::states::ship || cells[(*x1) - 1][(*y1) + i].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*y1) + i + 1 < height)
					if (cells[(*x1)][(*y1) + i + 1].state == Cell::states::ship || cells[(*x1)][(*y1) + i + 1].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*y1) + i - 1 >= 0)
					if (cells[(*x1)][(*y1) + i - 1].state == Cell::states::ship || cells[(*x1)][(*y1) + i - 1].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) + 1 < width) && ((*y1) + i + 1 < height))
					if (cells[(*x1) + 1][(*y1) + i + 1].state == Cell::states::ship || cells[(*x1) + 1][(*y1) + i].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) + 1 < width) && ((*y1) + i - 1 >= 0))
					if (cells[(*x1) + 1][(*y1) + i - 1].state == Cell::states::ship || cells[(*x1) + 1][(*y1) + i].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) - 1 >= 0) && ((*y1) + i + 1 < height))
					if (cells[(*x1) - 1][(*y1) + i + 1].state == Cell::states::ship || cells[(*x1) + 1][(*y1) + i].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) - 1 >= 0) && ((*y1) + i - 1 >= 0))
					if (cells[(*x1) - 1][(*y1) + i - 1].state == Cell::states::ship || cells[(*x1) + 1][(*y1) + i].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
			}
			else
			{
				if (cells[(*x1) + i][(*y1)].state == Cell::states::ship || cells[(*x1) + i][(*y1)].state == Cell::states::unknown_ship)
					throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*x1) + i + 1 < width)
					if (cells[(*x1) + i + 1][(*y1)].state == Cell::states::ship || cells[(*x1) + i + 1][(*y1)].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*x1) + i - 1 >= 0)
					if (cells[(*x1) + i - 1][(*y1)].state == Cell::states::ship || cells[(*x1) + i - 1][(*y1)].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*y1) + 1 < height)
					if (cells[(*x1) + i][(*y1) + 1].state == Cell::states::ship || cells[(*x1) + i][(*y1) + 1].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if ((*y1) - 1 >= 0)
					if (cells[(*x1) + i][(*y1) - 1].state == Cell::states::ship || cells[(*x1) + i][(*y1) - 1].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) + i + 1 < width) && ((*y1) + 1 < height))
					if (cells[(*x1) + i + 1][(*y1) + 1].state == Cell::states::ship || cells[(*x1) + i + 1][(*y1)].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) + i + 1 < width) && ((*y1) - 1 >= 0))
					if (cells[(*x1) + i + 1][(*y1) - 1].state == Cell::states::ship || cells[(*x1) + i + 1][(*y1)].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) + i - 1 >= 0) && ((*y1) + 1 < height))
					if (cells[(*x1) + i - 1][(*y1) + 1].state == Cell::states::ship || cells[(*x1) + i + 1][(*y1)].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
				if (((*x1) + i - 1 >= 0) && ((*y1) - 1 >= 0))
					if (cells[(*x1) + i - 1][(*y1) - 1].state == Cell::states::ship || cells[(*x1) + i + 1][(*y1)].state == Cell::states::unknown_ship)
						throw Exception_Ship_Wreck{ "Корабль не может быть помещён на другой корабль!" };
			}
		}
	}
	catch (const Exception_Ship_Wreck& err)
	{
		if (enemy == 0)
			cout << err.what() << "\n";
		return 1;
	}

	for (int i = 0; i < (*ship).length; i++) {
		if (enemy == 0)
		{
			if ((*position) == 1)
			{
				cells[(*x1)][(*y1) + i].state = Cell::states::ship;
				cells[(*x1)][(*y1) + i].pointer = &(*ship).segments[i];
			}
			else
			{
				cells[(*x1) + i][(*y1)].state = Cell::states::ship;
				cells[(*x1)][(*y1) + i].pointer = &(*ship).segments[i];
			}
		}
		else
		{
			if ((*position) == 1)
			{
				cells[(*x1)][(*y1) + i].state = Cell::states::unknown_ship;
				cells[(*x1)][(*y1) + i].pointer = &(*ship).segments[i];
			}
			else
			{
				cells[(*x1) + i][(*y1)].state = Cell::states::unknown_ship;
				cells[(*x1)][(*y1) + i].pointer = &(*ship).segments[i];
			}
		}
	}
	return 0;
}

int Map::attack(int x2, int y2, int* double_damage_switch)
{
	if (cells[x2 - 1][y2 - 1].state != Cell::states::ship && cells[x2 - 1][y2 - 1].state != Cell::states::unknown_ship)
	{
		if (cells[x2 - 1][y2 - 1].state == Cell::states::unknown_empty)
		{
			cout << "Промах!";
			cells[x2 - 1][y2 - 1].state = Cell::states::empty;
		}
		return 0;
	}
	(*cells[x2-1][y2-1].pointer).damaging();
	if ((*double_damage_switch) == 1) {
		(*cells[x2 - 1][y2 - 1].pointer).damaging();
		(*double_damage_switch) = 0;
	}
	if (cells[x2 - 1][y2 - 1].state == Cell::states::unknown_ship)
	{
		cout << "Попадание!";
		cells[x2 - 1][y2 - 1].state = Cell::states::ship;
	}
	return 0;
}

void Map::reserving_map()
{
	for (int i = 0; i < width; i++) {
		cells.push_back(vector<Cell>());
		for (int y = 0; y < height; y++) {
			Cell new_cell;
			if (enemy == 0)
				new_cell.state = Cell::states::empty;
			else
				new_cell.state = Cell::states::unknown_empty;
			cells[i].push_back(new_cell);
		}
	}
}

void Map::visual()
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (cells[i][j].state == Cell::states::unknown_empty)
				cout << ". ";
			if (cells[i][j].state == Cell::states::unknown_ship)
				cout << ". ";
			if (cells[i][j].state == Cell::states::empty)
				cout << "_ ";
			if (cells[i][j].state == Cell::states::ship)
				cout << (*(cells[i][j].pointer)).health << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
