//Reham Islam
//This is a header file for the Date Class
//Date Class will represent  value for the Date

#include <iostream>
using namespace std;


#ifndef DATE_H
#define DATE_H

class Date
{   friend istream& operator>>(istream&, Date&);
    friend ostream& operator<<(ostream&, Date&);
    public:
        Date(int = 1, int = 12);
	Date(int, int, int);
	Date(const Date& );

	bool setMonth(int m);
        bool setYear(int y);
        bool setDay(int d);

        int getMonth() const;
        int getYear() const;
        int getDay() const;
	
	bool operator==(const Date&) const;
	bool operator!=(const Date&)const;
	const Date& operator=(const Date&);
	


    private:
        int month, year, day; 
	const int MIN; 
        const int MAX;

	void output(ostream&) const;
	void input(istream&);


};

#endif // DATE_H

