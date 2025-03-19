#pragma once
#include <string>
class Person
{
public:

	Person(int age, const std::string& name)
		: age_(age), name_(name)
	{
	}

	void ItsMyBirthday();

	int Age() const { return age_; }
	std::string Name() const { return name_; }

	void Age(int age)
	{
		if (age >= 0 && age <= 120)
			age_ = age;
	}
	void Name(std::string name)
	{
		if (name.size() > 0 && name.size() < 32)
			name_ = name;
	}

private:
	int age_;
	std::string name_;
public:

};

