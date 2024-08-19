#include "patientmain.cpp"
#include "doctormain.cpp"
#include "accountant.cpp"

#include<iostream>
using namespace std;
int main(){
    patientmain p1;
    doctormain d1;
    accountant a1;
    int choice;    
     do{
        cout<<"\nEnter option  1 for Admin* "<<endl;
        cout<<"Enter option 2 for General_patient "<<endl;
        cout<<"Enter option 3 for General_Doctor "<<endl;
        cout<<"Enter option 4 for Accountant "<<endl;
        cin>>choice;        
        switch(choice){
           case 1 : cout<< " \n ********** Admin* **********"<<endl;
          // p1.dopatientrelatework();
           break;
           case 2 : cout<<" ********** General_patient **********"<<endl;
           p1.generalpatient();
           break;
           case 3 : cout<<" ********** General_doctor **********"<<endl;
           d1. generaldoctor();
           break;
           case 4: cout<<" ********** Accountant **********"<<endl;
           a1.accoutant();
           default:
           break;
        }
     }while(choice == 1 | choice == 2 | choice == 3 | choice == 4);
    return 0;
}