#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Game game;
	game.gaming();

	/*int p_height, p_width;
	int colvo_1, colvo_2, colvo_3, colvo_4;
	cout << "Введите размеры поля.\n";
	cin >> p_height >> p_width;
	Map map(p_height, p_width);
	Map* map_pointer = &map;
	map.reserving_map();
	cout << "Введите сначала количество одноклеточных, потом двуклеточных, трёхклеточных и четырёхклеточных кораблей.\n";
	cin >> colvo_1 >> colvo_2 >> colvo_3 >> colvo_4;
	Ship_Manager ship_manager(colvo_1, colvo_2, colvo_3, colvo_4);
	ship_manager.creating_ships();
	ship_manager.placing_ships(map_pointer);
	Ability_Double ability_double;
	Ability_Scaner ability_scaner;
	Ability_Rocket ability_rocket;
	Ability_Manager ability_manager;
	int abilities = 1;
	int check = 10000;
	int double_damage_switch = 0;
	int* double_damage_switch_pointer = &double_damage_switch;
	while (check != 0)
	{
		try
		{
			cout << "Введите 0, если хотите завершить работу программы.\nВведите 1, если хотите проверить состояние клетки.\nВведите 2, если хотите атаковать клетку.\nВведите 3, если хотите использовать способность.\n";
			cin >> check;
			if (check > 3)
				throw Exception_Wrong_Option{"Выберите существующую опцию."};
			if (check == 1)
			{
				cout << "Введите координаты интересующей вас клетки.\n";
				int j, k;
				cin >> j >> k;
				if (j <= 0 || k <= 0 || j > p_height || k > p_width)
					throw Exception_Attack_Out_Of_Bounds{ "Клетки с такими координатами нет на поле." };
				else
				{
					if (map.cells[j - 1][k - 1].state == Map::Cell::states::empty)
						cout << "Клетка пуста.\n";
					else
					{
						if ((*map.cells[j - 1][k - 1].pointer).state == Ship::Segment::states::whole)
							cout << "Сегмент корабля цел.\n";
						if ((*map.cells[j - 1][k - 1].pointer).state == Ship::Segment::states::damaged)
							cout << "Сегмент корабля повреждён.\n";
						if ((*map.cells[j - 1][k - 1].pointer).state == Ship::Segment::states::destroyed)
							cout << "Сегмент корабля уничтожен.\n";
					}
				}
			}
			if (check == 2)
			{
				int kill_begin = ship_manager.killed_ships();
				cout << "Введите координаты атакуемой клетки.\n";
				int j, k;
				cin >> j >> k;
				if (j <= 0 || k <= 0 || j > p_height || k > p_width)
					throw Exception_Attack_Out_Of_Bounds{ "Клетки с такими координатами нет на поле." };
				else
					map.attack(j, k, double_damage_switch_pointer);
				int kill_end = ship_manager.killed_ships();
				if (kill_begin < kill_end)
				{
					cout << "Поздравляем! вы получили новую способность!\n";
					ability_manager.new_ability();
				}
			}
			if (check == 3)
			{
				cout << "Введите 1, если хотите использовать удваивание урона. Ещё использований: " << ability_manager.double_count << "\nВведите 2, если хотите использовать сканер. Ещё использований: " << ability_manager.scaner_count << "\nВведите 3, если хотите использовать самонаводящуюся ракету. Ещё использований: " << ability_manager.rocket_count << "\nВведите 4, если хотите выйти из меню способностей.\n";
				cin >> check;
				if (check > 4)
					throw Exception_Wrong_Option{ "Выберите существующую опцию." };
				if (check == 1)
				{
					if (ability_manager.double_count > 0)
					{
						ability_double.using_ability(double_damage_switch_pointer, 1, 1, map, &ship_manager);
						ability_manager.double_count -= 1;
					}
					else
						throw Exception_Ability_Unavailable{ "Эта способность вам сейчас не доступна." };
				}
				if (check == 2)
				{
					if (ability_manager.scaner_count > 0)
					{
						cout << "Введите координаты левой верхней клетки сектора.\n";
						int j, k;
						cin >> j >> k;
						ability_scaner.using_ability(double_damage_switch_pointer, j, k, map, &ship_manager);
						ability_manager.scaner_count -= 1;
					}
					else
						throw Exception_Ability_Unavailable{ "Эта способность вам сейчас не доступна." };
				}
				if (check == 3)
				{
					if (ability_manager.rocket_count > 0)
					{
						int kill_begin = ship_manager.killed_ships();
						ability_rocket.using_ability(double_damage_switch_pointer, 1, 1, map, &ship_manager);
						int kill_end = ship_manager.killed_ships();
						if (kill_begin < kill_end)
						{
							cout << "Поздравляем! вы получили новую способность!\n";
							ability_manager.new_ability();
						}
						ability_manager.rocket_count -= 1;
					}
					else
						throw Exception_Ability_Unavailable{ "Эта способность вам сейчас не доступна." };
				}
				if (check == 4)
					continue;
			}
		}
		catch (const Exception_Ability_Unavailable& err)
		{
			cout << err.what() << "\n";
		}
		catch (const Exception_Attack_Out_Of_Bounds& err)
		{
			cout << err.what() << "\n";
		}
		catch (const Exception_Wrong_Option& err)
		{
			cout << err.what() << "\n";
		}
	}
	return 0;*/
}