//Author:	  Anthony Vallin, aav5195, 03Nov2018 2000
//Class:      CMPSC 121
//Assignment: Lab 12
//File:       lab12-aav5195.cpp
//Purpose: 	  Reads in sales report data and accumulates totals
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
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct SalesRecord
{
	string invoiceNum;
	char equipCode;
	double cost;
};

//Function Prototypes
void accumulate( const SalesRecord &, double &, double &, double& );
void writeReport( double, double, double, double, double, double, double );
double getTotal( double, double, double );
double getPercentage( double, double );

int main()
{
	ifstream salesFile;
	SalesRecord saleReport;
	double capEquip = 0.0;
	double expEquip = 0.0;
	double smallParts = 0.0;
	double saleTotal;
	double capPercentage;
	double expPercentage;
	double smallPartPercentage;

	//Opens file for reading
	salesFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Labs\\Lab12\\sales.txt" );

	//Reads sales data into struct instance
	if ( salesFile )
		while ( salesFile >> saleReport.invoiceNum >> saleReport.equipCode >> saleReport.cost )
		{
			accumulate( saleReport, capEquip, expEquip, smallParts );
		}
	else
		cout << "File opening error!" << endl;

	//Closes file
	salesFile.close();

	//Calculates sales totals & percentages of each accumulated equipment total
	saleTotal = getTotal( capEquip, expEquip, smallParts );
	capPercentage = getPercentage( capEquip, saleTotal );
	expPercentage = getPercentage( expEquip, saleTotal );
	smallPartPercentage = getPercentage( smallParts, saleTotal );

	//Calls sales report function for file-write
	writeReport( capEquip, expEquip, smallParts, capPercentage, expPercentage,
		         smallPartPercentage, saleTotal );

	system( "pause" );
	return 0;
}

//*************************************************
// Accumulates running total of various equipment *
// sales and total sales amount.                  *
//*************************************************
void accumulate( const SalesRecord &sales, double &capSales, double &expSales, double &prtSales )
{
	//Accumulates total equipment sales per equipment category
	switch ( toupper( sales.equipCode ) )
	{
		case 'A':
			capSales += sales.cost;
			break;
		case 'B':
			expSales += sales.cost;
			break;
		default:
			prtSales += sales.cost;
	}
}

//********************
// Gets total sales. *
//********************
double getTotal( double capTotal, double expTotal, double smallpTotal )
{
	double totalSales;

	totalSales = capTotal + expTotal + smallpTotal;

	return totalSales;
}

//******************************************
// Breaks down sales report equipment sale *
// percentage.                             *
//******************************************
double getPercentage( double equip, double s_Total )
{
	double percentTotal; //Equipment Sale percentage

	//Calculates percent of each equipment sale category
	percentTotal = ( equip / static_cast< double >( s_Total ) ) * 100;

	return percentTotal;
}

//*******************************************************
// Creates a file and writes sales report data to file. *
//*******************************************************
void writeReport( double capEq, double expEq, double smallEq, double capPercent, 
	              double expPercent, double smallPercent, double total )
{
	ofstream reportFile; 

	//Creates file for writing sales report
	reportFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Labs\\Lab12\\inventoryReport.txt" );

	//Writes report to file on drive
	if ( reportFile )
	{
		reportFile << left << fixed << setprecision( 2 );
		reportFile << "    S A L E S  R E P O R T" << '\n';
		reportFile << setw( 24 ) << "Capital Equipment"  << '$'
			 << setw( 10 ) << capEq << capPercent  << '%' << '\n'
			 << setw( 24 ) << "Expensed Equipment" << '$'
			 << setw( 10 ) << expEq << expPercent  << '%' << '\n'
			 << setw( 24 ) << "Small Parts" << '$'
			 << setw( 10 ) << smallEq << smallPercent << '%' << '\n';
		reportFile << right << setw( 33 ) << "----------"   << '\n';
		reportFile << left  << setw( 24 ) << "Total Sales"  << '$' << total << endl;
	}
	else
		cout << "File failed to open" << endl;

	reportFile.close();
}