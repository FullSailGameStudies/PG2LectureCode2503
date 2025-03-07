#include "ThemeSong.h"
#include <iostream>

//create definition for BatTheme
void ThemeSong::BatTheme(int count) const
{
	for (int i = 0; i < count; i++)
	{
		std::cout << "na ";
	}
	std::cout << "BATMAN!!\n";
}