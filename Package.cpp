/*Name:Reham Islam
 * Professor Papadakis
 * 4/30/2017
 * This is a Source file for Lab 4
 */
#include "Package.h"
Package::Package()
{	weight = 0;
	costPerOunce = 10;
}

Package::Package(Customer sender,Customer recipient, double weight):Package()
{	Package::sender = sender;
	Package::recipient =recipient;
	Package::weight=weight;
}

bool Package::setWeight(double mass)
{	bool valid = false;
	if(mass > 0)
	{	weight = mass;
		valid = true;
	}
	return( valid );
}

double Package::getWeight()const
{	return ( weight );
}

bool Package::setcostPerOunce(double set)
{	if(set > 0)
	{	costPerOunce= set;
		return ( true );
	}
	return ( false );
}


double Package::calculateCost()const
{	return( costPerOunce *  weight );	
}


void Package::output()const
{	cout << "From: \n"; 
	cout <<  sender << endl;
	cout << "To: \n" ;
	cout << recipient << endl;
	cout << "Total Cost" << calculateCost() << endl;	
}

void Package::input()
{	double mass = 0;
	cout << "Enter information about Sender: \n\n";
	cin >> sender;

	cout << "\n\nEnter information about Receipient: \n\n";
        cin >> recipient;
	
	do{	cout << "\n Weight of Package: "; 
		cin >> mass;
	}while(!(setWeight(mass)));
	
	
}
/*
main()
{	//Package A;
	Package A;
	A.input();
	A.output();
}*/
