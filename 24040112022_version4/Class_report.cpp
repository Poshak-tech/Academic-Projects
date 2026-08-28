#pragma once//It will not leave the compiler to make duplicates of the same class.
#include <iostream>
#include <string>
using namespace std;

namespace programming {
/*RunTime Ploymorphism Base Class*/
class Report
{
//member functions
public:
    virtual void print() = 0;//pure virtual function
    virtual ~Report() {}
};//abstract class, which no object can be created. Helpful in polymorphism

}
