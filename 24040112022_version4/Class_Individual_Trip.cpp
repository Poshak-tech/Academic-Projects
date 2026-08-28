#pragma once//It will not leave the compiler to make duplicates of the same class.
#include <iostream>
#include <string>
using namespace std;

namespace programming {
/*Use virtual inheritance to prevent a function copy more than once for diamond problem*/

class Individual_Trip : virtual public TravelRecord
{
//member variables
protected:

    float d=0,p=0,v=0,f=0,af=0,b=0,P=0;
    float total=0;
//member functions
public:
    Individual_Trip& operator=(const Individual_Trip&) = default;//it allows default assignment operator to work normally.
//As we are using virtual the compiler deletes the assignment operator for safer side and the above statement makes it normal.  
    
    void get_info()
    {
        cout<<"Enter due:"<<endl;
        cin>>d;

        cout<<"Enter penalty percent:"<<endl;
        cin>>p;

        P=p/100;

        cout<<"Enter days late:"<<endl;
        cin>>af;

        b = d*P*af;

        cout<<"Enter vehicle cost:"<<endl;
        cin>>v;

        cout<<"Enter food cost:"<<endl;
        cin>>f;

        total = d+b+v+f;
        cout<<"-------------------------------------------------\n";
    }
  //output
    void DisplayIndividual_Trip()
    {
        cout<<"Due "<<d<<endl;
        cout<<"Penalty "<<b<<endl;
        cout<<"Vehicle "<<v<<endl;
        cout<<"Food "<<f<<endl;
        cout<<"Total individual trip "<<total<<endl;
        cout<<"-------------------------------------------------\n";
    }

    friend class Department;
};

}

