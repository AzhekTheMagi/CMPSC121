//Author:	  Anthony Vallin, aav5195, 15Oct2018 1900
//Class:      CMPSC 121
//Assignment: Activity 16
//File:       activity16-aav5195.cpp
//Purpose: 	  Tracks account balance
/********************************************************************\
* Academic Integrity Affidavit:                                      *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *
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

//Function Prototypes
double calcBalance( double );
bool balanceCheck( double, double );
void userPrompt();
void exitPrompt();

int main()
{
	double balanceTotal = 0.0; //Account Balance total
	double transaction = 0.0; //Transaction amount
	char userExit;           //Loop exit

	cout << fixed << setprecision( 2 );

	do
	{
		//Prompts user for transaction amount
		userPrompt();
		cin >> transaction;

		if (  balanceCheck( transaction, balanceTotal ) )
		{
			balanceTotal = calcBalance(transaction);
			cout << "Current balance = " << balanceTotal << endl;
			exitPrompt();
			cin >> userExit;
		}
		else
			cout << "Impermissible withdrawal, insufficient funds!" << '\n';

		if ( userExit == 'N' )
			cout << "Final balance $ " << balanceTotal << endl;

	} while ( userExit == 'Y' );

	system( "pause" );
	return 0;
}

//*********************************************
// Displays user instructions for user input. *
//*********************************************
void userPrompt()
{
	cout << "Enter amount of transaction, positive for deposit, negative for withdrawal: ";
}

//******************************************
// Displays instructions for program exit. *
//******************************************
void exitPrompt()
{
	cout << "Do you have any more transactions? Y or N" << '\n';
}

//******************************
// Calculates account balance. *
//******************************
double calcBalance( double _transaction )
{
	static double accountBalance = 0.0;
	
	accountBalance += _transaction;
	return accountBalance;
}

//*************************************************
// Verifies user has enough funds for withdrawal. *
//*************************************************
bool balanceCheck( double _transaction, double _balance )
{
	double balanceTotal;
	bool kosherAccnt;

	balanceTotal = ( _transaction + _balance );
	
	if ( balanceTotal < 0 )
		kosherAccnt = false;
	else
		kosherAccnt = true;

	return kosherAccnt;
}