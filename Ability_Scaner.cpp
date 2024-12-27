#include "Ability_Scaner.h"
#include "Map.h"
#include <iostream>
#include "Exception_Wrong_Cell.h"
void Ability_Scaner::using_ability(int* double_damage_switch, int x, int y, Map map, Ship_Manager* ship_manager)
{
	try
	{
		if (x > map.width - 1 || x < 0 || y > map.height - 1 || y < 0) {
			throw Exception_Wrong_Cell{ "—ектора 2*2 с такими координатами левой верхней клетки не существует." };
		}
		else {
			if (map.cells[x - 1][y - 1].state == Map::Cell::states::unknown_ship || map.cells[x - 1][y - 1].state == Map::Cell::states::ship || map.cells[x][y - 1].state == Map::Cell::states::unknown_ship || map.cells[x][y - 1].state == Map::Cell::states::ship || map.cells[x - 1][y].state == Map::Cell::states::unknown_ship || map.cells[x - 1][y].state == Map::Cell::states::ship || map.cells[x][y].state == Map::Cell::states::unknown_ship || map.cells[x][y].state == Map::Cell::states::ship)
				cout << "¬ секторе обнаружен корабль.\n";
			else
				cout << "¬ секторе не обнаружено корабл€.\n";
		}
	}
	catch (const Exception_Wrong_Cell& err)
	{
		cout << err.what() << "\n";
	}
}