//Author:	  Anthony Vallin, aav5195, 17Nov2018 1100
//Class:      CMPSC 121
//Assignment: Lab 13
//File:       lab13-aav5195.cpp
//Purpose: 	Read candidate file list and generate a random vote total. Displays results.  
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
// Sources of Logic assistance: Program 3-26 from "C++ From Control Structures through Objects 8e"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

//Function Prototypes
bool readFile( string c[], int &size );
void getVotes( int v[], int size );
void calculatePercents( int v[], double p[], int size );
void displayResults( string c[], int v[], double p[], int size );

int main()
{
	const int CAPACITY = 25; //Size of array

	string candidates[ CAPACITY ]; //Holds candidate names
	double percents[ CAPACITY ];  //Holds candidate vote percentage
	int votes[ CAPACITY ];       //Holds vote total
	int size;

	size = CAPACITY; //Assigns initial array size 

	if ( readFile( candidates, size ) )
	{
		getVotes( votes, size ); //Populates votes and assigns real size of array
		calculatePercents( votes, percents, size ); //Calculates vote percentages
		displayResults( candidates, votes, percents, size );
	}
	else
		cout << "File read error" << endl;

	system( "pause" );
	return 0;
}

//**********************************************************************
// Opens candidate file list and populates array with candidate names. *
//**********************************************************************
bool readFile( string c[], int &size )
{
	fstream inputFile; //Read file
	bool filesuccess; //Error flag
	int counter = 0; //Holds # of names

    //Opens candidate file
	inputFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Labs\\Lab13\\candidates.txt" );

	if ( inputFile )
	{
		while ( inputFile >> c[ counter ] ) //Assigns name to each element
			counter++;
		filesuccess = true;
	}
	else
		filesuccess = false;

	//Closes file
	inputFile.close();

	//Assigns number of elements in array
	size = counter;

	return filesuccess;
}

//*********************************************************************
// Randomly generates numbers from 1500 to 25000 to fill votes array. *
//*********************************************************************
void getVotes( int v[], int size )
{
	const int MIN_VALUE = 1500;  //Min vote total
	const int MAX_VALUE = 25000; //Max vote total

	srand( ( unsigned )time( NULL ) ); //Randomizes seed

	//Assigns random number from MIN_VALUE to MAX_VALUE
	for ( int i = 0; i < size; i++ )
		v[ i ] = ( rand() % ( MAX_VALUE - MIN_VALUE + 1 ) ) + MIN_VALUE;
}

//******************************
// Calculates vote percentage. *
//******************************
void calculatePercents( int v[], double p[], int size )
{
	int voteTotal = 0; //Vote total

	//Calculates vote total
	for ( int i = 0; i < size; i++ )
		voteTotal += v[ i ];

	//Calculates percentage per element
	for ( int i = 0; i < size; i++ )
		p[ i ] = ( v[ i ] / static_cast< double >( voteTotal ) ) * 100;
}

//**********************************************************
// Prints candidates, their votes, and percentage results. *
//**********************************************************
void displayResults( string c[], int v[], double p[], int size )
{
	int highest; //Holds largest vote total
	string candidateWinner; //Holds candidate winner

	//Sets up formatting
	cout << left << setprecision( 2 );
	cout << setw( 16 ) << "Candidate" << setw( 10 ) << "Votes" << "Percent" << '\n';

	//Displays results of "election"
	for ( int i = 0; i < size; i++ )
		cout << setw( 16 ) << c[ i ] << setw( 10 ) << v[ i ] << p[ i ] << '%' << '\n';

	highest = v[ 0 ]; //Initial element votes
	candidateWinner = c[ 0 ]; //Initial candidate

	//Determines candidate winner and winning vote total
	for ( int i = 1; i < size; i++ )
	{
		if ( v[ i ] > highest )
		{
			highest = v[ i ];
			candidateWinner = c[ i ];
		}
	}

	cout << "The winner is " << candidateWinner << " with " << highest << " votes!" << endl;
}