//Author:	  Anthony Vallin, aav5195, 03Nov2018 1630
//Class:      CMPSC 121
//Assignment: Activity 20
//File:       activity20-aav5195.cpp
//Purpose: 	  Reverses a string 
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
// Sources of Logic assistance: Program 20-4 (C++ From Control Structures through Objects)

#include <iostream>
#include <string>
using namespace std;

//Function Prototype
void reverse( string, size_t );

int main()
{
	string phrase;

	cout << "Enter a string: " << endl;
	getline( cin, phrase );

	reverse( phrase, phrase.length() );

	system( "pause" );
	return 0;
}

//*************************************
// Reverses a string using recursion. *
//*************************************
void reverse( string s, size_t index )
{
	// Recursive case: Takes last character of string and
	// displays it first. Each recursion counts down until
	// base case met.
	if ( index <= s.length() )
	{
		cout << s[index];
		reverse( s, index - 1 ); 
	}
	//Base case
	else
	{
		index = 0;
		cout << endl;
	}
}