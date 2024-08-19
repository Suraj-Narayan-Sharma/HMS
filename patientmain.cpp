#include "patient.cpp"

#include<iostream>
using namespace std;
// main funtion 
class patientmain: virtual public  patient{
    private:
    int ch;
     
    public:
    void generalpatient(){
      do{
        cout<<"\n Enter 1 for Patient new registration "<<endl;
        cout<<" Enter 2 for Patient registered details"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"****** self register ******"<<endl;
        addPatient();
        break;
        case 2: cout<<"****** self Details ******"<<endl;
        showpatientDataFromFile();
        break; 
        default:
        break;
        }
    }while(ch == 1 | ch == 2);
    }
};