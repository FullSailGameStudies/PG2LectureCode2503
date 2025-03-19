#include "Person.h"
#include <iostream>

void Person::ItsMyBirthday()
{
	Age(age_ + 1);

	std::cout << "It's my birthday today! I am " << age_ << " years old!";
	std::cout << "Let's have some cake!!\n";
}
