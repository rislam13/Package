/*
 * Name: Reham Islam
 * 5/6/2017
 * Professor Papadakis
 * CISC2000
 * This is a Source file for the overnight shipping class
 */

#include "OverNightPackage.h"

int OverNightPackage::numOfOverNightPackage;
double OverNightPackage::totalOverNight; 

//Default Constructor
OverNightPackage::OverNightPackage()
{	additionalFee = 10;
	numOfOverNightPackage++;
	//setWeight(getWeight()*additionalFee);
}

OverNightPackage::OverNightPackage(double m):OverNightPackage()
{	setAdditionalFee(m);
}

//Custom COnstructor: note ad to copy and pasete the default constructor
//Because It gives me error about using delegrated constrctor
OverNightPackage::OverNightPackage(Customer sender, Customer reciept, double weight):Package( sender, reciept, weight)
{	 additionalFee = 10;
         setWeight(getWeight()*additionalFee);
}

bool OverNightPackage::setAdditionalFee(double m)
{	if(m > 0)
	{	OverNightPackage::additionalFee = m;
		return ( true );
	}
	return ( false );
}

//
//This method will return the additional fee
//
double OverNightPackage::getAdditionalFee()const
{	return( additionalFee );
}

int OverNightPackage::getnumOfOverNightPackage()
{	return( numOfOverNightPackage );
}

double OverNightPackage::gettotalOverNight() 
{	return( totalOverNight );
}

//This method overwrites the base classes’ member 
//function and calculates the cost of sending the package using this service by adding
//the flat fee to the weight based cost.
double OverNightPackage::calculateCost()
{	setWeight(getWeight()*additionalFee);
	//totalOverNight =totalOverNight - (Package::calculateCost() );//if the fuction is called mistakely twice
	totalOverNight = totalOverNight+ Package::calculateCost();//Will add the num of dollars per night	
	return ( Package::calculateCost() );
}

//
//This method will ask the user to enter the information
//
void OverNightPackage::input()
{	Package::input();//calls the input function from the package class
}

//A function print() that prints the sender and recipient information, any attributes
//associated with this package as well as the cost associated with sending this package.
void OverNightPackage::print()
{	 Package::output();
         cout << "Price: " << calculateCost() << endl;
}
/*
main()
{	OverNightPackage Two;
	Two.input();
	Two.print();
	Name J("RRR",'J',"KKK");	
	Customer k(J, "111 place", "city", "KK", 12345);
	Customer j(J, "111 2", "cit", "Kb", 12345);

	OverNightPackage L(k, j, 10);	
	L.print();
	
	
}*/
