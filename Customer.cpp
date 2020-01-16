/*Name:Reham Islam
 * Professor Papadakis
 * 4/30/2017
 * This is a source file for Customer Class
 */

#include "Customer.h"

istream& operator>>(istream& in, Customer& name)
{	name.input(in);
	return(in);
}

ostream& operator<<(ostream& on, const Customer& name)
{	name.output(on);
	return(on);
}


//Default Constructor
Customer::Customer()
{	address = "None";
	zipCode = 00000;
	city = "X";
	state = "KK";
}
//Custom Constructor
Customer::Customer(Name me):Customer()
{	name = me;
}

Customer::Customer(Name nam, string place, string city, string stae, int code): Customer()
{	name = nam;//calls the overloading assignment operator from name class
	setAddress(place);
	setCity(city);
	setState(stae);
	setZip(code);
}


//This menthod will make sure the whether string contains a number
bool Customer::checkNumber(const string place)const
{    	bool valid = false;
	//This for loop checks if there is at least one digit in the string
	for(int i = 0; i < place.length(); i++)
	{	char check = place[i];
		//isDigit will check whether the char is number
		if(isdigit(check))
		{	valid = true;
			break;
		}	
	}
	return ( valid );
}


//This method will make sure the address includes a number
//Based upon user input it will return true or false
bool Customer::setAddress(const string place)
{	if(checkNumber(place))//will check address has a number or not
	{	address = place;
	}
	return( checkNumber(place) );
}


//This will make sure the zip code is five digits	
bool Customer::setZip(const int zip)
{  	bool valid = false;
  
	string str = to_string(zip); // converst the int to string
	int length = str.length();//finds the lenght using string
	
	if(length==5)
	{	valid = true;
		zipCode = zip;	
	}
	return valid;
}

bool Customer::setCity(const string borough)
{	//This will check whether the city has number
	// If it has numbers, it will return false
	// City must not have any number
	if(!(checkNumber(borough)))
	{	city = borough;
	}
	return(!(checkNumber(borough)));
}


//This method will check whether the state 2 letter and
//It doesn't include any number 
bool Customer::setState(const string stat)
{	bool valid = false;
	if(!(setAddress(stat)))
	{	if(stat.length() == 2)
		{	valid = true;
			state = stat;
		}
	}
	return(valid);

}

void Customer::setName(string fname, char mi , string lname)
{	name.setLname(lname);
	name.setFname(fname);
	name.setMi(mi);
}

int Customer::getZip() const
{	return zipCode;
}

string Customer::getAddress() const
{	return address;
}

string Customer::getCity()const
{	return city;
}

string Customer::getState()const
{	return state;
}

const Customer& Customer::operator=(const Customer& copy)
{	this-> address = copy.address;
	state = copy.state;
	city = copy.city;
	zipCode = copy.zipCode;
	name = copy.name;
	return (*this);
}

void Customer::input(istream& in)
{	
	string adress = " ", city;
	int code;
	string state;
	//Calls the input fuction from the Name class
	in >> name;
	
	do{	cout << "Enter Address: ";
		getline(in,  adress); 
	}while(!(setAddress(adress)));
	
	do{     cout << "Enter city: ";
                in >> city;
        }while(!(setCity(city)));

	do{	cout << "Enter State: ";
		in >> state;
	}while(!(setState(state)));

	do{     cout << "Enter Zip Code: ";
                in >> code;
        }while(!(setZip(code)));
		
}

void Customer::getName()const
{	cout << name;
}

void Customer::output(ostream& out)const
{	out << name;
	out  << address <<  endl;
	out << city << ", " << state << " -" << zipCode << endl;
}
/*
main()
{	Customer k;
	cin >> k;
	cout << k;

}	*/
