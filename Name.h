#include <iostream>
using namespace std;

#ifndef NAME_H
#define NAME_H

class Name
{
    friend istream& operator>>(istream&, Name&);
    friend ostream& operator<<(ostream&, const Name&);
    public:
        Name();
        Name(string, char, string);

        void setLname(const string l);
        void setFname(const string f);
        void setMi(const char m);
	
	Name& operator=(const Name&);

        string getLname() const;
        string getFname()const;
        char getMi() const;


    private:
        string fName;
        string lName;
        char mi;

	void display(ostream&)const;
        void input(istream&) ;

};

#endif // NAME_H
