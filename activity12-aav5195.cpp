//Author:	  Anthony Vallin, aav5195, 07Oct2018 0700
//Class:      CMPSC 121
//Assignment: Activity 12
//File:       activity12-aav5195.cpp
//Purpose: 	  Break down number until int one is produced
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
// Sources of Logic assistance: Activity 12 instructions

#include <iostream>
using namespace std;

//Function prototype
void ulamSequence( int num1 );

int main()
{
	int usrNum; //User int input
	
	//User Input for int variable
	do
	{
		cout << "Enter a number greater than or equal to 2: ";
		cin >> usrNum;
	} while ( usrNum < 2 );
	
	ulamSequence( usrNum );
	
	system("pause");
	return 0;
}

//********************************************************
// Breaks down number until an integer of 1 is produced. *
//********************************************************
void ulamSequence( int num1 )
{
	//Breaks down number until 1 is produced
	while( num1 > 1 )
	{
		if (( num1 % 2) == 0 )
			num1 /= 2;
		else
		{
			num1 *= 3;
			num1++;
		}
	}
	
	cout << "Your number broke down to " << num1 << endl;
}