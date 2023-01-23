//Author:	  Anthony Vallin, aav5195, 29Aug2018 0944
//Class:      CMPSC 121
//Experiment: Lab 05
//File:       lab05-aav5195.cpp
//Purpose: 	  
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
// Sources of Logic assistance: Lab 05

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_STANDARD = 60;       //Number of free minutes w/ standard plan
const int MAX_DAY_PREMIUM = 75;    //Number of free daytime minutes w/ premium plan
const int MAX_NIGHT_PREMIUM = 100; //Number of free nighttime minutes w/ premium plan
const double STANDARD_PLAN = 12.00;  //Monthly cost of standard plan
const double PREMIUM_PLAN  = 25.00;  //Monthly cost of premium plan
const double S_OVERAGE       = 0.20; //Standard plan price per minute
const double P_DAY_OVERAGE   = 0.10; //Premium plan price per daytime minute
const double P_NIGHT_OVERAGE = 0.05; //Premium plan price per nighttime minute

int main()
{
	bool isStandard = false; //Standard or Premium Flag
	char serviceCode;    //Service code for plan types
	string serviceType;  //Service Type (premium or standard)
	string account;      //Account number
	int dayMinutes   = 0; //Total day minutes (premium or standard)
	int nightMinutes = 0; //Total night minutes (premium)
	double dayTotal   = 0.00; //Total cost of day minutes (premium or standard)
	double nightTotal = 0.00; //Total cost of nighttime minutes (premium)
	double billTotal  = 0.00; //Total cost of plan and minute overage

	//User input for account and service type
	cout << "Enter account number and service code <s or p>: ";
	cin >> account >> serviceCode;

	//Calculates cost of minutes overage
	if (serviceCode == 'p' || serviceCode == 'P')
	{
		serviceType = "PREMIER";
		cout << "Enter daytime and nighttime minutes: ";
		cin >> dayMinutes >> nightMinutes;
		if (dayMinutes > MAX_DAY_PREMIUM)
			dayTotal = ((dayMinutes - MAX_DAY_PREMIUM) * P_DAY_OVERAGE);
		if (nightMinutes > MAX_NIGHT_PREMIUM)
			nightTotal = ((nightMinutes - MAX_NIGHT_PREMIUM) * P_NIGHT_OVERAGE);
	}
	else if (serviceCode == 's' || serviceCode == 'S')
	{
		serviceType = "STANDARD";
		isStandard = true;
		cout << "Enter total minutes: ";
		cin >> dayMinutes;
		if (dayMinutes > MAX_STANDARD)
			dayTotal = ((dayMinutes - MAX_STANDARD) * S_OVERAGE);
	}
	else
		cout << "Invalid entry. Try again." << endl;
	//Flag dictates whether standard or premium bill is totaled
	if (isStandard)
		billTotal = STANDARD_PLAN + dayTotal;
	else
		billTotal = PREMIUM_PLAN + dayTotal + nightTotal;
	
	//Displays Phone bill 
	cout << setprecision(2) << fixed << left;
	cout << "----Zippy Cell Phone Company----" << '\n';
	cout << setw(21) << "Service Type:"      << serviceType << '\n'
		 << setw(21) << "Daytime minutes:"   << dayMinutes << '\n'
		 << setw(21) << "Nighttime minutes:" << nightMinutes << '\n'
		 << setw(21) << "Amount Due:" << '$' << billTotal << endl;

	system("pause");
	return 0;
}