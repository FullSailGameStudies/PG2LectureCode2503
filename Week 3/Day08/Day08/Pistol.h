#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage,int rounds, int magCapacity)
		: Weapon(range, damage), rounds_(rounds), magCapacity_(magCapacity)
	{
	}

	void showMe();// override;//override is optional BUT good coding

	int GetRounds() const { return rounds_; }
	void SetRounds(int rounds)
	{
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}

	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int magCap)
	{
		if (magCap > 0 && magCap <= 12)
			magCapacity_ = magCap;
	}

private:
	int rounds_, magCapacity_;
};

