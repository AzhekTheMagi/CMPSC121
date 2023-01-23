//Author:	  Anthony Vallin, aav5195, 11Sep2018 1800
//Class:      CMPSC 121
//Lab:        Activity 07
//File:       activity07-aav5195.cpp
//Purpose: 	  Calculates a customer's monthly mobile bill  
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
#include <iomanip>
using namespace std;

int main()
{
	const double A_OVERAGE = 0.45;  //Plan A overage fee
	const double A_MONTHLY = 39.99; //Plan A monthly fee
	const double B_OVERAGE = 0.40;  //Plan B overage fee
	const double B_MONTHLY = 59.99; //Plan B monthly fee
	const double C_MONTHLY = 69.99; //Plan C monthly fee
	const int A_TOTALMIN = 450; //Plan A minutes covered
	const int B_TOTALMIN = 900; //Plan B minutes covered

	char plan;            //Mobile Data plan choices
	bool exitFlag = true; //Verifies input is valid
	int minutes;          //Total minutes used by user
	double totalPrice;    //Total bill owed by user

	//User input for package plan and minutes used
	cout << "Enter Plan Package A, B, or C and minutes: ";
	cin >> plan >> minutes;

	//Calculates total cost of mobile bill
	switch (plan)
	{
	    case 'a':
	    case 'A':
			if (minutes > A_TOTALMIN)
			    totalPrice = ((minutes - A_TOTALMIN) * A_OVERAGE) + A_MONTHLY;
		    else
			    totalPrice = A_MONTHLY;
		    break;

	    case 'b':
	    case 'B':
		    if (minutes > B_TOTALMIN)
			    totalPrice = ((minutes - B_TOTALMIN) * B_OVERAGE) + B_MONTHLY;
		    else
			    totalPrice = B_MONTHLY;
		    break;

	    case 'c':
	    case 'C':
		    totalPrice = C_MONTHLY;
		    break;

	    default:
		    cout << "Invalid choice selection. Restart program and try again." << endl;
			exitFlag = false;
	}

	//Validates user input prior to displaying invoice
	if (exitFlag)
		cout << "For Package " << plan << " with " << minutes 
			 << " minutes of usage, your total bill is $" 
		     << setprecision(2) << fixed << totalPrice << endl;

	system("pause");
	return 0;
}

/*Solution Example:
Enter Plan Package A, B, or C and minutes: A 700
For Package A with 700 minutes of usage, your total bill is $152.49
Press any key to continue . . .
---
Enter Plan Package A, B, or C and minutes: B 220
For Package B with 220 minutes of usage, your total bill is $59.99
Press any key to continue . . .
---
Enter Plan Package A, B, or C and minutes: C 1200
For Package C with 1200 minutes of usage, your total bill is $69.99
Press any key to continue . . .
*/