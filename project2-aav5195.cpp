//Author:	  Anthony Vallin, aav5195, 09Oct2018 2000
//Class:      CMPSC 121
//Assignment: Project02
//File:       project2-aav5195.cpp
//Purpose: 	  Read invoice details from file and ouput invoices which
//            indicates total costs of each item and total cost of invoice.
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
// Sources of Logic assistance: Project#2 instruction sheet. 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Function Prototypes
double calccost( int, double );
double acctotal( double, double );
void printLine( string, string, int, double, double );
void printInvoiceHeader( string );
void printTotal( double );
void printReportHeader();

ofstream fout; //Output file

int main()
{
	ifstream invoiceFile; //Invoice file
	string transactionID; //Purchase transaction ID number
	string invoiceDate; //Invoice date
	string toolName;  //Tool name
	double toolPrice = 0.0; //Price of tool
	double toolTotal = 0.0; //Tool cost of tool purchased
	double transactionTotal = 0.0; //Total cost of transaction
	int toolQty;      //Tool quantity
	int invoiceNum; //Invoice ID number

	//Opens vehicle fleets file for read and write
	invoiceFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Project02\\input.txt" );
	fout.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Project02\\output.txt" );
	
	if ( invoiceFile && fout )
	{
		fout << fixed << setprecision(2);
		printReportHeader();

		do
		{
			invoiceFile >> invoiceNum >> invoiceDate;

			printInvoiceHeader( invoiceDate );

			//Iterates through number of individual transactions per invoice
			for ( int i = 0; i < invoiceNum; i++ )
			{
				invoiceFile >> transactionID >> toolName >> toolQty >> toolPrice;
				toolTotal = calccost( toolQty, toolPrice );
				printLine( transactionID, toolName, toolQty, toolPrice, toolTotal );
				transactionTotal = acctotal( transactionTotal, toolTotal );
			}

			printTotal( transactionTotal );
			transactionTotal = 0.0;

		} while ( !invoiceFile.eof() );

		cout << "File read and write successful!" << endl;
	}
	else
		cout << "File open error!" << endl;
	
	invoiceFile.close();
	fout.close();
	
	system( "pause" );
	return 0;
}

//****************************************
//Calculates the cost for a single item. *
//****************************************
double calccost( int quantity, double unitcost )
{
	return ( quantity * unitcost );
}

//****************************************
//Accumulates the total cost of invoice. *
//****************************************
double acctotal( double totalCost, double itemCost )
{
	return ( totalCost += itemCost );
}

//******************************
//Writes a line of the invoice.*
//******************************
void printLine( string itemno, string name, int quantity, double unitCost, double totalCost )
{
	fout << left;
	fout << setw( 10 ) << itemno << setw( 12 ) << name;
	fout << right;
	fout << setw( 6 ) << quantity 
		 << setw( 7 ) << unitCost
		 << setw( 8 ) << totalCost << endl;
}

//***************************************************
//Writes “Invoice date: “ and the date to the file. *
//***************************************************
void printInvoiceHeader( string date )
{
	fout << "Invoice Date:  " << date << "\n\n";
}

//***************
//Prints total. *
//***************
void printTotal( double invoiceTotal )
{
	fout << "Total  ............." << invoiceTotal << '\n' << endl;
}

//****************************
//Displays the company name. *
//****************************
void printReportHeader()
{
	fout << "    Erie Industrial Supply Corporation" << '\n';
}

/*Example Solution:
	Erie Industrial Supply Corporation
Invoice Date:  2/12/2017

134276    Framis-R         8   7.35   58.80
125790    Framis-L        12  15.76  189.12
100086    Aglet          395   0.11   43.45
Total  .............291.37

Invoice Date:  1/23/2017

135876    Wrench          12  22.50  270.00
543287    Henway           4  19.25   77.00
Total  .............347.00

Invoice Date:  1/15/2017

161432    Widget           5   6.50   32.50
543289    Wodget          10   2.25   22.50
876234    Gadget           2  10.75   21.50
Total  .............76.50

Invoice Date:  2/16/2017

198765    Corkle           2  12.18   24.36
107654    Swale            3   8.75   26.25
987987    Sinter           5   6.43   32.15
654821    Zangle           6  18.45  110.70
432165    Lunule           7   9.60   67.20
333221    Fangle          10  58.49  584.90
654098    Fwetstock        3  12.65   37.95
543210    Furnal           3   9.98   29.94
543287    Bobble          12  19.25  231.00
Total  .............1144.45

Invoice Date:  2/26/2017

654821    Muntin           2  18.45   36.90
766443    Finwiddie        9   2.22   19.98
120980    Ferkle         100   0.12   12.00
123222    Sneedooper     700   1.19  833.00
876543    Ferrule          2 345.77  691.54
877721    Uberfrock       14  88.93 1245.02
Total  .............2838.44

Press any key to continue . . .
*/