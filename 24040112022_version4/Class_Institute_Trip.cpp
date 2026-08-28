#pragma once//It will not leave the compiler to make duplicates of the same class.
#include <iostream>
#include <string>
using namespace std;

namespace programming {
class Institute_trip : virtual public TravelRecord
{
//member variables
protected:

    double s=0,B=0,V=0,r=0,TInstitute=0;
    float result=0,D=0,discount=0,total=0;

//member functions
public:
    Institute_trip& operator=(const Institute_trip&) = default;//it allows default assignment operator to work normally.
//As we are using virtual the compiler deletes the assignment operator for safer side and the above statement makes it normal.  

    void get_info()
    {
        cout<<"Enter snacks cost:"<<endl;
        cin>>s;

        cout<<"Enter break cost:"<<endl;
        cin>>B;

        cout<<"Enter institute vehicle cost:"<<endl;
        cin>>V;

        cout<<"Enter campus return cost:"<<endl;
        cin>>r;

        cout<<"Enter discount percent:"<<endl;
        cin>>D;

        result = D/100;

        TInstitute = s+B+V+r;

        discount = TInstitute*result;

        total = TInstitute-discount;
        cout<<"-------------------------------------------------\n";
    }
    
    //output
    void DisplayInstitute_trip()
    {   
        cout<<"Snacks cost:"<<s<<endl;
        cout<<"Break cost:"<<B<<endl;
        cout<<"Institute vehicle cost:"<<V<<endl;
        cout<<"Campus return cost:"<<r<<endl;
        cout<<"Discount amount:"<<discount<<endl;
        cout<<"Institute cost after discount "<<total<<endl;
        cout<<"-------------------------------------------------\n";
    }
};

}
