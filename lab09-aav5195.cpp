//Author:	  Anthony Vallin, aav5195, 18Oct2018 2020
//Class:      CMPSC 121
//Assignment: Lab09
//File:       lab09-aav5195.cpp
//Purpose: 	  Displays day of the week for user inputed date
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
// Sources of Logic assistance: Lab Experiment 09 instruction sheet

#include<iostream>
using namespace std;

//Function Prototypes
bool isLeapYear( int );
bool dateValid( int, int );
int getMonthValue( int, int );
int getCenturyValue( int );
int getYearValue( int );
void displayDate( int, int, int );
void getDay( int, int, int, int );

int main()
{
	char prgmExit;
	int day;   //Day of month
	int year;  //Year
	int month; //Month of year
	int yearValue;    //Years in century
	int monthValue;    //Month value based on table
	int centuryValue;   //Century of year
	bool dateValidation; //Validates day and month range

	do
	{
		cout << "Enter a date in the form month day year, eg 4 24 1939" << endl;
		cin >> month >> day >> year;
		dateValidation = dateValid( day, month );

		if ( !dateValidation )
			cout << "Incorrect format. Try again." << '\n';
		else
		{
			yearValue = getYearValue( year );
			monthValue = getMonthValue( month, year );
			centuryValue = getCenturyValue( year );

			displayDate( month, day, year );
			getDay( day, monthValue, yearValue, centuryValue );

			cout << "Do you wish to enter another date? Y or N" << '\n';
			cin >> prgmExit;
		}

	} while ( !dateValidation || prgmExit == 'Y' );

	system( "pause" );
	return 0;
}

//***************************
// Validates day and month. *
//***************************
bool dateValid( int day, int month )
{
	bool _dateValid;

	if ( ( day >= 1 && day <= 31 ) && ( month >= 1 && month <= 12 ) )
		_dateValid = true;
	else
		_dateValid = false;

	return _dateValid;
}

//****************************************
// Determines whether year is leap year. *
//****************************************
bool isLeapYear( int year )
{
	bool _leapYear;

	if ( (( year % 4 == 0 ) &&  ( year % 100 != 0 )) || ( year % 400 == 0 ) )
		_leapYear = true;
	else
		_leapYear = false;

	return _leapYear;
}

//****************************************
// Determines century year falls within. *
//****************************************
int getCenturyValue( int year )
{
	int _centuryValue;

	_centuryValue = ( 3 - ( year % 4 ) ) * 2;
	return _centuryValue;
}

//*******************************************************
// Computes value based on years since the beginning of *
// the century.                                         *
//*******************************************************
int getYearValue( int year )
{
	int _yearsInCentury;
	int _leapYearFactor;

	_yearsInCentury = year % 100;
	_leapYearFactor = _yearsInCentury / 4;

	return ( _yearsInCentury + _leapYearFactor );
}

//*****************
// Returns month. *
//*****************
int getMonthValue( int month, int year )
{
	int _monthValue;

	if ( isLeapYear( year ) )
	{
		switch ( month )
		{
			case 1:
			case 4:
			case 7:
				_monthValue = 6;
				break;
			case 2:
			case 8:
				_monthValue = 2;
				break;
			case 3:
			case 11:
				_monthValue = 3;
				break;
			case 5:
				_monthValue = 1;
				break;
			case 6:
				_monthValue = 4;
				break;
			case 9:
			case 12:
				_monthValue = 5;
				break;
			case 10:
				_monthValue = 0;
				break;
		}
	}
	else
	{
		switch (month)
		{
		case 1:
		case 10:
			_monthValue = 0;
			break;
		case 2:
		case 3:
		case 11:
			_monthValue = 3;
			break;
		case 4:
		case 7:
			_monthValue = 6;
			break;
		case 5:
			_monthValue = 1;
			break;
		case 6:
			_monthValue = 4;
			break;
		case 8:
			_monthValue = 2;
			break;
		case 9:
		case 12:
			_monthValue = 5;
			break;
		}
	}

	return _monthValue;
}

//*****************
// Displays date. *
//*****************
void displayDate( int _month, int _day, int _year )
{
	cout << _month << '/' << _day << '/' << _year << " is a ";
}


//******************************
// Calculates day of the week. *
//******************************
void getDay( int _day, int _monthValue, int _yearValue, int _centuryValue )
{
	int dayValue;

	dayValue = ( _day + _monthValue + _yearValue + _centuryValue ) % 7;

	if ( dayValue == 0 )
		cout << "Sunday" << endl;
	else if ( dayValue == 1 )
		cout << "Monday" << endl;
	else if ( dayValue == 2 )
		cout << "Tuesday" << endl;
	else if ( dayValue == 3 )
		cout << "Wednesday" << endl;
	else if ( dayValue == 4 )
		cout << "Thursday" << endl;
	else if ( dayValue == 5 )
		cout << "Friday" << endl;
	else 
		cout << "Saturday" << endl;
}

/*Sample Solution:
Enter a date in the form month day year, eg 4 24 1939
10 26 2016
10/26/2016 is a Wednesday
Do you wish to enter another date? Y or N
Y
Enter a date in the form month day year, eg 4 24 1939
12 25 2016
12/25/2016 is a Sunday
Do you wish to enter another date? Y or N
Y
Enter a date in the form month day year, eg 4 24 1939
32 65 2002
Incorrect format. Try again.
Enter a date in the form month day year, eg 4 24 1939
2 32 2000
Incorrect format. Try again.
Enter a date in the form month day year, eg 4 24 1939
33 25 2000
Incorrect format. Try again.
Enter a date in the form month day year, eg 4 24 1939
04 25 1984
4/25/1984 is a Tuesday
Do you wish to enter another date? Y or N
N
Press any key to continue . . .
*/