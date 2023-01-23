//Author:     Anthony Vallin, aav5195, 29Aug2018 0920.
//Class:      CMPSC 121
//Activity:   03
//File:       Activity03-aav5195-1.cpp
//Purpose:    Read-in 5 numbers and give average of those numbers

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num1, num2, num3, num4, num5; //User read-in values
	double average = 5.0;             //Initially assigned total number of read-in ints. 

	//Input Phase
	cout << setprecision(2) << fixed;
	cout << "Please enter five numbers: ";

	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	//Processing Phase: Calculate average
	average = (num1 + num2 + num3 + num4 + num5) / average;

	//Output Phase: Display average
	cout << "Your average is " << average << endl;

	system("pause");
	return 0;
}

/* Solution Sample:
Please enter five numbers: 6 5 4 3 2
Your average is 4.00
Press any key to continue . . .
*/