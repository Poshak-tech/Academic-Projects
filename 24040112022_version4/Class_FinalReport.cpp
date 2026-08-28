#pragma once//It will not leave the compiler to make duplicates of the same class.
#include <iostream>
#include <string>
using namespace std;

namespace programming {
class Final_Report :public Individual_Trip, public Department, public Institute_trip, public Report
{

//member functions and variables
public:
    int GrandTotal = 0;
    void calcGrandTotal();
    
    void print() override
    {
        float grand_total;

        cout<<"\n.....Final Report......"<<endl;

        Student::display();
        cout<<"-------------------------------------------------\n";
        
        Display_details(*this);

        DisplayIndividual_Trip();

        DisplayInstitute_trip();
        
        displayDepartment();

        calcGrandTotal();
    }
    //operator overloading is a concept were the user can define the operator by his intervention.
    Final_Report operator+(Final_Report &obj)
    {
      Final_Report temp = *this;

      temp.GrandTotal += obj.GrandTotal;

      return temp;
    }
};

//inline request
inline void Final_Report::calcGrandTotal() {
    GrandTotal = (Individual_Trip::total + this->Institute_trip::total) * TravelRecord::total + Department::Total;
    cout<<"Grand total expense "<<GrandTotal<<endl;
    cout<<"-------------------------------------------------\n";
}

}
