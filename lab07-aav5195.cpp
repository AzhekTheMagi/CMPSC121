//Author:	  Anthony Vallin, aav5195, 07Oct2018 1000
//Class:      CMPSC 121
//Assignment: Lab07
//File:       lab07-aav5195.cpp
//Purpose: 	  Reads Fleet Report and displays MPG for each vehicle and fleet total. 
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
using namespace std;

int main()
{
	bool fileSuccess = true; //File open success flag
	ifstream fleetFile; //Vehicle Fleet file
	string vehicleID;    //Vehicle ID
	string bestVehicleID; //Best MPG Vehicle ID
	string worstVehicleID; //Worst MPG Vehicle ID
	int counter = 1; //Tracks total Vehicle count
	double mpg;   //Miles per Gallon
	double miles;  //Vehicle miles
	double gallons; //Vehicle gallons
	double bestMPG;  //Best MPG amount
	double worstMPG;  //Worst MPG amount
	double totalMiles = 0.0; //Total miles driven by all cars
	double averageMPG = 0.0; //Average MPG of all vehicles
	
	//Opens vehicle fleets file
	fleetFile.open( "D:\\OneDrive\\Skool\\PSU\\CMPSC 121\\Lab07\\FleetInput.txt" );
	
	if ( fleetFile )
	{
		//Prints Fleet Report Header
		cout << left;
		cout << "AMSCO Fleet Report\n" << setw( 17 ) << "Vehicle ID "
		     << setw( 9 ) << "Miles" <<setw( 11 ) << "Gallons" << "MPG\n" 
			 << "-------------------------------------------------" << endl;
		cout << setprecision( 1 ) << fixed;
		
		//Reads-in files and prints vehicle fleet information
		while ( fleetFile >> vehicleID >> miles >> gallons )
		{
			totalMiles += miles;      //Accumulates total fleet vehicle mileage
			mpg = ( miles / gallons ); //Calculates MPG of each vehicle
			
			//Calculates average MPG of vehicle fleet
			averageMPG += gallons;
			
			//Prints vehicle information for Fleet Report
			cout << setw( 27 - vehicleID.length() ) << vehicleID << setw( 10 ) 
			     << miles << setw( 10 ) << gallons << setw( 14 ) << mpg << endl;
			
			//Determines the best and worst MPG vehicles in fleet
			if ( counter == 1 )
			{
				bestVehicleID  = vehicleID;
				worstVehicleID = vehicleID;
				bestMPG  = mpg;
				worstMPG = mpg;
			}
			else
			{
				if ( mpg > bestMPG )
				{
					bestVehicleID = vehicleID;
					bestMPG = mpg;
				}
				else if ( mpg < worstMPG )
				{
					worstVehicleID = vehicleID;
					worstMPG = mpg;
				}
			}
			
			//Keeps track of vehicle count
			counter++;
		}
	}
	else
	{
		cout << "File open error!" << endl;
		fileSuccess = false;
	}
	
	averageMPG = static_cast< double >( totalMiles ) / averageMPG;

	//Prints data involving every vehicle in the fleet
	if ( fileSuccess )
	{
		cout << "-------------------------------------------------" << endl;
		cout << setw(16) << "Count"  << counter << '\n'
			 << setw(16) << "Total Miles" << totalMiles << '\n'
			 << setw(16) << "Average MPG" << averageMPG << '\n'
			 << setw(30) << "Vehicle ID with Best MPG"
			 << setw(16) << bestVehicleID << setw(4) << bestMPG << '\n'
			 << setw(30) << "Vehicle ID with Worst MPG"
			 << setw(16) << worstVehicleID << setw(4) << worstMPG << endl;
	}
	
	system( "pause" );
	return 0;
}

/*Example Solution:
AMSCO Fleet Report
Vehicle ID       Miles    Gallons    MPG
-------------------------------------------------
279BX6KY2Z       582.2     20.5      28.4
802MX8BZ4Q       723.6     25.1      28.8
671AY6DZ3N       756.9     27.5      27.5
845DH6AJ3B       660.2     25.4      26.0
566GJ6KV2U       510.2     30.8      16.6
109QW2RP2Y       301.2     8.3       36.3
135TR4YC6H       387.6     12.2      31.8
122AC6UG7P       228.9     14.7      15.6
136VW8TD2Z       331.2     19.1      17.3
448WQ2DX1M       543.9     33.6      16.2
721GZ1LJ5N       629.8     27.9      22.6
779FS3MB4Y       651.2     28.4      22.9
553SB5LK8O       444.4     26.8      16.6
-------------------------------------------------
Count           14
Total Miles     6751.3
Average MPG     22.5
Vehicle ID with Best MPG      109QW2RP2Y      36.3
Vehicle ID with Worst MPG     122AC6UG7P      15.6
Press any key to continue . . .
*/