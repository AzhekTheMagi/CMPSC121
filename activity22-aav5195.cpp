//Author:	  Anthony Vallin, aav5195, 05Nov2018 2130
//Class:      CMPSC 121
//Assignment: Activity 22
//File:       activity22-aav5195.cpp
//Purpose: 	  Assigns and prints random numbers to an array 
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
#include <ctime>
using namespace std;

//Function Prototype
void showValues( const int [], int );

int main()
{
	const int SIZE = 50;
	int numbers[ SIZE ];

	//Randomizes seed 
	srand( ( unsigned )time( NULL ) );

	//Assigns random numbers to 50 element array
	for ( int i = 0; i < SIZE; i++ )
		numbers[ i ] = rand();
	
	//Displays Array contents
	showValues( numbers, SIZE );

	system( "pause" );
	return 0;
}

//******************************
// Displays contents of array. *
//******************************
void showValues( const int num[], int size )
{
	const int COLUMN = 10; //Column formatting
	int counter = 1;       //New line formatting counter

	for ( int index = 0; index < size; index++ )
	{
		cout << num[ index ] << ' ';

		//Inserts newline for new row
		if ( counter % COLUMN == 0 )
			cout << endl;

		counter++;
	}
}