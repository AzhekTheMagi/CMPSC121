//Author:	  Anthony Vallin, aav5195, 26Oct2018 2000
//Class:      CMPSC 121
//Assignment: Activity 18
//File:       activity18-aav5195.cpp
//Purpose: 	  Capitalizes full name and rearranges name to Last, First MI format.
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
#include <string>
#include <limits>
using namespace std;

//Function Prototypes
string usrInput();
string capitalizeName( string );
void printName( string, string );

int main()
{
	string name;       //Original Name input: First MI. Last
	string revisedName; //Revised Name input: Last, First MI.
	char contPrgm; //Program Exit Sentinel

	do
	{
		name = usrInput();
		revisedName = capitalizeName( name );
		printName( name, revisedName );
		
		cout << "Do you wish to continue? Y or N " << '\n';
		cin >> contPrgm;

		//Clears left over junk in cin stream and resets flag
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while ( contPrgm == 'Y' );

	system( "pause" );
	return 0;
}

//**********************************************************
// Asks user to enter name: First, Middle Initial, & Last. *
//**********************************************************
string usrInput()
{
	string _name;

	cout << "Enter a name first mi last: ";
	getline( cin, _name );

	return _name;
}

//*********************************************************
// Capitalizes First name, Middle initial, and last name. *
// Also revises name order to Last Name, First Name MI.   *
//*********************************************************
string capitalizeName( string _name )
{
	string firstName;
	string lastName;
	int nameSort;

	//Separates last name from first name and middle initial
	nameSort = _name.find( '.' );
	firstName = _name.substr( 0, nameSort + 1 );
	lastName = _name.substr( nameSort + 2 );
	
	//Capitalizes first and last names
	firstName[ 0 ] = toupper( firstName[ 0 ] );
	lastName[ 0 ] = toupper( lastName[ 0 ] );

	//Finds and capitalizes middle initial
	for ( int i = 0; i < firstName.length(); i++ )
	{
		if ( isspace( firstName[ i ] ) )
			firstName[ i + 1 ] = toupper( firstName[ i + 1 ] );
	}

	//Adds comma after last name
	lastName.resize( ( lastName.length() + 1 ), ',' );

	return (lastName + ' ' + firstName);
}

//*****************************************************
// Displays last name, first name and middle initial. *
//*****************************************************
void printName( string _name, string _revisedName )
{
	cout << "You entered: " << _name << '.'
		 << " It was converted to: " 
		 << _revisedName << endl;
}