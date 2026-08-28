#include <iostream>
#include <string>
#include <fstream>//file IO stream
using namespace std;

//naive programming
#include "Class_report.cpp"
#include "Class_student.cpp"
#include "Class_TravelRecord.cpp"
#include "Class_Individual_Trip.cpp"
#include "Class_Institute_Trip.cpp"
#include "Class_Department.cpp"
#include "Class_FinalReport.cpp"

namespace pgm = programming;
using namespace pgm;

int main()
{
    Report*       students[50];//abstract class array helps in run time polymorphism
    Final_Report* temps[50];//Final_Report class array
 
    int  total = 0;
    char choice;
 
    //exception handling
    try
    { 
    //user input loop
        do
        {
            int batch;
            cout<<"This program takes one record and calculate for n trips."
            cout<<"\nHow many students do you want to enter? (should be under 50): ";
            cin>>batch;

            //EXCEPTION CHECK
            if(batch <= 0 || total + batch > 50)
                throw "Invalid number of students!";
 
            for(int i = total; i < total + batch; i++)
            {
                cout<<"\nEntering details for student "<<i+1<<endl;
                
                cin.ignore();//removes extra white spaces
                temps[i]    = new Final_Report();//using dynamic memory allocation
                students[i] = temps[i];
 
                temps[i]->Total_trips();
                temps[i]->Individual_Trip::get_info();
                temps[i]->Institute_trip::get_info();
                temps[i]->Department::get_info();
            }
 
            total += batch;//total this variable is used for proper indexing of next records.
            //asking user for more inputs
            cout<<"\nDo you want to enter more students? (y/n): ";
            cin>>choice;
 
        } while(choice == 'y' || choice == 'Y');
 
 
        cout<<"\n========= FINAL REPORT =========\n";
        
         //printing final report using report array.
        for(int i = 0; i < total; i++)
        {
            students[i]->print();
        }
        
        //static function used
        Student::showStudentCount();
 
 
        //OPERATOR OVERLOADING used
        if(total >= 2)
        {
          int combinedTotal = temps[0]->GrandTotal + temps[1]->GrandTotal;

          cout<<"\nCombined Report of first two students:\n";
          cout<<"Combined Grand Total: "<< combinedTotal <<endl;
        }
 
 
        // ================= FILE HANDLING =================
        ofstream fout("report.txt");//fout is a object

        if(!fout)
            throw "File could not be opened!";//exception case handled

        fout<<"FINAL REPORT DATA\n";

        for(int i = 0; i < total; i++)
        {
            fout<<"Student "<<i+1<<" Grand Total: " <<temps[i]->GrandTotal<<endl;
        }

        fout.close();//closing of writing file

        cout<<"\nData written to file successfully!\n";


        // ===== READ FILE =====
        ifstream fin("report.txt");//object fin

        if(!fin)
            throw "Error reading file!";

        string line;//variable created

        cout<<"\nReading from file:\n";
        while(getline(fin, line))
        {
            cout<<line<<endl;
        }

        fin.close();//closing of reading file
 
 
        //freeing used array and variables which are dynamic in nature 
        for(int i = 0; i < total; i++)
        {
            delete students[i];//Report has virtual destructor
            students[i] = nullptr;
            temps[i]    = nullptr;
        }
    }
 
    // ================= EXCEPTION HANDLING =================
    catch(const char* msg)
    {
        cout<<"Exception: "<<msg<<endl;
    }
    catch(...)
    {
        cout<<"Unknown error occurred!"<<endl;
    }
 
    return 0;
}
