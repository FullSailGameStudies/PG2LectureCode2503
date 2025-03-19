#pragma once
#include <string>
#include "../../../Shared/Console/Console.h"

const int MaxSpeed = 10;
class PlayerShip
{
	//access modifiers
	//public: ALL code can see it/access it
	//protected: (inheritance) my class and ALL descendent classes (children, gran-childs, etc)
	//private: (default) ONLY this class can access it*

	//the rule: be protective of your class (hide it!!)
public:

	//constructors (ctors)
	// IF you do NOT create a ctor, the compiler will give
	//   you a default ctor. 
	// IF you DO create a ctor, the compiler's ctor
	//	 is NO LONGER available
	PlayerShip() //a default ctor
	{
		name_ = "";
		rotation_ = 0; speed_ = 0;
		xPosition_ = Console::GetWindowWidth() / 2;
		yPosition_ = Console::GetWindowHeight() / 2;
	}

	PlayerShip(int rot, int sp)
	{
		rot = rotation_;//backwards!!!
		sp = speed_;
	}
	
	PlayerShip(std::string& name, int rotation, int speed, int x, int y) :
		//prefer to use the "member initialization list"
		name_(name)
		,rotation_(rotation)
		,speed_(speed)
		,xPosition_(x)
		,yPosition_(y)
	{

	}

	//methods (member functions, behaviors)
	// accelerate, rotate, shoot, hyperjump
	// PascalNamingConvention

	// _stricmp, rand, stoi
	// push_back
	// remove_if

	//getters (accessors)
	// the return type matches the field type
	// no parameters
	// const
	int GetRotation() const { return rotation_; }
	int Speed() const { return speed_; }

	//setters (mutators)
	//  return type is usually void
	//  at least 1 parameter to set the field with
	void SetRotation(int newRotation)
	{
		rotation_ = newRotation;
	}
	void Speed(int newSpeed)
	{
		if (newSpeed >= 0 && newSpeed <= MaxSpeed)
		{
			speed_ = newSpeed;
		}
	}

	const std::string& Name() const {
		return name_;
	}


protected:

private:
	std::string name_;// = "Batmobile";
	//fields (data members)
	// camelCasingNamingConvention
	//m_iRotation, mRotation, _rotation, rotation_
	int rotation_, speed_, xPosition_, yPosition_;

	void simple(int rotation)
	{
		int rot;
		rotation = rotation;

	}
};

