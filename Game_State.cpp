#include "Game_State.h"
void Game_State::saving(Map map, Map enemy_map, Ship_Manager ship_manager, Ship_Manager enemy_ship_manager, Ability_Manager ability_manager)
{
	std::ofstream out;          
	out.open("save_file.txt");
	out << map.width << " " << map.height << std::endl;
	out << ship_manager.colvo1 << " " << ship_manager.colvo2 << " " << ship_manager.colvo3 << " " << ship_manager.colvo4 << std::endl;
	int colvo = ship_manager.colvo1 + ship_manager.colvo2 + ship_manager.colvo3 + ship_manager.colvo4;
	for (int i = 0; i < colvo; i++)
		out << ship_manager.x_coords[i] + 1 << " " << ship_manager.y_coords[i] + 1 << " " << ship_manager.pos_coords[i] << std::endl;

	for (int i = 0; i < colvo; i++)
		out << enemy_ship_manager.x_coords[i] + 1 << " " << enemy_ship_manager.y_coords[i] + 1 << " " << enemy_ship_manager.pos_coords[i] << std::endl;
	out << ability_manager.double_count << " " << ability_manager.rocket_count << " " << ability_manager.scaner_count << std::endl;
	out << attacks;
}