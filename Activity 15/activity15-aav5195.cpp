//Author:	  Anthony Vallin, aav5195, 08Oct2018 1900
//Class:      CMPSC 121
//Assignment: Activity 15
//File:       activity15-aav5195.cpp
//Purpose: 	  Calculates user item total
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
void calculateCost( int, double );

int main()
{
	char sentinel;     //Program exit sentinel
	double itemPrice; //Price of items entered by user
	int itemsSold;   //Number of items sold
	
	cout << fixed << setprecision( 2 );
	
	do
	{
		cout << "Enter number of items and cost: ";
		cin >> itemsSold >> itemPrice;
		
		calculateCost( itemsSold, itemPrice );
		
		cout << "Do you have another purchase to enter? Y or N\n";
		cin >> sentinel;
		
	} while ( sentinel == 'Y' );
	
	cout << "Thank you" << endl;
	
	system( "pause" );
	return 0;
}

//*****************************************
// Calculates the cost of the total items *
//*****************************************
void calculateCost( int items, double price )
{
	cout << "The extended amount is $" << ( items * price ) << endl;
}	