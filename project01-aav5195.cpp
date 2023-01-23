//Author:	  Anthony Vallin, aav5195, 19Sep2018 2000
//Class:      CMPSC 121
//Assignment: Project 01
//File:       project01-aav5195.cpp
//Purpose: 	  Calculates and displays wind chill  
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
#include <cmath>
using namespace std;

const int ROW = 12;      //Max number of temperature rows
const int COLUMN = 9;    //Max number of windchill columns
const int INCREMENT = 5; //Increments actual temperature and windspeed by 5

int main()
{
	double windChill;         //Stores calculated wind chill
	double windSpeed = 5.0;   //Initial wind speed
	double actualTemp = -5.0; //Initial actual temperature
	
	//Sets up formatting for table
	cout << setprecision(1) << fixed << left;
	cout << setw(23) << "Temp :" << "Wind Speed" << endl;
    cout << right << setw(11) << '5' << setw(8) << "10" << setw(8) << "15"
         << setw(8) << "20" << setw(8) << "25" << setw(8) << "30"
         << setw(8) << "35" << setw(8) << "40" << setw(8) << "45" << endl;

	//Calculates wind chill and displays results
    for (int count = 0; count < ROW; count++)
	{
		cout << setw(4) << actualTemp;
        for (int i = 0; i < COLUMN; i++)
        {
			windChill = 35.74 + (0.6215 * actualTemp) - (35.75 * pow(windSpeed, 0.16))
                        + (0.4275 * actualTemp * pow(windSpeed, 0.16));
			cout << setw(8) << windChill;
			windSpeed += INCREMENT;
		}
		windSpeed = INCREMENT;   //Resets wind speed to initial value for wind chill column calculation
		actualTemp += INCREMENT;
		cout << endl;
	}

	system("pause");
	return 0;
}

/*Solution Example:
Temp :                 Wind Speed
		  5      10      15      20      25      30      35      40      45
-5.0   -16.4   -22.1   -25.8   -28.6   -30.8   -32.7   -34.3   -35.7   -37.0
 0.0   -10.5   -15.9   -19.4   -22.0   -24.1   -25.9   -27.4   -28.8   -30.0
 5.0    -4.6    -9.7   -13.0   -15.4   -17.4   -19.1   -20.5   -21.8   -23.0
10.0     1.2    -3.5    -6.6    -8.9   -10.7   -12.3   -13.6   -14.8   -15.9
15.0     7.1     2.7    -0.2    -2.3    -4.0    -5.5    -6.8    -7.9    -8.9
20.0    13.0     8.9     6.2     4.2     2.6     1.3     0.1    -0.9    -1.8
25.0    18.9    15.1    12.6    10.8     9.3     8.1     7.0     6.1     5.2
30.0    24.7    21.2    19.0    17.4    16.0    14.9    13.9    13.0    12.2
35.0    30.6    27.4    25.4    23.9    22.7    21.7    20.8    20.0    19.3
40.0    36.5    33.6    31.8    30.5    29.4    28.5    27.7    26.9    26.3
45.0    42.3    39.8    38.2    37.0    36.1    35.3    34.5    33.9    33.3
50.0    48.2    46.0    44.6    43.6    42.8    42.0    41.4    40.9    40.4
Press any key to continue . . .
*/