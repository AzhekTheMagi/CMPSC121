//Author:	  Anthony Vallin, aav5195, 29Sep2018 1820
//Class:      CMPSC 121
//Assignment: Lab06
//File:       lab06-aav5195.cpp
//Purpose: 	  Calculates units, unit prices, and total  
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
using namespace std;

int main()
{
	bool exitLoop = false; //Loop control flag
	int units = 0;           //Units bought
	int unitsSold = 0;       //Total number of units sold
	int itemSentinel  = -99; //Sentinel value for program exit
	int transactionsProcessed = 0; //Number of processed transactions
	double unitPrice = 0.0;    //Unit Price
	double unitAverage = 0.0;  //Average units per transactions
	double transactions = 0.0; //Transaction cost
	double totalRevenue = 0.0; //Total Revenue
	double averageRevenue = 0.0;      //Average Revenue
	double largestTransaction = 0.0;  //Largest Transaction
	double smallestTransaction = 0.0; //Smallest Transaction

	//Menu
	cout << "Enter transactions -99 0 to stop: " << endl;

	do
	{
		//User input with transaction processed counter
		cout << "Transaction # " << ++transactionsProcessed << ": ";
		cin >> units >> unitPrice;

		//Calculates transaction report data values 
		if (units != itemSentinel)
		{
			unitsSold += units;
			unitAverage = (unitsSold / static_cast<double>(transactionsProcessed));
			transactions = (units * unitPrice);
			totalRevenue += transactions;
			averageRevenue = (totalRevenue / transactionsProcessed);

			//Determines largest and smallest transaction
			if (transactionsProcessed == 1)
			{
				largestTransaction = transactions;
				smallestTransaction = transactions;
			}
			else
			{
				if (transactions > largestTransaction)
					largestTransaction = transactions;
				else if (transactions < smallestTransaction)
					smallestTransaction = transactions;
			}
		}
		else
		{
			exitLoop = true;
			transactionsProcessed--;
		}
	} while (!exitLoop);

	//Prints out Transaction report for customer
	cout << "TRANSACTION PROCESSING REPORT" << '\n';
	cout << "    Transactions processed:" << setw(11) << transactionsProcessed << '\n'
		 << "    Units Sold:" << setw(23) << unitsSold << endl;
	cout << setprecision(2) << fixed;
	cout << "    Average Units per Order:" << setw(10) << unitAverage << '\n'
		 << "    Largest Transaction:" << setw(14) << largestTransaction << '\n'
		 << "    Smallest Transaction:" << setw(13) << smallestTransaction << '\n'
		 << "    Total Revenu:" << setw(21) << totalRevenue << '\n'
		 << "    Average Revenue" << setw(19) << averageRevenue << endl;

	system("pause");
	return 0;
}