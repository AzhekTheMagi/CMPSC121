//Author:	  Anthony Vallin, aav5195, 05Nov2018 1800
//Class:      CMPSC 121
//Assignment: Activity 21
//File:       activity21-aav5195.cpp
//Purpose: 	  Uses a struct to enter Part Information and outputs to data file.
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
// Sources of Logic assistance: Program 11-6 & 11-7 from C++ From Control Structures through Objects

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct PartInformation
{
	string partNumber; //Part Number
	string partName;   //Part Name
	char partClass;    //Part Class
	int onhandBalance; //Units on hand
	double unitPrice;  //Unit price
};

//Function Prototype
PartInformation getInfo();
void printItem( fstream&, const PartInformation& );

int main()
{
	PartInformation part;
	fstream outputFile;
	char contPrgm;

	//Creates and opens file for writing
	outputFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Activities\\Activity 21\\partInfo.txt", ios::out );

	if ( outputFile )
	{
		do
		{
			//Gets information about part
			part = getInfo();
			//Prints part info to output file 
			printItem( outputFile, part );

			cout << "More parts? Y or N" << endl;
			cin >> contPrgm;

			//Clears left over junk in cin stream and resets flag
			cin.clear();
			cin.ignore( numeric_limits<streamsize>::max(), '\n' );

		} while ( toupper( contPrgm ) == 'Y' );
	}
	else
		cout << "File failed to open!" << endl;

	outputFile.close();

	system( "pause" );
	return 0;
}

//***************************************************
// Uses a local struct variable to fill in part     *
// information and returns data in struct instance. *
//***************************************************
PartInformation getInfo()
{
	PartInformation partInfo; //Temporary struct variable

	//Store part information in temp struct variable
	cout << "Enter part information: part number, name, class, onhand balance"
		 << " and price." << endl;
	getline( cin, partInfo.partNumber );
	getline( cin, partInfo.partName );
	cin >> partInfo.partClass >> partInfo.onhandBalance >> partInfo.unitPrice;

	//Clears left over junk in cin stream and resets flag
	cin.clear();
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );

	return partInfo;
}

//******************************************
// Writes part information to output file. *
//******************************************
void printItem( fstream& fileWrite, const PartInformation& partInfo )
{
	//Outputs partInfo struct instance to output file
	fileWrite << partInfo.partNumber << ' ' <<  partInfo.partName     << ' ' 
		      << partInfo.partClass  << ' ' << partInfo.onhandBalance << ' ' 
		      << partInfo.unitPrice  << '\n';
}