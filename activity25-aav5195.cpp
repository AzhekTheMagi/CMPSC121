//Author:	  Anthony Vallin, aav5195, 20Nov2018 1800
//Class:      CMPSC 121
//Assignment: Activity 25
//File:       activity25-aav5195.cpp
//Purpose: 	  Fills vector with 5000 random numbers and displays various info regarding numbers in vector
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
// Sources of Logic assistance: Activity 25 shellsort zip file

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

// Function Prototypes
vector<int> numGenerator( int );
void printResults( int, int, int, int, int, int, int, double );
void evensOdds( const vector<int>&, int &, int & );
void shellSort( vector<int>& );
void swapper( int &, int & );
void usrPrmpt( int & );
double valueAvg( int, int );
int binarySearch( const vector<int>&, int, int );
int smallestNumber( const vector<int>& );
int largestNumber( const vector<int>&, int );
int totalValue( const vector<int>& );

int main()
{
	const int SIZE = 5000;       // Elements in Vector
	vector<int> nums1( SIZE );   // Holds 5000 random numbers
	double valueAverage; // Value average
	int position;        // Holds element position 
	int smallNum;        // Smallest number in vector
	int largeNum;        // Largest number in vector
	int oddTotal;        // Odd total
	int evenTotal;       // Even total
	int valueTotal;      // Value total
	int userInteger;     // Holds user integer input

	nums1 = numGenerator( SIZE ); // Populates vector w/ 5000 random numbers
	shellSort( nums1 );           // Sorts into ascending order

	smallNum = smallestNumber( nums1 );           // Assigns smallest number in Vector
	largeNum = largestNumber( nums1, SIZE );      // Assigns largest number in Vector
	evensOdds( nums1, oddTotal, evenTotal );      // Counts odds and evens in Vector
	valueTotal = totalValue( nums1 );             // Total value in Vector
	valueAverage = valueAvg( SIZE, valueTotal );  // Vector sum average

	usrPrmpt( userInteger );                              // Asks for user integer input
	position = binarySearch( nums1, SIZE, userInteger );  // Searches for user integer in vector

	printResults( smallNum, largeNum, evenTotal, oddTotal, valueTotal, 
		userInteger, position, valueAverage );

	system( "pause" );
	return 0;
}

//*********************************************************
// Populates vector with 5000 randomly generated numbers. *
//*********************************************************
vector<int> numGenerator( int n )
{
	vector<int> result;

	// Randomizes seed 
	srand( ( unsigned )time( NULL ) );

	// Randomly assigns a number from 1 to 100
	for ( int i = 0; i < n; i++ )
		result.push_back( rand() );

	return result;
}
//**********************************************************************
// Compares elements separated by a gap of several positions. Elements *
// sorted with multiple passeswith each pass reducing the gap.         *
//**********************************************************************
void shellSort( vector<int>& V )
{
	bool flag = true;
	int i, numLength = V.size();
	int d = numLength;

	while ( flag || ( d > 1 ) ) // bool flag 
	{
		flag = false;           //reset flag to 0 to check for
		d = ( d + 1 ) / 2;	    // future swaps
		for ( i = 0; i < ( numLength - d ); i++ )
		{
			if ( V[ i + d ] < V[ i ] )
			{
				swapper( V[ i ], V[ i + d ] );
				flag = true;    //tells swap has occurred
			}
		}
	}
}

//***************************
// Swaps two int arguments. *
//***************************
void swapper( int &a, int &b )
{
	int temp; 

	temp = a;
	a = b;
	b = temp;
}

//***************************
// Returns smallest number. *
//***************************
int smallestNumber( const vector<int>& v )
{
	return ( v[ 0 ] );
}

//**************************
// Returns largest number. *
//**************************
int largestNumber( const vector<int>& v, int size )
{
	int large = v[ size - 1 ];
	return large;
}

//***************************************************
// Counts total number of evens and odds in vector. *
//***************************************************
void evensOdds( const vector<int>& v, int& odds, int& evens )
{
	odds = 0;
	evens = 0;

	for ( size_t i = 0; i < v.size(); i++ )
	{
		if ( v[ i ] % 2 == 0 )
			evens++;
		else
			odds++;
	}
}

//******************************************
// Calculates sum of all values in vector. *
//******************************************
int totalValue( const vector<int>& v )
{
	int value = 0; // Total vector value

	for ( size_t i = 0; i < v.size(); i++ )
		value += v[ i ];

	return value;
}

//*******************************************************
// Caculates average of Vector sum with element number. *
//*******************************************************
double valueAvg( int size, int total )
{
	double avg;

	avg = total / static_cast< double >( size );

	return avg;
}

//******************************************
// Asks user for an integer to search for. *
//******************************************
void usrPrmpt( int & i )
{
	cout << "Enter an integer: ";
	cin >> i;
}

//*************************************************
// Searches for user specified integer in vector. *
//*************************************************
int binarySearch( const vector<int>& v, int size, int user )
{
	int first = 0;       // First array element
	int last = size - 1; // Last array element
	int middle;          // Midpoint of search
	int position = -1;   // Position of search value
	bool found = false;  // Flag

	while ( !found && first <= last )
	{
		middle = ( first + last ) / 2;   //Calculate midpoint
		if ( v[ middle ] == user ) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if ( v[ middle ] > user ) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;             // If value is in upper half
	}
	return position;
}

//************************************
// Displays results of vector facts. *
//************************************
void printResults( int small, int large, int even, int odd, int value, int usr,
	int position, double avg )
{
	cout << fixed << setprecision( 2 );
	cout << "The smallest number is " << small << '\n'
		 << "The largest number is "  << large << '\n'
		 << "The number of evens is " << even  << '\n'
		 << "The number of odds is "  << odd   << '\n'
		 << "The total of the values is "   << value << '\n'
		 << "The average of the values is " << avg   << '\n';

	if ( position == -1 )
		cout << usr << " was not found!" << endl;
	else
		cout << usr << " was found at position " << position << endl;
}