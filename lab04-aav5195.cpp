//Author:	  Anthony Vallin, aav5195, 12Sep2018 1900
//Class:      CMPSC 121
//Lab:        Lab04
//File:       lab04-aav5195.cpp
//Purpose: 	  Calculates cost to park a vehicle 
/********************************************************************\
* Academic Integrity Affidavit:                                      *                                                                                                                                                     *                                                                    *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *                                                                                                                                                                                                                                                                                                                       *                                                                    *
* I understand that submitting code which is totally or partially    *
* the product of other individuals is a violation of the Academic    *
* Integrity Policy and accepted ethical precepts. Falsified          *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment, reduced   *
* credit for the assignment, or course failure.                      *
\********************************************************************/
// Sources of Logic assistance: Lab04 Manual
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const int LIMIT = 2;     //Car and Truck 1st rate parking limit
	const int BUS_LIMIT = 1; //Bus 1st rate parking limit
	const double CAR_1ST_RATE = 1.25;   //First 2 hours of parking rate (car)
	const double CAR_2ND_RATE = 1.50;   //Car overtime parking rate
	const double TRUCK_1ST_RATE = 2.75; //First 2 hours of parking rate (Truck)
	const double TRUCK_2ND_RATE = 3.75; //Truck overtime parking rate
	const double BUS_1ST_RATE = 9.50;   //First hour of parking rate (Bus)
	const double BUS_2ND_RATE = 6.75;   //Bus overtime parking rate
	
	char vehicle;          //Vehicle Type (C,T,B)
	string vehicleType;    //Vehicle Type (Car, Truck, Bus)
	int hoursParked;       //Total hours parked
	double totalDue = 0.0; //Total cost of parking
	
	//User input for vehicle type and hours parked
	cout << "Enter vehicle type(C=Car, T=Truck, B=Bus) and hours parked: ";
	cin >> vehicle >> hoursParked;
	
	//Calculates total amount due based on vehicle rate and hours parked
	switch (vehicle)
	{
		case 'C':
		    if (hoursParked > LIMIT)
				totalDue = ((hoursParked - LIMIT) * CAR_2ND_RATE) + (LIMIT *
			                 CAR_1ST_RATE);
			else
				totalDue = hoursParked * CAR_1ST_RATE;
			break;
		
		case 'T':
		    if (hoursParked > LIMIT)
				totalDue = ((hoursParked - LIMIT) * TRUCK_2ND_RATE) + (LIMIT *
			                 TRUCK_1ST_RATE);
			else
				totalDue = hoursParked * TRUCK_1ST_RATE;
			break;
		
		case 'B':
		    if (hoursParked > BUS_LIMIT)
				totalDue = ((hoursParked - BUS_LIMIT) * BUS_2ND_RATE) +
			               (BUS_LIMIT * BUS_1ST_RATE);
			else
				totalDue = hoursParked * BUS_1ST_RATE;
			break;

		default: cout << "Invalid selection choice. Try again." << endl;
	}

	//Assigns vehicle type
	if (vehicle == 'C')
		vehicleType = "Car";
	else if (vehicle == 'T')
		vehicleType = "Truck";
	else if (vehicle == 'B')
		vehicleType = "Bus";
	else
		vehicleType = "Invalid Selection";
	
	//Prints parking invoice
	cout << setprecision(2) << fixed << left;
	cout << "Vallin Parking Lots, Inc." << '\n'
	     << "\"We usually find your vehicle!" << '\n'
		 << "===============================" << '\n';
	cout << setw(16) << "Vehicle Type:" << vehicleType << '\n'
         << setw(16) << "Time:" << hoursParked << " Hours" << '\n'
         << setw(16) << "Amount Due:" << '$' << totalDue << '\n'
		 << "===============================" << endl;
		 
	system("pause");
	return 0;
}

/*Solution Example:
Enter vehicle type(C=Car, T=Truck, B=Bus) and hours parked: C 7
Vallin Parking Lots, Inc.
"We usually find your vehicle!
===============================
Vehicle Type:   Car
Time:           7 Hours
Amount Due:     $10.00
===============================
Press any key to continue . . .
---
Enter vehicle type(C=Car, T=Truck, B=Bus) and hours parked: T 10
Vallin Parking Lots, Inc.
"We usually find your vehicle!
===============================
Vehicle Type:   Truck
Time:           10 Hours
Amount Due:     $35.50
===============================
Press any key to continue . . .
---
Enter vehicle type(C=Car, T=Truck, B=Bus) and hours parked: B 8
Vallin Parking Lots, Inc.
"We usually find your vehicle!
===============================
Vehicle Type:   Bus
Time:           8 Hours
Amount Due:     $56.75
===============================
Press any key to continue . . .
*/