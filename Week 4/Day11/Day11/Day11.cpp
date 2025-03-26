// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
	std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

	Car myRide(1967, "Ford", "Shelby Mustang GT500");
	//1) open the file
	std::string fileName = "garage.csv";
	std::ofstream outFile(fileName);
	char delimiter = '$';
	if (outFile.is_open())
	{
		//call a Serialize method on the car object
		myRide.SerializeCSV(outFile, delimiter);
	}
	else std::cout << "Could not open the file: " << fileName << "\n";

	//3) close the file
	outFile.close();

	std::vector<Car> garage;
	garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
	garage.push_back(Car(1956, "Ford", "T Bird"));
	garage.push_back(Car(1961, "Porsche", "Speedster"));
	garage.push_back(Car(1965, "Pontiac", "GTO"));
	garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

	std::cout << "Nick's Garage\n";
	for (auto& car : garage)
	{
		car.SerializeCSV(std::cout, '\t');
		std::cout << "\n";
	}

	//1) open the file
	fileName = "cagesGarage.csv";
	std::ofstream garageOutput(fileName);
	char cardelimiter = '\n';
	if (garageOutput.is_open())
	{
		for (int i = 0; i < garage.size(); i++)
		{
			garage[i].SerializeCSV(garageOutput, delimiter);
			if(i < garage.size() - 1)
				garageOutput << cardelimiter;
		}

	}
	else std::cout << "Error opening file: " << fileName << "\n";
	garageOutput.close();

	Car sample("1974,Chevrolet,Nova SS", ',');
	fileName = "garage.csv";
	//1) open the file
	std::ifstream inGarage(fileName);
	std::cout << "\n\nDeserializing...\n";
	if (inGarage.is_open())
	{
		std::string carLine;
		std::getline(inGarage, carLine);
		Car myCar(carLine, '$');
		myCar.SerializeCSV(std::cout, '>');
	}
	else std::cout << "Error opening file: " << fileName << "\n";
	inGarage.close();


	fileName = "cagesGarage.csv";
	std::vector<Car> savedCars;
	std::ifstream cagesSaveFile(fileName);
	if (cagesSaveFile.is_open())
	{
		while (not cagesSaveFile.eof())
		{
			std::string line;
			std::getline(cagesSaveFile, line);
			Car nextCar(line, '$');
			savedCars.push_back(nextCar);
		}
	}
	else std::cout << "Error opening file: " << fileName << "\n";
	cagesSaveFile.close();

	std::cout << "\nSaved Cars:\n";
	for (auto& savedCar : savedCars)
	{
		savedCar.SerializeCSV(std::cout, '\t');
		std::cout << "\n";
	}

	/*
		╔═════════════╗
		║ Serializing ║
		╚═════════════╝

		Saving the state (data) of objects

		Lecture Code: serialize the vector of Cars to a file.
			Data Format:
				separates cars. EX: car1|car2|car3
				separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

	*/



	/*
		╔═══════════════╗
		║ Deserializing ║
		╚═══════════════╝

		Recreating the objects from the saved state (data) of objects

		Lecture Code:
			Open the file
			Read in each line
			split each line to get each car
			split each car to get the car details

	*/
}