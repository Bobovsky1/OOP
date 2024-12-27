#include "Ability_Manager.h"
#include <stdlib.h>
void Ability_Manager::new_ability()
{
	int reward = rand() % 3;
	if (reward == 0)
		double_count += 1;
	if (reward == 1)
		scaner_count += 1;
	if (reward == 2)
		rocket_count += 1;
}