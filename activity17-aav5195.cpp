//Author:	  Anthony Vallin, aav5195, 26Oct2018 1900
//Class:      CMPSC 121
//Assignment: Activity 17
//File:       activity17-aav5195.cpp
//Purpose: 	  Display longest pole size in room
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
#include <cmath>
using namespace std;

//Function Prototypes
void usrInput( double &, double &, double & );
void calcPole( double, double, double );

int main()
{
	double length;
	double height;
	double width;

	usrInput( length, width, height );
	calcPole( length, width, height );

	system( "pause" );
	return 0;
}

//*****************************************************
// Requests user input for length, width, and height. *
//*****************************************************
void usrInput( double &_length, double &_width, double &_height )
{
	cout << "Enter length, width, and height: ";
	cin >> _length >> _width >> _height;

	cout << fixed << setprecision( 2 );
}

//****************************************************************
// Calculates longest pole that can fit in a prism shapped room. *
//****************************************************************
void calcPole( double _length, double _width, double _height )
{
	double pole;

	pole = sqrt( pow( _length, 2.0 ) + pow( _width, 2.0 ) + pow( _height, 2.0 ) );

	cout << '\n' << "The highest pole from lower corner end to upper end corner is "
		 << pole << endl;
}