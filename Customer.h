/*Name:Reham Islam
 * Professor Papadakis
 * 4/30/2017
 * This is a Customer class for Lab 4
 */

#include<iostream>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Name.h"

class Customer
{

friend ostream& operator<<(ostream&, const Customer&);
friend istream& operator>>(istream&, Customer&);
   
public:
	Customer();
	Customer(Name);
	Customer(Name, string, string, string, int);
	
	//Mutators Methods: Alters and checks the content
	bool setAddress(const string);
	bool setZip(const int);
	bool setCity(const string);
	bool setState(const string);

	void setName(string, char, string);
	
	//Accessor Methods: Returns the contents of Data membets
	string getCity()const;	
	string getState()const;
	string getAddress()const;
	int getZip() const;
	void getName() const;
	
	//Other Methods
	//This method will basically check whether string contains number
	bool checkNumber(const string) const;

	const Customer& operator=(const Customer&);	

private:
	Name name;
	string address;
	string city;
	string state;
	int zipCode;

	void output(ostream&)const;
        void input(istream&);

};

#endif//CUSTOMER_H
