#include "Calculator.h"

int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

bool Calculator::isEven(int numberToCheck)
{
	return numberToCheck % 2 == 0;
}


double Calculator::mult(double num, double factor)
{
	return num * factor;
}
