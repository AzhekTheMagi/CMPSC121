//Author:	  Anthony Vallin, aav5195, 08Oct2018 2020
//Class:      CMPSC 121
//Assignment: Lab08
//File:       lab08-aav5195.cpp
//Purpose: 	  Calculates batting statistics
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
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
int getHits( int, int, int, int );
double getAvg( int, int );

//Maximum number of at bats 
const int MAX_AT_BATS = 1000;

int main()
{
	int outs, singles, walks, doubles, triples, homeRuns;
	int hits = 0; //Total number of hits
	int atBat;   //Holds random generated number
	char sentinel; //Menu exit flag
	double battingAvg = 0.0; //Batting Average
	
	//Assigns random generator start position.
	srand( ( unsigned )time( NULL ) );
	
	do
	{
		//Initializes to zero for each iteration of batting computation
		outs = 0;
		walks = 0;
		singles = 0;
		doubles = 0;
		triples = 0;
		homeRuns = 0;

		//Accumulates amount of times player struck out, hit a single, double, 
		//triple, home run, or was walked.
		for ( int i = 0; i < MAX_AT_BATS; i++ )
		{
			//Randomizes number from 0 to 1000;
			atBat = rand() % 1001;
			
			//Determines what happened when player was at bat. Ranges are based
			//on predetermined percentages: (58% for out, 9.7% for walk,
            //22% for single, 6.1% for double, 2.5% for triple, & 1.7% for home run.			
			if ( atBat < 580 )
				outs++;
			else if ( atBat > 580 && atBat < 800 )
				singles++;
			else if ( atBat > 800 && atBat < 897 )
				walks++;
			else if ( atBat > 897 && atBat < 958 )
				doubles++;
			else if ( atBat > 958 && atBat < 983 )
				triples++;
			else
				homeRuns++;
		}
		
		//Calculates total hits & batting average
		hits = getHits( singles, doubles, triples, homeRuns );
		battingAvg = getAvg( hits, walks );
		
		//Prints batting stats of player
		cout << left << fixed << setprecision( 1 );
		cout << setw( 16 ) << "Outs"  << outs  << '\n'
		     << setw( 16 ) << "Walks" << walks << '\n'
			 << setw( 16 ) << "Singles" << singles << '\n'
			 << setw( 16 ) << "Doubles" << doubles << '\n'
			 << setw( 16 ) << "Triples" << triples << '\n'
			 << setw( 16 ) << "Home Runs" << homeRuns << '\n'
			 << setw( 16 ) << "Batting Avg" << battingAvg << '\n'
			 << setw( 16 ) << "Hits" << hits << endl;
		
		cout << "Do you wish to continue? Y or N\n";
		cin >> sentinel;
		
	} while ( sentinel == 'Y' );
	
	system( "pause" );
	return 0;
}

//****************************************************************************
// Calculates total hits (singles, doubles, triples, & home runs) by player. *
//****************************************************************************
int getHits( int _single, int _double, int _triple, int _homeRun )
{
	return ( _single + _double + _triple + _homeRun );	
}

//****************************************
// Calculates batting average of player. *
//****************************************
double getAvg( int _hits, int _walks )
{
	return ( _hits / static_cast< double >( MAX_AT_BATS - _walks ) );
}

/*Example Solution:
Outs            572
Walks           96
Singles         237
Doubles         53
Triples         20
Home Runs       22
Batting Avg     0.4
Hits            332
Do you wish to continue? Y or N
Y
Outs            586
Walks           85
Singles         215
Doubles         65
Triples         26
Home Runs       23
Batting Avg     0.4
Hits            329
Do you wish to continue? Y or N
Y
Outs            572
Walks           75
Singles         231
Doubles         67
Triples         33
Home Runs       22
Batting Avg     0.4
Hits            353
Do you wish to continue? Y or N
N
Press any key to continue . . .
*/




