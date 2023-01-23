//Author:	  Anthony Vallin, aav5195, 27Nov2018 0940
//Class:      CMPSC 121
//Assignment: Lab 14
//File:       lab14-aav5195.cpp
//Purpose:    Reads part info for user from part list  
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
// Sources of Logic assistance: Lab 14 sheet

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct PartInfo
{
	string partNum;
	char partClass;
	int partQty;	
	double partPrice;
};

// Function Prototypes
void countByClass( const vector <PartInfo> &pVector, vector <int> &classCounts );
void displayCounts( const vector <int> &classCounts );
double costForClass( char classIn, const vector <PartInfo> &pVector );
double totalCost( const vector <PartInfo> &pVector );
string highestCost( const vector <PartInfo> &pVector );
string lowestCost( const vector <PartInfo> &pVector );
bool readFile( vector<PartInfo>& pVector );
int displayMenu();

int main()
{
	bool menuExit = false; // Menu exit flag
	char classChoice;      // Specific class
	int menuSelection;     // Menu selection
	vector<int> classCount( 6, 0 ); // Holds number of each class
	vector<PartInfo> partListing;   // Holds part listing info

	cout << fixed << setprecision( 2 ); // Number formatting

	if ( readFile( partListing ) )
	{
		do
		{
			menuSelection =	displayMenu(); // Displays menu
			cout << "Your choice was " << menuSelection << endl;
			
			switch ( menuSelection )
			{
				case 1 :
				    cout << "Total cost of inventory: " << '$'
					     << totalCost( partListing ) << endl;
					break;
				case 2 :
				    countByClass( partListing, classCount );
					displayCounts( classCount );
					break;
				case 3 :
				    cout << "Which class?" << endl;
					cin >> classChoice;
					cout << "Cost of inventory for class" << classChoice << '$'
					     << costForClass( classChoice, partListing ) << endl;
					break;
				case 4 :
				    cout << "The part with the highest cost of inventory is "
                         << highestCost( partListing ) << endl;
                    break;						 
				case 5 :
				    cout << "The part with the lowest cost of inventory is "
                         << lowestCost( partListing ) << endl;
                    break;	
				default:
				    menuExit = true;
			}
			cout << endl;
		} while( !menuExit );
	}
	else
		cout << "File read error!" << endl;
		
	system( "pause" );
	return 0;
}

//**********************************************************************
// Opens candidate file list and populates array with candidate names. *
//**********************************************************************
bool readFile( vector<PartInfo>& pVector )
{
	fstream inputFile; // Read file
	bool filesuccess;  // Error flag
	PartInfo parts;    // Holds part information

    //Opens candidate file
	inputFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Labs\\Lab14\\parts.txt" );

	if ( inputFile )
	{
		// Reads data into struct
		while ( inputFile >> parts.partNum >> parts.partClass >> parts.partQty
                          >> parts.partPrice )
		{
			pVector.push_back( parts ); // Assigns to struct vector
		}		  
		filesuccess = true;
	}
	else
		filesuccess = false;

	inputFile.close();  //Closes file

	return filesuccess;
}

//*****************
// Displays menu. *
//*****************
int displayMenu()
{
	int selection; // Menu choice

	// Displays menu
	cout << "   R E P O R T S  M E N U" << '\n';
	cout << "1. Total cost of inventory." << '\n'
	     << "2. A count of parts of each class." << '\n'
		 << "3. Cost of inventory for a class." << '\n'
		 << "4. Part with the highest cost of inventory" << '\n'
		 << "5. Part with lowest cost." << '\n'
		 << "6. Exit" << endl;

	cin >> selection; // User menu choice
	system( "cls" );  // Clears display menu

	return selection;
}

//*******************************************
// Calculates total cost of part inventory. *
//*******************************************
double totalCost(const vector <PartInfo> &pVector)
{
	double total = 0.00;  // Total inventory cost
	double inventoryCost; // Individual inventory cost
	
	// Calculates total cost of inventory.
	for ( size_t i = 0; i < pVector.size(); i++ )
	{
		inventoryCost = pVector[ i ].partQty * pVector[ i ].partPrice;
		total += inventoryCost;
	}
	
	return total;
}

//********************************
// Tracks each part class total. *
//********************************
void countByClass( const vector <PartInfo> & pVector, vector <int> &classCounts )
{
	for ( size_t i = 0; i < pVector.size(); i++ )
	{
		switch ( pVector[ i ].partClass )
		{
			case 'A' :
			    classCounts[ 0 ]++;
				break;
			case 'B' :
			    classCounts[ 1 ]++;
				break;
			case 'C' :
			    classCounts[ 2 ]++;
				break;
			case 'D' :
			    classCounts[ 3 ]++;
				break;
			case 'E' :
			    classCounts[ 4 ]++;
				break;
			default :
			    classCounts[ 5 ]++;
		}
	}
}

//******************************
// Displays part class counts. *
//******************************
void displayCounts( const vector <int> &classCounts )
{
	cout << "Count of parts by class:" << '\n'
	     << 'A' << setw( 5 ) << classCounts[ 0 ] << '\n'
	     << 'B' << setw( 5 ) << classCounts[ 1 ] << '\n'
	     << 'C' << setw( 5 ) << classCounts[ 2 ] << '\n'
	     << 'D' << setw( 5 ) << classCounts[ 3 ] << '\n'
	     << 'E' << setw( 5 ) << classCounts[ 4 ] << '\n'
	     << 'F' << setw( 5 ) << classCounts[ 5 ] << endl;		
}

//******************************************
// Calculates cost of specific part class. *
//******************************************
double costForClass( char classIn, const vector <PartInfo> &pVector )
{
	double inventoryTotal; // Holds total for specified inventory class
	double total = 0.00;   // Holds part class total
	
	for ( size_t i = 0; i < pVector.size(); i++ )
	{
		if ( pVector[ i ].partClass == classIn )
		{
			inventoryTotal = pVector[ i ].partQty * pVector[ i ].partPrice;
			total += inventoryTotal;
		}
	}
	
	return total;
}

//***********************************************
// Calculates part with highest inventory cost. *
//***********************************************
string highestCost( const vector <PartInfo> &pVector )
{
	string highest;  // Highest inventory part
	double highCost; // Highest inventory cost
    double lowCost;  // Lowest inventory cost

    highCost = pVector[ 0 ].partQty * pVector[ 0 ].partPrice;
	highest = pVector[ 0 ].partNum;
	
	for ( size_t i = 0; i < pVector.size(); i++ )
	{
		lowCost = pVector[ i ].partQty * pVector[ i ].partPrice;
		if ( highCost < lowCost )
		{
			highCost = lowCost;
			highest  = pVector[ i ].partNum;
		}
	}
	
	return highest;
}

//**********************************************
// Calculates part with lowest inventory cost. *
//**********************************************
string lowestCost( const vector <PartInfo> &pVector )
{
	string lowest;  // lowest inventory part
	double highCost; // Highest inventory cost
    double lowCost;  // Lowest inventory cost

    lowCost = pVector[ 0 ].partQty * pVector[ 0 ].partPrice;
	lowest = pVector[ 0 ].partNum;
	
	for ( size_t i = 0; i < pVector.size(); i++ )
	{
		highCost = pVector[ i ].partQty * pVector[ i ].partPrice;
		if ( lowCost > highCost )
		{
			lowCost = highCost;
			lowest  = pVector[ i ].partNum;
		}
	}
	
	return lowest;	
}