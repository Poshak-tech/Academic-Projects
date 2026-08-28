#pragma once//It will not leave the compiler to make duplicates of the same class.
#include <iostream>
#include <string>
using namespace std;

namespace programming {
class Student
{
//member variables
protected:
    string name_of_student;
    string class_of_student;
    string branch_of_campus;
    int regno;

    static int student_count;//static variable.
//member functions
public:
    Student()//Constructor used
    {
        student_count++;

        cout<<"Enter the student name:"<<endl;
        getline(cin,name_of_student);

        cout<<"Enter the class of the student:"<<endl;
        getline(cin,class_of_student);

        cout<<"Enter the branch of the campus:"<<endl;
        cin>>branch_of_campus;

        cout<<"Enter the regno:"<<endl;
        cin>>regno;

        cout<<"-------------------------------------------------\n";
    }

    void display()
    {
        cout<<"Student name:"<<name_of_student<<endl;
        cout<<"Class:"<<class_of_student<<endl;
        cout<<"Branch:"<<branch_of_campus<<endl;
        cout<<"Register number:"<<regno<<endl;
    }

    static void showStudentCount()//This function keeps the count of no of students entered.
    {
        cout<<"Total students entered: "<<student_count<<endl;
    }//static function
};

int Student::student_count = 0;//static member defined

}

