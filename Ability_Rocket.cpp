#include "Ability_Rocket.h"
void Ability_Rocket::using_ability(int* double_damage_switch, int x, int y, Map map, Ship_Manager* ship_manager)
{
	int colvo = (*ship_manager).colvo1 + (*ship_manager).colvo2 + (*ship_manager).colvo3 + (*ship_manager).colvo4;
	int rand_ship = rand() % colvo;
	int rand_segment = rand() % (*ship_manager).ships[rand_ship].length;
	(*ship_manager).ships[rand_ship].segments[rand_segment].damaging();
}