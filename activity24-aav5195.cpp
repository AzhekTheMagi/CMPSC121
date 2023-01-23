//Author:	  Anthony Vallin, aav5195, 17Nov2018 0946
//Class:      CMPSC 121
//Assignment: Activity 24
//File:       activity24-aav5195.cpp
//Purpose: 	  Fills parallel vectors with 500 random numbers between 1 and 100.
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
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

//Function Prototypes
vector<int> numGenerator( int ); 
int evenCounter( const vector<int> &, const vector<int> &, int );

int main()
{
	const int SIZE = 500; //Vector size
	vector<int> nums1( SIZE ); //Holds 500 random numbers 
	vector<int> nums2( SIZE ); //Holds 500 random numbers
	int evenTotal; //Holds even numbers from both vector positions

	//Randomizes seed 
	srand( ( unsigned )time( NULL ) );

	//Populates vectors with 500 Randomly generated numbers from 1 to 500
	nums1 = numGenerator( SIZE );
	nums2 = numGenerator( SIZE );

	//Counts even numbers from both vector elements
	evenTotal = evenCounter( nums1, nums2, SIZE );

	//Displays even count
	cout << "The Vectors contain " << evenTotal << " cells where both values are even." << endl;

	system( "pause" );
	return 0;
}

//**********************************************************************
// Populates vector with 500 randomly generated numbers from 1 to 100. *
//**********************************************************************
vector<int> numGenerator( int n )
{
	vector<int> result;

	//Randomly assigns a number from 1 to 100
	for ( int i = 0; i < n; i++ )
		result.push_back( ( rand() % 101 + 1 ) );

	return result;
}

//*********************************************************************************************
// Counts the amount of times an even number is found between two equavalent vector elements. *
//*********************************************************************************************
int evenCounter( const vector<int> &num1, const vector<int> &num2, int n )
{
	int counter = 0; //Holds even number count

	for ( int i = 0; i < n; i++ )
	{
		if ( num1[ i ] % 2 == 0 && num2[ i ] % 2 == 0 )
			counter++;
	}

	return counter;
}