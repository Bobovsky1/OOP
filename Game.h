#pragma once
#include <iostream>
#include "Map.h"
#include "Ship.h"
#include "Ship_Manager.h"
#include "Ability_Double.h"
#include "Ability_Scaner.h"
#include "Ability_Rocket.h"
#include "Ability_Manager.h"
#include "Exception_Wrong_Option.h"
#include "Exception_Ability_Unavailable.h"
#include "Exception_Attack_Out_Of_Bounds.h"
#include "Game_State.h"
using namespace std;

class Game
{
public:
	void gaming();
	void gaming_plus(Map* map, Ship_Manager* ship_manager);
	void game_round(Ship_Manager* enemy_ship_manager, Ship_Manager* ship_manager, Ability_Manager* ability_manager, Map* enemy_map, Map* map, int* double_damage_switch_pointer, Ability_Double* ability_double, Ability_Rocket* ability_rocket, Ability_Scaner* ability_scaner, Game_State* game_state);
};

