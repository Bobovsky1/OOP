#pragma once
#include "Ability.h"
#include "Map.h"
#include "Ship_Manager.h"
class Ability_Double: public Ability
{
public:
	void using_ability(int* double_damage_switch, int x, int y, Map map, Ship_Manager* ship_manager);
};

