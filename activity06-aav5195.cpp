//Author:	  Anthony Vallin, aav5195, 11Sep2018 1800
//Class:      CMPSC 121
//Lab:        Activity 06
//File:       activity06-aav5195.cpp
//Purpose: 	  Determine whether date is a magic number  
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
// Sources of Logic assistance:

#include <iostream>
using namespace std;

int main()
{
	int month;       
	int day;
	int year;
	int multiplier; //Holds multiplication of day and month

	cout << "Enter date in format mm/dd/yy: ";
	cin >> month >> day >> year;

	multiplier = day * month;

	if (year == multiplier)
		cout << "It's a Magic Date!! :D" << endl;
	else
		cout << "Not a Magic Date. :(" << endl;

	system("pause");
	return 0;
}

/*Solution Example:
Enter date in format mm/dd/yy: 8 2 16
It's a Magic Date!! :D
Press any key to continue . . .
----
Enter date in format mm/dd/yy: 4 25 84
Not a Magic Date. :(
Press any key to continue . . .
*/