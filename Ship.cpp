#include "Ship.h"
void Ship::Segment::damaging() 
{
	if (state == states::whole) {
		state = states::damaged;
		health = 1;
	}
	else{
		state = states::destroyed;
		health = 0;
	}
}

void Ship::creating_ship()
{
	for (int i = 0; i < length; i++) {
		Segment new_segment;
		segments.push_back(new_segment);
	}
}

