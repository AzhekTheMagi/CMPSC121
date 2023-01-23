//Author:	  Anthony Vallin, aav5195, 06Sep2018 1800
//Class:      CMPSC 121
//Lab:        03 part 2
//File:       Lab03-aav5195-02.cp
//Purpose: 	  Calculate diameter and torque 
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

int main()
{
	double rpm;
	double horsePower;
	double shearStrength;
	double diameter;      //Diameter of Shaft
	double torque;        //Torque of Shaft
	
	//User inputs required values for torque and diameter calculation
	cout << "Enter values for horsepower(P), rpm(N), and shear strength: ";
	cin >> horsePower >> rpm >> shearStrength;
	
	//Calculates torque and diameter of shaft
	torque = 63000 * (horsePower / static_cast<double>(rpm)); //63000 is formula constant
	diameter = pow((16 * torque) / static_cast<double>(shearStrength), 0.333); //16 is formula constant
	
	//Displays final results of calculation
	cout << setprecision(3) << fixed;
	cout << "  P(HP)" << setw(11) << "N(rpm)" << setw(11) << "S(psi)"
	     << setw(14) << "T(torque)" << setw(16) << "D(diameter)" << endl;
		 
	cout << horsePower << setw(11) << rpm << setw(11) << shearStrength
	     << setw(14) << torque << setw(14) << diameter << " inches" << endl;
	
	system("pause");
	return 0;
}

/*Solution Example:
Enter values for horsepower(P), rpm(N), and shear strength: 20 50 5000
  P(HP)     N(rpm)     S(psi)     T(torque)     D(diameter)
20.000     50.000   5000.000     25200.000         4.314 inches
Press any key to continue . . .
*/