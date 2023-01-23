//Author:	  Anthony Vallin, aav5195, 03Nov2018 1630
//Class:      CMPSC 121
//Assignment: Activity 19
//File:       activity19-aav5195.cpp
//Purpose: 	  CCalculates area of triangle using two different formulas
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
#include <ctime>
using namespace std;

//Function Prototypes
void printPrmpt( double&, double& );
void printPrmpt( double&, double&, double& );
void triangleArea( double, double );
void triangleArea( double, double, double );


int main()
{
	char contPrgm;      //Program sentinel
	int randomQuestion; //Randomizes question number
	double height; //Height of triangle
	double base;   //Base of triangle
	double sideX;  //Side of triangle
	double sideY;  //Side of triangle 
	double sideH;  //Side of triangle

	//Randomizes seed 
	srand(( unsigned )time( NULL ));

	cout << fixed << setprecision( 2 );

	do
	{
		//Assigns either a random 0 or 1
		randomQuestion = rand() % 2;

		//Random '0' is assigned base/height triangle prompt 
		if ( randomQuestion == 0 )
		{
			printPrmpt( base, height );
			triangleArea( base, height );
		}
		else
		{
			printPrmpt( sideX, sideY, sideH );
			triangleArea( sideX, sideY, sideH );
		}

		cout << "Do you wish to continue? Y or N " << '\n';
		cin >> contPrgm;

	} while ( toupper( contPrgm ) == 'Y' );

	system( "pause" );
	return 0;
}

//************************************************
// Requests user enter triangle base and height. *
//************************************************
void printPrmpt( double& b, double& h )
{
	cout << "Enter base and height of a triangle." << endl;
	cin >> b >> h;
}

//*****************************************************
// Requests user enter three lengths of the triangle. *
//*****************************************************
void printPrmpt(double& x, double& y, double& h)
{
	cout << "Enter the lengths of the sides of a triangle." << endl;
	cin >> x >> y >> h;
}

//***************************************************
// Prints area of a triangle using base and height. *
//***************************************************
void triangleArea( double x, double y)
{
	double area;

	area = ( 1.0 / 2.0 ) * x * y;
	cout << "The area is " << area << endl;
}

//**********************************************
// Prints Heron's Area formula for a triangle. *
//**********************************************
void triangleArea( double x, double y, double h )
{
	double perimeter;
	double area;

	//Calculates area of a triangle using Heron's Area formula
	perimeter = ( x + y + h ) / 2.0;
	area = sqrt( perimeter * ( perimeter - x ) * ( perimeter - y ) * ( perimeter - h ) );

	cout << "The area is " << area << endl;
}

/*Solution Examples:
Enter the lengths of the sides of a triangle.
18 30 24
The area is 216.00
Do you wish to continue? Y or N
y
Enter base and height of a triangle.
24 18
The area is 216.00
Do you wish to continue? Y or N
y
Enter the lengths of the sides of a triangle.
20 28 34
The area is 279.91
Do you wish to continue? Y or N
n
Press any key to continue . . .
*/