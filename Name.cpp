//Name: Reham Islam
//Professor Papadakis
//This is a source file for Date.h


#include <iostream>
using namespace std;

#include "Name.h"
istream& operator>>(istream &in, Name& name)
{  	 name.input(in);
	return(in);
}

ostream& operator<<(ostream &out, const Name& name)
{   name.display(out);
	return(out);   
}


Name::Name()
{   setLname("N/A");
    setFname("N/A");
    setMi('X');
}

Name::Name(string f, char m, string l)
{   setLname(l);
    setFname(f);
    setMi(m);
}

void Name::setLname(const string l)
{   lName = l;
}

void Name::setFname(const string f)
{   fName = f;
}

void Name::setMi(const char m)
{   mi = m;
}

string Name::getLname() const
{   return lName;
}

string Name::getFname() const
{   return fName;
}

char Name::getMi() const
{   return mi;
}

void Name::display(ostream& out) const
{   out << getFname() << " " << getMi() << " " << getLname();
    out << endl;
}

Name& Name::operator=(const Name &k)
{	cout << " mmm" <<endl;
	this -> fName = k.getFname(); 
	cout << "bbb" << endl;
	this -> lName = k.getLname();
	this-> mi = k.getMi();
	cout << "LL" << endl;
	return(*this);
}

void Name::input(istream& inp)
{
    string f, l;
    char m;

    cout << "Please Enter First Name: " ;
    inp >> f;
    setFname(f);
    
    cout << "Please Enter last Name: " ;
    inp >> l;
    setLname(l);

    cout << "Please Enter Middle initial: ";
    inp >> m;
    setMi(m);
}
/*
int main()
{   
    Name k;
    Name R("R", 'K', "L");
    Name S(R);
    cout << "Name using Default Constuctor: " ;
    cout << k;
    cout << "\nUpdate Default Contructor" << endl;
    cin >> k;
    cout << "\nUpdated Default Constructor: ";
    cout << k;
    cout << "\nName using Custom Constructor: " ;
    cout << R;
    cout << "\nCopy Constructor: ";
    cout << S;


}*/
