/*
 * Name: Reham Islam
 * 5/6/2017
 * Professor Papadakis
 * CISC2000
 * This is a Header file for the overnight shipping class
 */


#include<iostream>
using namespace std;

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OverNightPackage: public Package
{
public: 
	OverNightPackage();
	OverNightPackage(double m);
	OverNightPackage(Customer, Customer, double);

	bool setAdditionalFee(double);
	
	double getAdditionalFee()const;
	static int getnumOfOverNightPackage();
	static double gettotalOverNight();

	double calculateCost();
	void input();
	void print();

private:
	double additionalFee;
	static int numOfOverNightPackage;
	static double totalOverNight;
};

#endif //TWODAYPACKAGE_H
