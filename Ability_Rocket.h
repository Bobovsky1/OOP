#pragma once
#include "Ability.h"
#include "Ship_Manager.h"
#include "Ship.h"
class Ability_Rocket: public Ability
{
public:
	void using_ability(int* double_damage_switch, int x, int y, Map map, Ship_Manager* ship_manager);
};

