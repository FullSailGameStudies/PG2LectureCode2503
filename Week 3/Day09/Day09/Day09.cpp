// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pistol.h"
#include <vector>


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	//static methods do NOT have a 'this' parameter
	//static methods can ONLY access other static members
	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static methods can access non-static AND static members
	void vehicleInfo() //there's a hidden parameter called 'this'
	{
		std::cout << "Model Year: " << this->mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;

int main()
{
	Car myRide(2025);
	Car currentCar(2009);
	myRide.vehicleInfo();
	currentCar.vehicleInfo();
	Car::reporting();

	int num = 5;
	int* ptrNum = &num;
	int& refNum = num;
	std::cout << num << "\n" << ptrNum << "\n" << refNum << "\n";
	std::cout << "*ptrNum: (dereference the pointer): " << *ptrNum << "\n";

	Pistol banger(50, 100, 20, 5);//lives on the stack section of memory
	Pistol pewpew = banger;//making a copy of the Pistol data
	Pistol* pPistol = &banger;
	Pistol* pPistol2 = pPistol;//copying the MEMORY address. it does NOT create a new pistol
	banger.showMe();
	pPistol->showMe();
	(*pPistol).showMe();

	Weapon wpn = pewpew;//copies the weapon parts to wpn
	Weapon* pWeapon = &pewpew;
	Pistol* ptrPewpew = &pewpew;
	std::cout << pWeapon << "\n" << ptrPewpew << "\n";
	std::cout << "\nWeapon showMe:\n";
	pWeapon->showMe();
	std::cout << "\n\nPistol showMe:\n";
	ptrPewpew->showMe();
	std::cout << "\n\n";

	std::vector<Weapon*> backpack;
	backpack.push_back(&pewpew);//UPCAST. Always safe.
	backpack.push_back(&banger);//making a copy!
	for (auto& weapon : backpack)
	{
		weapon->showMe();
	}
	//stores on the heap with "= new"
	//EVERY "=new" statement needs a "delete" statement
	//if you do not delete the heap memory and you lose
	//the pointer, you have leaked memory
	{
		//RAW pointer
		Pistol* ptrPistol = new Pistol(50, 100, 10, 1);

		Pistol* pPistol2 = ptrPistol;//copies the memory address
		delete ptrPistol;//release the Heap memory
		//ptrPistol->showMe();
		//pPistol2->showMe();//read access violation
	}
	//std::cout << ptrPistol;

	//a unique_ptr will release the memory 
	//when it goes out of scope
	{
		std::unique_ptr<Pistol> uPtrPistol =
			std::make_unique<Pistol>(50, 100, 10, 1);

		std::unique_ptr<Pistol> uPistol2 = std::move(uPtrPistol);

		uPistol2->showMe();
	}//when the scope closes, the unique_ptr will release the memory
	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/




	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide(1988);
	Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}