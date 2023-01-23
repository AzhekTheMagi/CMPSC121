//Author:     Anthony Vallin, aav5195, 04Sep2018 2000.
//Class:      CMPSC 121
//Activity:   05
//File:       Activity05-aav5195.cpp
//Purpose:    Calculates the purchase price and sale cost of shares

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double commission;    //Commission for share purchase and sell
	double sharesBought;  //Amount of shares purchased
	double purchasePrice; //Share purchase price
	double purchaseTotal; //Final cost of shares bought + commission fee
	double sellPrice;     //Share sell price
	double sellTotal;     //Sell total amount - sell commission fee 

    //Input Phase
	cout << "Enter number of shares purchased, purchase price of stock, commission rate, and saleprice: ";
	cin >> sharesBought >> purchasePrice >> commission >> sellPrice;

   //Calculates Purchase and Sale total to include commission costs
	purchaseTotal = (sharesBought * purchasePrice) * (commission + 1); //Total cost of purchase. '1' represents formula constant.
	sellTotal = (sharesBought * sellPrice) * (1 - commission);         //Total proceeds from stock sale. '1' represents formula constant.

   //Displays details of share purchase
	cout << setprecision(2) << fixed << endl;
	cout << "    **** TRANSACTION DETAILS ****" << endl;
	cout << "Cost of stock before commision" << setw(3) << '$' << setw(8) 
	     << (sharesBought * purchasePrice) << endl;
	cout << "Commission on purchase" << setw(11) << '$' << setw(8) 
	     << (sharesBought * purchasePrice * commission) << endl;
	cout << "Total Cost of purchase" << setw(11) << '$' << setw(8) 
	     << purchaseTotal << endl;
	cout << endl;

	//Displays details of share sale
	cout << "Sale revenue before commission" << setw(3) << '$' << setw(8) 
	     << (sharesBought * sellPrice) << endl;
	cout << "Commission on sale" << setw(15) << '$' << setw(8) 
	     << (sharesBought * sellPrice * commission) << endl;
	cout << "Total cost of sale" << setw(15) << '$' << setw(8) 
	     << sellTotal << endl;
	cout << endl;

	//Displays profits or loss on sale
	cout << "Profit or loss on sale" << setw(11) << '$' << setw(8) 
	     << (sellTotal - purchaseTotal) << endl;

	system("pause");
	return 0;
}

/*Solution example:
Enter number of shares purchased, purchase price of stock, commission rate, and saleprice: 1000 45.76 .02 57.23

	**** TRANSACTION DETAILS ****
Cost of stock before commision  $45760.00
Commission on purchase          $  915.20
Total Cost of purchase          $46675.20

Sale revenue before commission  $57230.00
Commission on sale              $ 1144.60
Total cost of sale              $56085.40

Profit or loss on sale          $ 9410.20
Press any key to continue . . .
*/