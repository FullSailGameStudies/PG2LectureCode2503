#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::SerializeCSV(std::ostream& outFile, char delimiter)
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}

void Car::DeserializeCSV(const std::string& csvData, char delimiter)
{
	//use std::getline and stringstream to parse the csvData
	std::stringstream carStream(csvData);

	//year delimiter make delimiter model
	std::string data;
	std::getline(carStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(carStream, mMake, delimiter);
	std::getline(carStream, mModel, delimiter);
}
