#pragma once
#include "Ship.h"
#include "Map.h"
#include <vector>
using namespace std;
class Ship_Manager
{
public:
	Ship_Manager(int p_colvo1, int p_colvo2, int p_colvo3, int p_colvo4) :
		colvo1(p_colvo1), colvo2(p_colvo2), colvo3(p_colvo3), colvo4(p_colvo4) {}
	int colvo1;
	int colvo2;
	int colvo3;
	int colvo4;
	std::vector<Ship> ships;
	std::vector<int> x_coords;
	std::vector<int> y_coords;
	std::vector<int> pos_coords;
	void creating_ships();
	void placing_ships(Map* map);
	void placing_ships_random(Map* map);
	int killed_ships();
};