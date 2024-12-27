#pragma once
#include "Map.h"
#include "Ship_Manager.h"
class Ability
{
public:
	virtual void using_ability(int* double_damage_switch, int x, int y, Map map, Ship_Manager* ship_manager) = 0;
};

