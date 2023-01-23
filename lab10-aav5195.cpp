//Author:	  Anthony Vallin, aav5195, 27Oct2018 1300
//Class:      CMPSC 121
//Assignment: Lab 10
//File:       lab10-aav5195.cpp
//Purpose: 	  Calculates the cost of lumber.
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
// Sources of Logic assistance: Lab Experiment 10 Instruction sheet

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double INCHESINLINEARFOOT = 12.0;
const double INCHESINONESQUAREFOOT = 144.0;
const double PINECOST = 0.89;
const double FIRCOST = 1.09;
const double CEDARCOST = 2.26;
const double MAPLECOST = 4.40;
const double OAKCOST = 3.10;

bool validateType( char t );
double calcBoardFeet( double th, double wid, double len );
double calcCost( char type, int numP, double bf );
string getTypeName( char type);
void getData( char & woodType, int & numPieces, double &thickness,
	          double & width, double & length );

// Get data on sale
int main()
{
	char woodType, reply;
	int numPieces;
	double thickness, width, length;
	double cost, totalCost, boardFeet;
	string woodTypeName;

	cout << fixed << setprecision( 2 );

	do
	{
		totalCost = 0;
		do
		{
			getData(woodType, numPieces, thickness, width, length);
			if ((toupper(woodType)) != 'T')
			{
				boardFeet = calcBoardFeet(thickness, width, length);
				cost = calcCost(woodType, numPieces, boardFeet);
				woodTypeName = getTypeName(woodType) + ", cost: $";
				cout << setw(3) << numPieces << setw(6) << thickness
					<< " X " << setw(6) << width << " X " << setw(6)
					<< length << " " << setw(14)
					<< woodTypeName << cost << endl;
				totalCost += cost;
			}
		} while (toupper(woodType) != 'T');
		cout << "Total cost: $" << totalCost << endl;
		cout << "More purchases?" << endl;
		cin >> reply;
	} while (toupper(reply) == 'Y');

}

//***************************
// Acquires data from sale. *
//***************************
void getData( char &woodType, int &numPieces, double &thickness,
	          double &width, double &length )
{
	cout << "Enter item: ";

	do
	{
		cin >> woodType;
	} while( !validateType( woodType ) );

	if ( (toupper( woodType ) ) != 'T' )
	{
		cout << "Enter number of pieces and thickness width and length" << '\n';
		cin >> numPieces >> thickness >> width >> length;
	}
}

//*************************************************
// Returns true if t represents a valid wood type *
// or false otherwise.                            *
//*************************************************
bool validateType(char t)
{
	bool isKosher;

	switch ( ( toupper( t ) ) )
	{
		case 'P':
		case 'F':
		case 'C':
		case 'M':
		case 'O':
		case 'T':
			isKosher = true;
			break;
		default:
			cout << t << " is not a valid type! Re-enter: ";
			isKosher = false;
	}

	return isKosher;
}

//*************************
// Calculates board feet. *
//*************************
double calcBoardFeet( double th, double wid, double len )
{
	double boardFeet; //Board Feet

	//Calculates board feet
	boardFeet = (th * wid * len) / INCHESINLINEARFOOT;

	return boardFeet;
}

//************************************************
// Calculate cost based on type number of pieces *
// and board feet.                               *
//************************************************
double calcCost( char type, int numP, double bf )
{
	double _price;
	double _cost;

	if ( toupper( type ) == 'P' )
		_price = PINECOST;
	else if ( toupper( type ) == 'F' )
		_price = FIRCOST;
	else if ( toupper( type ) == 'C' )
		_price = CEDARCOST;
	else if ( toupper( type ) == 'M' )
		_price = MAPLECOST;
	else
		_price = OAKCOST;

	_cost = numP * bf * _price;

	return _cost;
}

//*****************************************
// Return name of wood type based on char *
// representing type.                     *
//*****************************************
string getTypeName( char type )
{
	string woodType;

	switch ( toupper( type ) )
	{
		case 'P':
			woodType = "Pine";
			break;
		case 'F':
			woodType = "Fir";
			break;
		case 'C':
			woodType = "Cedar";
			break;
		default:
			woodType = "Maple";
	}

	return woodType;
}