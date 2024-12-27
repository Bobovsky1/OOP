#pragma once
#include <iostream>
#include <fstream>
#include "Map.h"
#include "Ship_Manager.h"
#include "Ability_Manager.h"
#include "Ship.h"
#include <string>
class Game_State
{
public:
	void saving(Map map, Map enemy_map, Ship_Manager ship_manager, Ship_Manager enemy_ship_manager, Ability_Manager ability_manager);
	std::string attacks = "";
};

