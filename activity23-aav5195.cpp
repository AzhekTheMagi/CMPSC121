//Author:	  Anthony Vallin, aav5195, 17Nov2018 0800
//Class:      CMPSC 121
//Assignment: Activity 23
//File:       activity23-aav5195.cpp
//Purpose: 	  Array manipulation practice
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
// Sources of Logic assistance: Activity 23 worksheet

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	const int SIZE = 10;
	int nums[ SIZE ] = { 5, 4, 2, 7, 6, 8, 5, 2, 8, 14 };

	//Randomizes seed
	srand( ( unsigned )time( NULL ) );

	//#1 Square each number
	for ( int i = 0; i < SIZE; i++ )
		nums[ i ] = nums[ i ] * nums[ i ];

	//#2 Adds a random number between zero and 10 to each number
	for ( int i = 0; i < SIZE; i++ )
		nums[ i ] += ( rand() % 11 );

	//#3 Add to each number the number that follows in the 
	//array. Skip the last value in the array.
	for ( int i = 0; i < SIZE - 1; i++ )
		nums[ i ] += nums[ i + 1 ];

	//#4 Calculate the sum of all the numbers.
	int sum = 0;

	for ( int i = 0; i < SIZE; i++ )
		sum += nums[ i ];

	//#5 Display the largest number in the array
	int highest;

	highest = nums[ 0 ];
	for ( int i = 1; i < SIZE; i++ )
	{
		cout << nums[ i ] << endl;
		if ( nums[ i ] > highest )
		{
			highest = nums[ i ];
		}
	}

	cout << "Highest is: " << highest << endl;

	system( "pause" );
	return 0;
}