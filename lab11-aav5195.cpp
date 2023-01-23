//Author:	  Anthony Vallin, aav5195, 03Nov2018 2000
//Class:      CMPSC 121
//Assignment: Lab 11
//File:       lab11-aav5195.cpp
//Purpose: 	  Reformats data from an old file 
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
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//Function Prototypes


int main()
{
    fstream inputFile;
	ofstream outputFile;
	bool fileSuccess = true;
	string inputData;
	string outputData;

	//Opens Mega Industry obsolete system file and updated replacement file.
	inputFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Labs\\Lab11\\badnames.txt" );
	outputFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Labs\\Lab11\\goodnames.txt" );

	//Initiates if file opens successfully
	if ( inputFile && outputFile )
	{
		while ( getline( inputFile, inputData, '\n' ) )
		{

		}
	}
	else
	{
		cout << "Unable to open File!" << endl;
		fileSuccess = false;
	}

	inputFile.close();
	outputFile.close();

	system( "pause" );
	return 0;
}

//*************************************************
// Reformats and capitalizes first and last name. *
//*************************************************
string fixName( string n )
{
	string firstName; //Temp holds first name
	string lastName;  //Temp holds last name
	string fullName;  //Full name (last,first)
	size_t position;  //Temp position locations

	fullName = n;   //Keeps names only and discards the rest
	position = fullName.find( ' ' ); //Finds white space location between first & last name
	firstName = fullName.substr( 0, position ); //Assigns beginning characters up until white space as first name 
	fullName.erase( 0, position +1 ); //Deletes first name from string
	lastName = fullName; //Remaining characters assigned as last name

	firstName[ 0 ] = toupper( firstName[ 0 ] ); //Capitalizes first name
	lastName[ 0 ] = toupper( lastName[ 0 ] );    //Capitalizes last name
	fullName = lastName + ',' + firstName + ','; //Reformats to last name, first name

	return fullName;
}

//*********************************************************
// Formats social security number with dashes ###-##-#### *
//*********************************************************
string fixSSN( string ss )
{
	string ssn; //Social Security Number w/out octothorpe

	ssn = ss; //Removes octothorpe
	ssn.insert( 3, 1, '-' ); 
	ssn.insert( 6, 1, '-' );
	ssn += ',';

	return ssn;
}

//********************************
// Formats phone to ###-###-#### *
//********************************
string fixPhone( string ph )
{
	string phone; //Phone w/out octothorpe

	phone = ph; //Removes octothorpe
	phone.insert( 3, 1, '-' );
	phone.insert( 7, 1, '-' );

	phone += ',';

	return phone;
}

//****************************
// Capitalizes street names. *
//****************************
string fixAddress( string addr )
{
	string address;

	address = addr;

	for ( size_t i = 0; i < address.length (); i++ )
	{
		if ( address[ i ] == ' ' )
			address[ i + 1 ] = toupper( address[ i + 1 ] );
	}

	address += ',';

	return address;
}

//*************************
// Capitalizes city name. *
//*************************
string fixCity( string cty )
{
	string city;
	
	city = cty;
	city[ 0 ] = toupper( city[ 0 ] );
	city += ',';
	
	return city;
}

//******************************
// Capitalizes state initials. *
//******************************
string fixState( string st )
{
	string state;

	state = st;
	state[ 0 ] = toupper( state[ 0 ] );
	state[ 1 ] = toupper ( state[ 1 ] );
	state += ',';

	return state;
}