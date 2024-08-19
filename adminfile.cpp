// This is admin section 
//<------for geneeral access purposes files----=->
#include "patientmain.cpp"
#include "doctormain.cpp"
#include "accountant.cpp"

//<-----this is the file for everything setting ------>
#include "patient.cpp"
#include "doctor.cpp"

#include<istream>
using namespace std;

//class for option 
class admin:  public doctor, public patientmain, public doctormain, public accountant{
   private: 
   int choice;
   
   public:
   //function for general option 
void generalaccess(){
do{
        // for option .
cout<<"***** In this section you can have general access*****"<<endl;
cout<<"--------------------------------------------------------"<<endl;
cout<<"Enter the option 1 for general patient "<<endl;
cout<<"Enter the option 2 for general Doctor "<<endl;
cout<<"Enter the option 3 for general Accountant"<<endl;
cout<<"--------------------------------------------------------"<<endl;
cin>>choice;

     switch (choice)
     {
     case 1: cout<<"\n*******  patient_section  *********"<<endl;
       generalpatient();
        break;
     case 2: cout<<"\n*******  doctor_section  *********"<<endl;
       generaldoctor();
       break;
     case 3: cout<<"\n*******  Accountant_section  *********"<<endl;
       accoutant();
       break;
     default:
        break;
     }

}while (choice ==1 | choice ==2 | choice ==3);

}
//void  dopatientrelatework(){}

   //  funtion for everything access
   void everythingaccess(){
      patient p;
    cout<<"\n\n"<<endl;
    cout<<"************ In this section you can save proper action of everysettings *****"<<endl;
     do{
        cout<<"\nEnter option  1 for patient "<<endl;
        cout<<"Enter option 2 for doctor "<<endl;
        cin>>choice;        
        switch(choice){
           case 1 : cout<< " \n ********** PATIENT **********"<<endl;
           p.dopatientrelatework();
           break;
           case 2 : cout<<"\n ********** DOCTOR **********"<<endl;
           doDoctorRelatedWork();
           break;
           default:
           break;
        }
     }while(choice == 1 | choice == 2);
   }
};

int main(){

    int choice ;
   //   //function for general option 
   //  patientmain gen;
   //  doctormain  doc;
   //  accountant  acc;
 
   // //  funtion for everything access
   // patient p1;
   // doctor d1; 
   admin A;

   do{

    cout<<"Enter 1 if you want to general access "<<endl;
    cout<<"Enter 2 if you want to everything access"<<endl;
    cin >>choice;
    switch (choice)
    {
    case 1 : cout<<"\n**********general access*********"<<endl;
          A.generalaccess();
        break;
    case 2 : cout<<"********* Everything access ***********"<<endl;
          A.everythingaccess();
        break;
    
    default:
        break;
    }
   }while ((choice == 1 | choice==2));

    return 0;
}