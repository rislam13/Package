/*
 * Name: Reham Islam
 * 5/6/2017
 * Professor Papadakis
 * CISC2000
 * This is a Source file for the Two day shipping class
 */

#include "TwoDayPackage.h"

int TwoDayPackage::numOfTwoDayPackage;
double TwoDayPackage::totalCostTwoDayPackage;
//Default Constructor
TwoDayPackage::TwoDayPackage()
{	flatFee = 10;
	numOfTwoDayPackage++;
	
}

TwoDayPackage::TwoDayPackage(double m): TwoDayPackage()
{	setFlatfee(m);
}

TwoDayPackage::TwoDayPackage(Customer sender, Customer reciept, double weight)
		:Package( sender, reciept, weight)
{
}

bool TwoDayPackage::setFlatfee(double m)
{	if(m > 0)
	{	TwoDayPackage::flatFee = m;
		return true;
	}
	return false;
}

double TwoDayPackage::getFlatfee()const
{	return( flatFee );
}

double TwoDayPackage::gettotalCostTwoDayPackage()
{	return( totalCostTwoDayPackage );
}

int TwoDayPackage::getnumOfTwoDayPackage()
{	return( numOfTwoDayPackage);
}

//This method overwrites the base classes’ member 
//function and calculates the cost of sending the package using this service by adding
//the flat fee to the weight based cost.

/*
 * Note:: I tried to decrement the totalcost in case if the function calls twice, 
 * but it didn't work
 */
double TwoDayPackage::calculateCost()
{	//totalCostTwoDayPackage = (totalCostTwoDayPackage - (Package::calculateCost()+flatFee));
	totalCostTwoDayPackage = (totalCostTwoDayPackage + (Package::calculateCost()+flatFee));
	return ( Package::calculateCost()+flatFee );
}

//
//This method will ask the user to enter the information
//
void TwoDayPackage::input()
{	Package::input();//calls the input function from the package class
}

//A function print() that prints the sender and recipient information, any attributes
//associated with this package as well as the cost associated with sending this package.
void TwoDayPackage::print()
{	 Package::output();
         cout << "Price after adding flatfee: " << TwoDayPackage::calculateCost() << endl;
}
/*
main()
{
	TwoDayPackage Two;
	Two.input();
	Two.print();	
}*/
