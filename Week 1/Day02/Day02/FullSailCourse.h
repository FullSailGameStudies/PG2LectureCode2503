#pragma once
#include <string>
class FullSailCourse
{
public:
	const std::string& GetName() const; //prevents the method from changing class data
	
	void SetName(const std::string& newName)// const  cannot be const b/c it changes the data of the class
	{
		name = newName;
	}

private:
	std::string name;
};

