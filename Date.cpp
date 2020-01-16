//Name:Reham Islam
//This is a source file for Date


#include <iostream>
using namespace std;
#include "Date.h"


istream& operator>>(istream& inp, Date& d)
{	d.input(inp);
	return inp;
}

ostream& operator<<(ostream& out, Date& d)
{       d.output(out);
        return out;
}

bool Date::operator!=(const Date& other)const
{	return(!(*this == other));
}

bool Date::operator==(const Date& d) const
{	bool isEqual = false;
	if( month == d.month && this -> year == d.year && this -> day == d.day)
	{	isEqual = true;
	}
	return isEqual;
}

const Date& Date::operator=(const Date& d)
{
	month = d.month;
	year = d.year;
	day = d.day;

	return(*this);
}

//Default constructor will initialize all of the private data members
Date::Date(int mi, int ma): MIN(mi), MAX(ma)
{   this -> month=0;
    this -> year =0;
    this -> day  =0;
}


//Constructor that initializes object with name and date of birth
Date::Date(int x, int y, int z): MIN(1), MAX(12)
{   Date();
    setMonth(x);
    setYear(z);
    setDay(y);
}

Date::Date(const Date& d):MIN(d.MIN), MAX(d.MAX)
{   this -> month = d.month;
    this -> year = d.year;
    this -> day = d.day;
}

//This setMonth Function is going to make sure the month is on range
//It also makes sure the month is set to the Data member
bool Date::setMonth(int m) 
{   bool valid = false;
   //This if statement will make sure the month is between 1 to 12
   
    if(m >= MIN  && m <= MAX)
    {   this -> month = m;
        valid = true;
    }
    return (valid);
}

//This setYear Function is going to make sure the year is on range
//It also makes sure the year is set to the Data member
bool Date::setYear(int y)
{   bool v = false;
    //This if statement will prevent setting wrong value to the Year
    if(y >1000 && y < 4000)
    {   this -> year = y;
        v = true;
    }
    return (v);
}

//This setDay Function is going to make sure the day is on range
//It also makes sure the day is set to the Data member
bool Date::setDay(int d)
{   bool v = false;
    //This will make sure if the day and the month are valid
    if(year%4==0 && d >=30)
    {   v= false;
    }else if(d==31 && (month!=9 || month!=4 || month!=6 || month!=11))
    {   day=d;
        v=true;
    }else if (d > 0 &&  d <= 31)
    {   day = d;
        v= true;
    }
    return (v);
}

//This function will return the month value
int Date::getMonth()const
{   return this-> month;
}


//This function will return the year
int Date::getYear()const
{   return this -> year;
}

//This function will return the Day
int Date::getDay()const
{   return this -> day;
}

//Displays the date
void Date::output(ostream& output) const
{   output << "Date: " << getMonth() << "/" << getDay() 
	<< "/" << getYear();
    output << endl;
}

//Take information from the user and sets to the data member
void Date::input(istream &inp)
{   int month, year, day;
    
     cout << "Enter Year" << endl;
     //Do while will continue to run until user enters right value for year^M
     do{
         inp >> year;
         if (!setYear(year))
             {cout << "Please enter the Year Again" << endl;
             }
     }while(!setYear(year));


    cout << "Enter Month" << endl;
    //This do while will continue to operate if the user doesn't enter correct answer
    do{
    	inp >> month;
        if (!setMonth(month))
            {cout << "Please enter the Month Again" << endl;
            }
    }while(!setMonth(month));

    
    cout << "Enter Day" << endl;
    //Do while will continue to run until user enters right value for day
    do{

        inp >> day;
        if (!setDay(day))
            {cout << "Please enter the Day Again" << endl;
            }
    }while(!setDay(day));
}

