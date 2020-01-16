/*
 * Name: Reham Islam
 * 5/6/2017
 * Professor Papadakis
 * CISC2000
 * This is a Header file for the Two day shipping class
 */


#include<iostream>
using namespace std;

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage: public Package
{
public: 
	TwoDayPackage();
	TwoDayPackage(double m);
	TwoDayPackage(Customer, Customer, double);

	bool setFlatfee(double);
	
	double getFlatfee()const;
	static int getnumOfTwoDayPackage();
	static double gettotalCostTwoDayPackage();

	double calculateCost();
	void input();
	void print();

private:
	double flatFee;
	double totalCost;
	static int numOfTwoDayPackage;
	static double totalCostTwoDayPackage;
};

#endif //TWODAYPACKAGE_H
