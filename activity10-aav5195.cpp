//Author:	  Anthony Vallin, aav5195, 24Sep2018 0900
//Class:      CMPSC 121
//Assignment: Activity 10
//File:       activity10-aav5195.cpp
//Purpose: 	  Displays day of the week  
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
	char continueProgram = 'y'; //Initial starting condition
	bool inputFailure;          //User validation flag
	int day;                    //Day of the week (1 to 7)
	
	do
	{
		cout << "Enter a day of week value: ";
		cin >> day;

		//Validates user input is between 1 to 7
		if (day > 0 && day < 8)
		{
			inputFailure = false;
			switch (day)
			{
			case 1:
				cout << "Sunday" << endl;
				break;
			case 2:
				cout << "Monday" << endl;
				break;
			case 3:
				cout << "Tuesday" << endl;
				break;
			case 4:
				cout << "Wednesday" << endl;
				break;
			case 5:
				cout << "Thursday" << endl;
				break;
			case 6:
				cout << "Friday" << endl;
				break;
			default:
				cout << "Saturday" << endl;
			}
		}
		else
		{
			inputFailure = true;
			cout << day << " is invalid." << endl;
		}

		//Prompts user to continue program
		if (!inputFailure)
		{
			cout << "Do you wish to continue (y or n)? ";
			cin >> continueProgram;
			cout << endl;
		}
	} while (continueProgram == 'y');

	cout << "Goodbye! Thank you for using our program!" << endl;

	system("pause");
	return 0;
}