//Author:	  Anthony Vallin, aav5195, 18Sep2018 1100
//Class:      CMPSC 121
//Lab:        Activity 08
//File:       activity08-aav5195.cpp
//Purpose: 	  Cartesian coordinate (x,y) quadrant locator 
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
// Sources of Logic assistance:

#include <iostream>
using namespace std;

int main()
{
	const int ORIGIN = 0; //Origin for x and y coordinates

	int xCoordinate; //x Coordinate
	int yCoordinate; //y coordinate

	//User inputs x and y coordinates
	cout << "Enter an integer coordinat: x, y" << endl;
	cin >> xCoordinate >> yCoordinate;

	//Calculates coordinate quadrant location
	if (xCoordinate == ORIGIN && yCoordinate == ORIGIN)
	{
		cout << '<' << xCoordinate << ',' << yCoordinate << '>'
			<< " is the origin." << endl;
	}
	else if (xCoordinate == ORIGIN)
	{
		cout << '<' << xCoordinate << ',' << yCoordinate << '>'
			<< " is on the y-axis." << endl;
	}
	else if (yCoordinate == ORIGIN)
	{
		cout << '<' << xCoordinate << ',' << yCoordinate << '>'
			<< " is on the x-axis." << endl;
	}
	else if (xCoordinate > ORIGIN && yCoordinate > ORIGIN)
	{
		cout << '<' << xCoordinate << ',' << yCoordinate << '>'
			<< " is in the first quadrant." << endl;
	}
	else if (xCoordinate < ORIGIN && yCoordinate > ORIGIN)
	{
		cout << '<' << xCoordinate << ',' << yCoordinate << '>'
			<< " is in the second quadrant." << endl;
	}
	else if (xCoordinate < ORIGIN && yCoordinate < ORIGIN)
	{
		cout << '<' << xCoordinate << ',' << yCoordinate << '>'
			<< " is in the third quadrant." << endl;
	}
	else if (xCoordinate > ORIGIN && yCoordinate < ORIGIN)
	{
		cout << '<' << xCoordinate << ',' << yCoordinate << '>'
			<< " is in the fourth quadrant." << endl;
	}
	else
		cout << "Invalid entry. Try again." << endl;

	system("pause");
	return 0;
}

/*Solution Example:
Enter an integer coordinat: x, y
0 0
<0,0> is the origin.
Press any key to continue . . .
---
Enter an integer coordinat: x, y
-6 0
<-6,0> is on the x-axis.
Press any key to continue . . .
---
Enter an integer coordinat: x, y
0 9
<0,9> is on the y-axis.
Press any key to continue . . .
---
Enter an integer coordinat: x, y
2 6
<2,6> is in the first quadrant.
Press any key to continue . . .
---
Enter an integer coordinat: x, y
-9 6
<-9,6> is in the second quadrant.
Press any key to continue . . .
---
Enter an integer coordinat: x, y
-2 -5
<-2,-5> is in the third quadrant.
Press any key to continue . . .
---
Enter an integer coordinat: x, y
8 -22
<8,-22> is in the fourth quadrant.
Press any key to continue . . .
*/