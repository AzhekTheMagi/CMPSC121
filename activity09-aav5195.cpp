//Author:	  Anthony Vallin, aav5195, 18Sep2018 1200
//Class:      CMPSC 121
//Lab:        Activity 09
//File:       activity09-aav5195.cpp
//Purpose: 	  Calculates the sum of the even digits in user supplied integer value. 
/********************************************************************\
* Academic Integrity Affidavit:                                      *                                                                                                                                                     *                                                                    *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *                                                                                                                                                                                                                                                                                                                       *                                                                    *
* I understand that submitting code which is totally or partially    *
* the product of other individuals is a violation of the Academic    *
* Integrity Policy and accepted ethical precepts. Falsified          *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment, reduced   *
* credit for the assignment, or course failure.                      *
\********************************************************************/
// Sources of Logic assistance: Activity 9 instructions

#include <iostream>
using namespace std;

int main()
{
	const int MIN_NUMBER = 10000; //Minimum acceptable user integer input
	int num1;          //Holds user input
	int digit;         //Holds even digit
	int sumTotal = 0;  //Accumulator for even digits
	int workingDigit;  //Holds user input. Changes during calculations

	//Asks for and validates user input
	do
	{
		cout << "Enter an integer greater than 10000: ";
		cin >> num1;
		if (num1 < MIN_NUMBER)
			cout << num1 << " is not greater than " << MIN_NUMBER << endl;
	} while (num1 < MIN_NUMBER);

	//Assigns original user input for use in calculations
	workingDigit = num1;

	//Takes each digit and checks for even int. Even numbers are calculated together for sum total.
	while (workingDigit > 0)
	{
		digit = (workingDigit % 10);
		workingDigit /= 10;
		if ((digit % 2) == 0)
			sumTotal += digit;
	}

	//Displays calculation output.
	cout << "The sum of the even digits of " << num1
		 << " is: " << sumTotal << endl;

	system("pause");
	return 0;
}

/*Solution Example:
Enter an integer greater than 10000: 34
34 is not greater than 10000
Enter an integer greater than 10000: 39428
The sum of the even digits of 39428 is: 14
Press any key to continue . . .
---
Enter an integer greater than 10000: 43210
The sum of the even digits of 43210 is: 6
Press any key to continue . . .
*/