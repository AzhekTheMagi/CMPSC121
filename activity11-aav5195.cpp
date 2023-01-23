//Author:	  Anthony Vallin, aav5195, 04Oct2018 1900
//Class:      CMPSC 121
//Assignment: Activity 11
//File:       activity11-aav5195.cpp
//Purpose: 	  Read-in data from text file 
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
// Sources of Logic assistance: Module 7: Lesson 1: Reading Text Files

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream partsFile; //Read file 
	string partNum;     //Part number
	bool fileSuccess = true; //File flag
	char partClass;     //Part Class
	int inventory = 0;  //Temp current inventory
	int aInventory = 0; //Class A part inventory total
	int bInventory = 0; //Class B part inventory total
	int cInventory = 0; //Class C part inventory total
	int dInventory = 0; //Class D part inventory total
	int unknownInventory = 0;   //Unknown part inventory total
	double a_Total_Value = 0.0; //Class A total inventory value
	double b_Total_Value = 0.0; //Class B total inventory value
	double c_Total_Value = 0.0; //Class C total inventory value
	double d_Total_Value = 0.0; //Class d total inventory value
	double unknown_Total_Value = 0.0; //Unknown class total inventory value
	double inventoryValue = 0.0; //Temp current inventory value

	//Opens parts file from local student system (aav5195)
	partsFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Activity 11\\parts.txt" );

	//Initiates if file opens successfully
	if (partsFile)
	{
		//Reads in data from file
		while (partsFile >> partNum >> partClass >> inventory >> inventoryValue)
		{
			//Calculates part inventory and class value total
			switch (partClass)
			{
			case 'A':
				aInventory++;
				a_Total_Value += (inventory * inventoryValue);
				break;
			case 'B':
				bInventory++;
				b_Total_Value += (inventory * inventoryValue);
				break;
			case 'C':
				cInventory++;
				c_Total_Value += (inventory * inventoryValue);
				break;
			case 'D':
				dInventory++;
				d_Total_Value += (inventory * inventoryValue);
				break;
			default:
				unknownInventory++;
				unknown_Total_Value += (inventory * inventoryValue);
			}
		}
	}
	else
	{
		cout << "Unable to open File!" << endl;
		fileSuccess = false;
	}

	partsFile.close();

	//Prints out Inventory Report
	if (fileSuccess)
	{
		cout << fixed << setprecision(2);
		cout << "...........Inventory Report.........." << endl;
		cout << "A parts Count: " << aInventory << "  Value of inventory:" 
			 << setw(10) << a_Total_Value << endl;
		cout << "B parts Count: " << bInventory << "  Value of inventory:"
			<< setw(10) << b_Total_Value << endl;
		cout << "C parts Count: " << cInventory << "  Value of inventory:"
			<< setw(10) << c_Total_Value << endl;
		cout << "D parts Count: " << dInventory << "  Value of inventory:"
			<< setw(10) << d_Total_Value << endl;
		cout << "Unknown Count: " << unknownInventory << "  Value of inventory:"
			<< setw(10) << unknown_Total_Value << endl;
	}

	system( "pause" );
	return 0;
}