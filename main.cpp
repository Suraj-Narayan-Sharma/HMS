
#include "patient.cpp"
#include "doctor.cpp"

#include<iostream>
using namespace std;
    patientmain P1;
    doctormain D1;
    accountant a1;
    patient p1;
    doctor d1;
    string username, password;
 void adminrelatedwork();
 void adminpw();
 void patientpw();
 void doctorpw();
 void accountantpw();
int main(){
   //  patientmain p1;
   //  doctormain d1;
   //  accountant a1;
    int choice;    
     do{
        cout<<"\nEnter option  1 for Admin* "<<endl;
        cout<<"Enter option 2 for General_patient "<<endl;
        cout<<"Enter option 3 for General_Doctor "<<endl;
        cout<<"Enter option 4 for Accountant "<<endl;
        cin>>choice;        
        switch(choice){
           case 1 : cout<< " \n ********** Admin* **********"<<endl;
           adminpw();
           break;
           case 2 : cout<<" ********** General_patient **********"<<endl;
           patientpw();
           break;
           case 3 : cout<<" ********** General_doctor **********"<<endl;
           doctorpw();
           break;
           case 4: cout<<" ********** Accountant **********"<<endl;
            accountantpw();
           default:
           break;
        }
     }while(choice == 1 | choice == 2 | choice == 3 | choice == 4);
    return 0;
}

// function defination for admin
 void adminrelatedwork() {
   //  patientmain p1;
   //  doctormain D1;
   //  accountant a1;
   //  patient p1;
   //  doctor d1;
   int choice ;
        do {
            cout << "\nEnter option 1 for patient " << endl;
            cout << "Enter option 2 for doctor " << endl;
            cout<<"Enter option 3 for General_patient "<<endl;
            cout<<"Enter option 4 for General_Doctor "<<endl;
            cout<<"Enter option 5 for Accountant "<<endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << " \n ********** PATIENT **********" << endl;
                   p1. dopatientrelatework();  // Make sure this method is defined
                    break;
                case 2:
                    cout << "\n ********** DOCTOR **********" << endl;
                    d1.doDoctorRelatedWork();  // Make sure this method is defined
                    break;
                case 3 : cout<<" ********** General_patient **********"<<endl;
                    P1.generalpatient();
                    break;
                case 4 : cout<<" ********** General_doctor **********"<<endl;
                    D1. generaldoctor();
                    break;
                case 5: cout<<" ********** Accountant **********"<<endl;
                    a1.accoutant();
                default:
                    break;
            }
        } while (choice == 1 || choice == 2  || choice == 3 || choice == 4 || choice == 5);
    }

    //for password section

    // * admin password
    void adminpw(){
     
      
      do {
        cout<<" Enter the username for Admin login "<<endl;
        cin>>username;

      if(username == "Admin"){
         do{
             cout<<" \nEnter the password"<<endl;
             cin>>password;
         if(password == "Admin"){
            cout<<" \n\nlogin sucessfully please press Enter "<<endl;
            getch();
            adminrelatedwork();
         }else{
         
          cout<<"\nincorrect passwrod please enter another password "<<endl;
           
         }
           }while(password != "Admin");
        
      }else{
         cout<<"incorrect username please try another username "<<endl;
      }
      }while(username !="Admin"); 
    }

// for password security for general patient .
 void patientpw(){
  do{
   cout<<"Enter the username : ";
   cin>>username;
   if(username == "iamgeneralpatient"){
     do{
       cout<<"Enter the password :";
       cin>>password;
      if(password == "iamgeneralpatient"){
         cout<<"login sucessfully please press enter "<<endl;
         getch();
          P1.generalpatient();
      }else{
         cout<<" incorrect password "<<endl;
      }
     }while(password != "iamgeneralpatient");
   }else{
      cout<<"incorrect username "<<endl;
   }
  }while( username != "iamgeneralpatient");
 }

 // security section of general_doctor
 void doctorpw(){
   do{
      cout<<"Enter the username :";
      cin>>username;
      if(username == "iamaccountant"){
         do{
            cout<<"Enter the password :";
            cin>>password;
            if(password == "iamaccountant"){
               cout<<"login sucessfully please press enter "<<endl;
               getch();
               D1. generaldoctor();
            }else{
               cout<<"incorrect password!!!!!!!!"<<endl;
            }
         }while(password != "iamaccountant");
      }else{
         cout<<"incorrect username !!!!!!!!!!!!"<<endl;
      }
   }while(username != "iamaccountant");
 }

 // security section of accountant
 void accountantpw(){
       do{
      cout<<"Enter the username :";
      cin>>username;
      if(username == "iamaccountant"){
         do{
            cout<<"Enter the password :";
            cin>>password;
            if(password == "iamaccountant"){
               cout<<"login sucessfully please press enter "<<endl;
               getch();
              a1.accoutant();
            }else{
               cout<<"incorrect password!!!!!!!!"<<endl;
            }
         }while(password != "iamaccountant");
      }else{
         cout<<"incorrect username !!!!!!!!!!!!"<<endl;
      }
   }while(username != "iamaccountant");
 }