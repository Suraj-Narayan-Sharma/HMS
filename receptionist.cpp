#include "patient.cpp"
#include "doctor.cpp"
int main(){
    patient p1;
    doctor d1;   
     int choice;    
     //getch();
     do{
        cout<<"\nEnter optin  1 for patient "<<endl;
        cout<<"Enter option 2 for doctor "<<endl;
        cin>>choice;        
        switch(choice){
           case 1 : cout<< " \n ********** PATIENT **********"<<endl;
           p1.dopatientrelatework();
           break;
           case 2 : cout<<"\n ********** DOCTOR **********"<<endl;
           d1.doDoctorRelatedWork();
           break;
           default:
           break;
        }
     }while(choice == 1 | choice == 2);
     return 0;
}