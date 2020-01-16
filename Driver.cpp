//Name:Reham Islam
//This is a driver file for Package Class
//CISC2000
//Professor Papadakis

#include <iostream>
using namespace std;

#include "TwoDayPackage.h"
#include "OverNightPackage.h"

void twoDay(TwoDayPackage*[]);
void overNight(OverNightPackage*[]);
void displayAll(OverNightPackage*[], TwoDayPackage*[]);

static const int MAXPASSENGERS =10;

int main()
{	int input = 0;
    const int MIN = 1, MAX = 3;
	cout << "Please follow the instructions below.\n\n";
	do{
		//These are the options that user are going to choose
		cout << "Please choose one of the options.\n\n";
		cout << "'1': Two Day Package.\n";
        cout << "'2': Over Night Package\n";
		cout << "'3': Get summary of Package delivered.\n";
		cout << "'4': Quit\n\n";
	
        //static const int MAXPASSENGERS =10;
        TwoDayPackage*two[MAXPASSENGERS];
        OverNightPackage*over[MAXPASSENGERS];
	
		//The outer do while is going to run unless the user chooses to quit		
		//The inner do while loop will make user the user chooses right number
		do{
			cout << "Please enter an option between (1-3): ";
			cin >> input;
		}while (input < MIN &&  input > MAX);

		//Switch statement will do the actions depending on the menu
		switch (input)
		{
			case 1:    
	                	twoDay(two);
        	        	break;
			case 2:   
			   	overNight(over);
				break;
			case 3:   
			    displayAll(over, two);//will show summary statistics
				break;
	
		}

	}while (input!= MAX);
}

void twoDay(TwoDayPackage* two[])
{	if(TwoDayPackage::getnumOfTwoDayPackage() >= MAXPASSENGERS)
		cout << "Exceeded number of Package for TDP " << endl;
	else
	{	two[TwoDayPackage::getnumOfTwoDayPackage()-1] = new TwoDayPackage;
		two[TwoDayPackage::getnumOfTwoDayPackage()-1]->input();
		cout << "getnumOfTwoDayPackage()" << TwoDayPackage::getnumOfTwoDayPackage() << endl;
	}
}

void displayAll(OverNightPackage*over[], TwoDayPackage* two[])
{
	 cout << TwoDayPackage::getnumOfTwoDayPackage() << "   " << OverNightPackage::getnumOfOverNightPackage() << endl;
	for(int i = 0; i < OverNightPackage::getnumOfOverNightPackage(); i++)
	{	cout << "Customer No: " << i << " for Over Night Package" << endl;
		over[i]->print();	
		cout << endl;
	}

	cout << TwoDayPackage::getnumOfTwoDayPackage() << "   " << OverNightPackage::getnumOfOverNightPackage() << endl;

	for(int i = 0; i < TwoDayPackage::getnumOfTwoDayPackage(); i++)
        {       cout << "Customer No: " << i << " for Two Day Package" << endl << endl;
		two[i]->print();
		cout << endl;
        }

	//cout << TwoDayPackage::gettotalCostTwoDayPackage()<< "____________" << endl;
	cout << "Total Amount of Money Earned: " <<  OverNightPackage::gettotalOverNight()+TwoDayPackage::gettotalCostTwoDayPackage() ;

}   


void overNight(OverNightPackage*over[] )
{        if(OverNightPackage::getnumOfOverNightPackage() >= MAXPASSENGERS)
                 cout << "Exceeded number of Package" << endl;
         else
         {      over[OverNightPackage::getnumOfOverNightPackage()-1] = new OverNightPackage;
                over[OverNightPackage::getnumOfOverNightPackage()-1]->input();
         }

	 cout << "getnumOfOverNightPackage() "<< OverNightPackage::getnumOfOverNightPackage()<< endl;
}



