#pragma once//It will not leave the compiler to make duplicates of the same class.
#include <iostream>
#include <string>
using namespace std;


namespace programming{
class Department
{
//member variables
protected:

    float cost=0,InstituteDep=0,IndividualDep=0,Total=0;

//member functions
public:

    void get_info()
    {
        cout<<"Department helped institute trip cost:"<<endl;
        cin>>InstituteDep;

        cout<<"Department helped individual trip:"<<endl;
        cin>>IndividualDep;

        cout<<"Department expense:"<<endl;
        cin>>cost;

        Total = InstituteDep + IndividualDep + cost;
        cout<<"-------------------------------------------------\n";
    }
    
    //output
    void displayDepartment()
    {
        cout<<"Institute help "<<InstituteDep<<endl;
        cout<<"Individual help "<<IndividualDep<<endl;
        cout<<"Total Department expense cost "<<cost<<endl;
        cout<<"Department total cost "<<Total<<endl;
        cout<<"-------------------------------------------------\n";
    }
};

}
