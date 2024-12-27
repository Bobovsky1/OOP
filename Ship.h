#include <vector>
#pragma once
class Ship
{
public:
	Ship(int Length) :
		length(Length){}
	class Segment
	{
	public:
		enum class states { whole, damaged, destroyed };
		states state = states::whole;
		int health = 2;
		void damaging();
	};
	int length;
	std::vector <Segment> segments;
	void creating_ship();
};