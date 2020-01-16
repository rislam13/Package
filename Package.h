/*Name:Reham Islam
 * Professor Papadakis
 * 4/30/2017
 * This is a Package class for Lab 4
 */

#include<iostream>
using namespace std;

#ifndef PACKAGE_H
#define PACKAGE_H

#include "Customer.h"

class Package
{   
public:
	Package();
	Package(Customer sender,  Customer recipient, double);
	
	//Mutators Methods: Alters and checks the content
	bool setWeight(double );
	bool setcostPerOunce(double);
	//Accessor Methods: Returns the contents of Data membets
	
	double getWeight()const;

	void output()const;
        void input();
	double calculateCost()const;

	
private:
	Customer sender;
	Customer recipient;
	double weight;
	int costPerOunce; 
};

#endif//PACKAGE.H
