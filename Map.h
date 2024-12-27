#pragma once
#include "Ship.h"
#include <vector>
using namespace std;
class Map
{
public:
	Map(int p_x, int  p_y, int p_e)
	{
		width = p_x;
		height = p_y;
		enemy = p_e;
	}
	Map(const Map& p_map)
	{
		width = p_map.width;
		height = p_map.height;
		enemy = p_map.enemy;
		cells = p_map.cells;
	}
	Map(Map&& m_map) noexcept 
	{
		width = m_map.width;
		height = m_map.height;
		enemy = m_map.enemy;
		cells = m_map.cells;
	}
	class Cell
	{
	public:
		enum class states { unknown_empty, unknown_ship, empty, ship };
		states state = states::unknown_empty;
		Ship::Segment* pointer = 0;
	};
	int width;
	int height;
	int enemy;
	std::vector < vector <Cell> > cells;
	void reserving_map();
	int placing_ship(Ship* ship, int* x1, int* y1, int* position);
	int attack(int x2, int y2, int* double_damage_switch);
	void visual();
};
