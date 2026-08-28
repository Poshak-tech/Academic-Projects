#pragma once//It will not leave the compiler to make duplicates of the same class.
#include <iostream>
#include <string>
using namespace std;

namespace programming {
/* Virtual inheritance to avoid duplicate Student*/

/*Diamond problem:-Here if two class inherits the same base class. Which result in copy the same class twice. To avoid that virtual is used. And at last those two classes which will be inherited by a class*/
class TravelRecord : virtual public Student//virtual is used for ambiguity
{
//member variables
protected:
    int n=0,a=0;

//member functions
public:
    int total = 0;
    TravelRecord& operator=(const TravelRecord&) = default;//it allows default assignment operator to work normally.
//As we are using virtual the compiler deletes the assignment operator for safer side and the above statement makes it normal.  
    
    void Total_trips()
    {   
        cout<<"Enter total trips including your personal trips and mention how many times it was a personal (extra trips):"<<endl;
        cout<<"Enter the total trips:"<<endl;
        cin>>n;

        cout<<"Enter extra trips:"<<endl;
        cin>>a;
        total = n;
        cout<<"-------------------------------------------------\n";
    }

    friend void Display_details(TravelRecord &);//Here we are giving the address of object declared.(friend function)
    friend class Department;
};

void Display_details(TravelRecord &t)//Friend function defined.
{
    cout<<"Total trips "<<t.total<<endl;
    cout<<"Extra trips "<<t.a<<endl;
    cout<<"-------------------------------------------------\n";
}

}

