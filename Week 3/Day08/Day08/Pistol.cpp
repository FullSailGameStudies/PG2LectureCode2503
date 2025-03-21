#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	//modes of overriding:
	//  extension: adding on to the base behavior
	//  full-override: totally new behavior

	//extension: call the base method
	//full: don't call the base method

	//call the base
	Weapon::showMe();

	std::cout << "\n\t Rounds: " << rounds_ << "\tMagazine Capacity: " << magCapacity_ << "\n";
}
