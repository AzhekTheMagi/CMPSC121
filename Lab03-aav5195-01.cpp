//Author:	  Anthony Vallin, aav5195, 06Sep2018 1800
//Class:      CMPSC 121
//Lab:        03 part 1
//File:       Lab03-aav5195-01.cp
//Purpose: 	  Calculate volume and surface area 
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
// Sources of Logic assistance: Lab Experiment #03

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159;

int main() 
{
	double ringRadii;          //Ring radius of hose
    double crossSectionRadii;  //Cross sectional radius of hose
    double volume;             //Volume of hose
    double surfaceArea;        //Surface Area of hose
    
	//User inputs values required to calculate volume & surface area of hose
	cout << "Enter radius of ring and radius of cross section: ";
    cin >> ringRadii >> crossSectionRadii;

	//Calculates volume and surface area of hose
    volume = 2 * pow(PI, 2.0) * ringRadii * pow(crossSectionRadii, 2.0);  
    surfaceArea = 4 * pow(PI, 2.0) * ringRadii * crossSectionRadii;  //4 is formula constant
	
	//Displays results of calculation for user
	cout << setprecision(3) << fixed;
	cout << "For a ring with a radius of "  << ringRadii
	     << " and cross section radius of " << crossSectionRadii
		 << endl;
    cout << "The volume is:" << setw(15) << volume << '\n'
         << "The surface area is:" << setw(9) << surfaceArea
         << endl;		 

    system("pause");
    return 0;
}

/*Solution Example:
Enter radius of ring and radius of cross section: 25.75 3
For a ring with a radius of 25.750 and cross section radius of 3.000
The volume is: 4574.554
The surface area is: 3049.703
Press any key to continue . . .
*/