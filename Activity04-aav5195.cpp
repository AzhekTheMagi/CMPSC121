//Author:     Anthony Vallin, aav5195, 04Sep2018 1849.
//Class:      CMPSC 121
//Activity:   04
//File:       Activity04-aav5195.cpp
//Purpose:    Convert Fahrenheit to Celsius Calculator

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double fahrenheitNum; //Fahrenheit temperature
	double celsiusNum;    //Celsius temperature

	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahrenheitNum;

	celsiusNum = ((fahrenheitNum - 32) * (5.0 / 9.0));

	cout << setprecision(2) << fixed;
	cout <<  celsiusNum << "  degrees Celsisus" << endl;

	system("pause");
	return 0;
}

/* Solution:
Enter temperature in Fahrenheit: 100
37.78
Press any key to continue . . .
*/