//Author:	  Anthony Vallin, aav5195, 08Oct2018 1800
//Class:      CMPSC 121
//Assignment: Activity 14
//File:       activity14-aav5195.cpp
//Purpose: 	  Simulate dice roll
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
// Sources of Logic assistance: Module 8, Lesson 1, Random Numbers Part 2 &
// Starting Out w/ C++, program 3-26

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int MAX_VALUE = 6;
	const int MIN_VALUE = 1;
	int die1;
	int die2;
	
	//Assigns random generator start position.
	srand(( unsigned )time( NULL ));
	
	for ( int i = 0; i < 10; i++ )
	{
		//Generates random number (1 through 6) for each die. Code from program 3-26
		//located in text book Starting Out w/ C++ 8th edition
		die1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		die2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

		cout << "  " << (die1 + die2) << endl;
	}

	
	system( "pause" );
	return 0;
}