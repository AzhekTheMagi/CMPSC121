//Author:	  Anthony Vallin, aav5195, 08Oct2018 1700
//Class:      CMPSC 121
//Assignment: Activity 13
//File:       activity13-aav5195.cpp
//Purpose: 	  Display the average for games played & results of coin toss
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
// Sources of Logic assistance: Module 8, Lesson 1.

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
	const int MAX_GAMES = 10; //Max number of toss games
	double avgPayment = 0.0; //Average payment for all toss games
	double payment = 0.0;   //Payments for each toss game
	int counter; //Keeps track of flips per toss game
	int coin;   //Coin for heads (0) or tails (1) 
	
	//Assigns random generator start position.
	srand(( unsigned )time( NULL ));

	cout << right << fixed << setprecision( 2 );
	
	//Loop for total amount of toss games
	for ( int i = 0; i < MAX_GAMES; i++ )
	{
		counter = 0; //Resets counter after every toss game

		//Tracks coin result and resulting payment
		do
		{
			coin = rand() % 2; //Randomly generates a '0' for tails & a '1' for heads
			if ( coin == 0 )
			{
				counter++;
				cout << 'T';
			}
			else if ( coin == 1 )
			{
				counter++;
				payment = pow( 2, static_cast< double >( counter ));
				cout << 'H' << setw( 20 - counter ) << "You win $" << payment << endl;
				avgPayment += payment; //Temporarily holds total payment amount. Used for future average payment calculation
			}
		} while ( coin == 0 );
	}
	
	//Calculates average payment
	avgPayment /= static_cast< double >( MAX_GAMES );

	cout << "\nThe average payout was $" << avgPayment << endl;
	
	system( "pause" );
	return 0;
}