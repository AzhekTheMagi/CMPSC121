//Author:	  Anthony Vallin, aav5195, 278ov2018 0910
//Class:      CMPSC 121
//Assignment: Project 03
//File:       project03-aav5195.cpp
//Purpose: Searches for parts from list or adds them to file if not found. 
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
// Sources of Logic assistance: Module 14, "C++ From Control Structures through
// Objects" section 17.2

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Struct
struct Parts
{
	string number;
	char clss;
	int qty;	
	double price;
};

// Templated swap function - Swaps two items in a vector of any type
template <class CType>
void swapper( CType& a, CType& b )
{
	CType temp;
	temp = a;
	a = b;
	b = temp;
}

// Function Prototypes
string get_target();
bool get_data( vector<Parts>& pVector );
bool get_more_data( Parts& add, string key ); 
int bin_search( string key, const vector<Parts>& pVector);
void print_stats( int good, int bad );
void shell_sort( vector<Parts>& pVector );
void put_data( const vector<Parts>& pVector );
void display( const vector<Parts>& pVector, int finder );
void insert_data( vector<Parts>& pVector, const Parts& addPart );

// Main
int main()
{
	vector<Parts> partInfo; // Part data struct vector
	string partNum;         // Holds part number
	Parts add_Part;         // Holds user part number inputs
	char menuExit;          // Menu exit
	int notFound = 0;       // Counter for unsuccessfull searches
	int found = 0;          // Counter for successfull searches
	int position;           // Binary search position
	
	if ( get_data( partInfo ) ) // If successful file opening & vector fill
	{
		shell_sort( partInfo ); // Sorts Vector using shell sort method
		do
		{
			partNum = get_target();                       // Gets Part#
			position = bin_search( partNum, partInfo );   // Searches for Part#
			if ( position == -1 )                         // If part search unsuccessful
			{
				if ( get_more_data( add_Part, partNum ) ) // Gathers new part data
					insert_data( partInfo, add_Part );
				notFound++;                               // Unsuccessfull search counter
			}
			else
			{
				display( partInfo, position ); // Displays pre-existing part info
				found++;                       // Counter for successfull search
			}
			cout << "Would you like to do another search? < Y or N >" << '\n';
			cin >> menuExit;
		} while ( toupper( menuExit ) != 'N' );
	}
	else
		cout << "File read failed!" << endl;
	
	print_stats( found, notFound ); // Prints search results
	put_data( partInfo );           // Writes to file
	
	system( "pause" );
	return 0;
}

//**************************************************************
// Opens file so that contents are written to a struct vector. *
//**************************************************************
bool get_data( vector<Parts>& pVector )
{
	fstream inputFile; // Read file
	bool filesuccess;  // Error flag
	Parts partIn;      // Holds part information

    //Opens parts file
	inputFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Project03\\parts.txt" );

	if ( inputFile )
	{
		// Reads data from file into vector struct
		while ( inputFile >> partIn.number >> partIn.clss >> partIn.qty
                          >> partIn.price )
		{
			pVector.push_back( partIn ); // Assigns to struct vector
		}		  
		filesuccess = true;
	}
	else
		filesuccess = false;

	inputFile.close();  //Closes file

	return filesuccess;
}

//******************************************************************************
// Sorts parts list using Shell sort. Code adapted and modified from CMPSC 121 *
// module 14 Shell Sort S2015.docx                                             *
//******************************************************************************
void shell_sort( vector<Parts>& pVector )
{
	bool flag = true;
	int i, numLength = pVector.size();
	int d = numLength;

	while ( flag || ( d > 1 ) ) // bool flag 
	{
		flag = false;           //reset flag to 0 to check for
		d = ( d + 1 ) / 2;	    // future swaps
		for ( i = 0; i < ( numLength - d ); i++ )
		{
			if ( pVector[ i + d ].number < pVector[ i ].number )
			{
				swapper( pVector[ i ].number, pVector[ i + d ].number );
				swapper( pVector[ i ].clss, pVector[ i + d ].clss );
				swapper( pVector[ i ].qty, pVector[ i + d ].qty );
				swapper( pVector[ i ].price, pVector[ i + d ].price );
				flag = true;    //tells swap has occurred
			}
		}
	}
}

//*********************************************************
// Asks user for a part number to search for in the file. *
//*********************************************************
string get_target()
{
	string partNumber; // Holds part number
	
	cout << "What part number would you like to search for?" << endl;
	cin >> partNumber; // Part number string is continuous. Getline not needed.
	
	return partNumber;
}

//*********************************************
// Does a binary search based on part number. *
//*********************************************
int bin_search( string key, const vector<Parts>& pVector)
{
	int first = 0;                 // First vector element
	int last = pVector.size() - 1; // Last vector element
	int middle;                    // Midpoint of search
	int position = -1;             // Position of search value
	bool found = false;            // Flag

	while ( !found && first <= last )
	{
		middle = ( first + last ) / 2;         //Calculate midpoint
		if ( pVector[ middle ].number == key ) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if ( pVector[ middle ].number > key ) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;                    // If value is in upper half
	}
	return position;
}

//********************************
// Displays info on part number. *
//********************************
void display( const vector<Parts>& pVector, int finder )
{
	double total; // Holds inventory total cost
	
	// Calculates total price of inventory for part number
	total = pVector[ finder ].qty * pVector[ finder ].price;
	
	// Displays Part information
	cout << fixed << setprecision( 2 );
	cout << "There are " << pVector[ finder ].qty << " of Part Number "
	     << pVector[ finder ].number << " in inventory. It is a class "
		 << pVector[ finder ].clss   << " part. The cost is $"
		 << pVector[ finder ].price  << ". The value of that inventory is $"
		 << total << '.' << endl;
}

//********************************************
// Gets remaining info to add a part number. *
//********************************************
bool get_more_data( Parts& add, string key )
{
	bool add_part = false; // User selection flag
	char part;             // User choice 
	
	cout << "Add this part? ";
	cin >> part;
	part = toupper( part );
	
	if ( part == 'Y' )
	{
		add.number = key;
		cout << "What class is this part number in?" << '\n';
		cin >> add.clss;
		cout << "What is the on hand balance of this part?" << '\n';
		cin >> add.qty;
		cout << "What is the cost of this part?" << '\n';
		cin >> add.price;
		add.clss = toupper( add.clss );
		add_part = true;
	}

	return add_part;
}

//************************************************************
// Inserts part number data into vectors at proper location. *
//************************************************************
void insert_data( vector<Parts>& pVector, const Parts& addPart )
{
	int first = 0;                 // First vector element
	int last = pVector.size() - 1; // Last vector element
	int middle;                    // Midpoint of search
	bool inposition = false;       // Correct position flag
    vector<Parts>::iterator iter = pVector.begin(); // Iterator to point to element vector

	while ( !inposition && first <= last )
	{
		middle = ( first + last ) / 2;                       // Calculate midpoint
		if ( pVector[ middle ].number < addPart.number &&    // Determines if value is between specified elements
		     pVector[ middle + 1 ].number > addPart.number ) 
		{
			inposition = true;
			pVector.insert( ( iter + middle + 1 ), addPart ); // Inserts part info into vector
		}
		else if ( addPart.number < pVector[ 0 ].number )
		{
			inposition = true;
			pVector.insert( iter, addPart );                  // Inserts part info into first element
		}
		else if ( pVector[ middle ].number > addPart.number ) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;                               // If value is in upper half
	}
}

//***********************
// Prints search stats. *
//***********************
void print_stats( int good, int bad )
{
	int total; // Total searches conducted
	
	total = good + bad; // Calculates total searches conducted
	//Displays stats
	cout << "There were " << total << " searches performed today." << '\n'
	     << good << " of them were successfull." << '\n'
		 << bad  << " of them were not in the system." << '\n';
}

//*************************************************************************
// Writes out file when program ends so that additions are saved to file. *
//*************************************************************************
void put_data( const vector<Parts>& pVector )
{
	ofstream writeFile; // Write File
	
	// Opens file for data write
	writeFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Project03\\parts.txt" );
	
	if ( writeFile )
	{
		writeFile << left << fixed << setprecision( 2 );
		for ( size_t i = 0; i < pVector.size(); i++ )
		{
			writeFile << pVector[ i ].number << ' ' << pVector[ i ].clss << ' '
			          << setw( 4 ) << pVector[ i ].qty << ' ' 
				      << pVector[ i ].price << endl;
		}
	}
    else
		cout << "Failed to write data to file!" << endl;

	writeFile.close();
}