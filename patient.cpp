#include "person.cpp"
#include "disease.cpp"
#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

class patient: public person {
     private:
     int billamount = 0;
     int patienId;
     disease Disease;
     string appointDate;
     char patientFile[20] = "patinetData.dat";
     char patinetTempFile[20] = "patientData2.dat";

     public:
     void getPatientInfo(){
       cout<<"enter the data for person "<<endl;
       getpatientdata();

       cout<<"Disease details "<<endl;
       Disease.getdiseasedetail();
       cout<<"Appoint data : ";
       cin>>appointDate;
     }
     void addPatient(){
        cout<<"patint_Id : ";
        cin>>patienId;
        getPatientInfo();
        ofstream patientDatabase(patientFile, ios::binary | ios:: out | ios:: app);
         
         patientDatabase.write((char*)this, sizeof(patient));
        //  cout<<"-------------patient data---------------"<<endl;
        //  cout<<"patinet Id : "<<patienId<<endl;
        //  showpatientdata();
        //  Disease.showdiseaselist();
        //  cout<<"appointment data : "<<appointDate;
     }
      //add bill amount
     void addpatientamount(){  
         int id;
        cout<<"Enter the id number of patient for billing ."<<endl;
        cin>>id;       
        ifstream ifpatinet;
        ifpatinet.open(patientFile, ios::in | ios:: binary);
        while(!ifpatinet.eof()){
            ifpatinet.read((char*)this , sizeof(patient));
           
        }
         if(patienId == id){
              cout<<"Enter the  Bill amount"<<endl;
              cin>>billamount;
              ofstream patientDatabase(patientFile, ios::binary | ios:: out | ios:: app);
              patientDatabase.write((char*)this, sizeof(patient));
            }else{
                cout<<"-------Record not found!!!!!!!-------"<<endl;
                return ;
            }
        
     }   

    //to check bill amount
    void checkbill(){
        
         int id;
        cout<<"Enter the patientID for Bill amount checking ."<<endl;
        cin>>id;       
        ifstream ifpatinet;
        ifpatinet.open(patientFile, ios::in | ios:: binary);
        while(!ifpatinet.eof()){
            ifpatinet.read((char*)this , sizeof(patient));
           
        }
         if(patienId == id){
             cout<<" Bill amount :"<<billamount<<endl;
            }else{
                cout<<"-------Record not found!!!!!!!-------"<<endl;
                return ;
            }
    }
    // to pay the bill amount 
    void payment(){
         int id,paidamount;
        cout<<"Enter the patientID for pay Bill amount  ."<<endl;
        cin>>id;       
        ifstream ifpatinet;
        ifpatinet.open(patientFile, ios::in | ios:: binary);
        while(!ifpatinet.eof()){
            ifpatinet.read((char*)this , sizeof(patient));
           
        }
         if(patienId == id){
            cout<<"enter the amount you want to pay : "<<endl;
            cin>>paidamount;
            cout<<" Unpaid Bill amount :"<<billamount<<endl;
            billamount  = billamount - paidamount;
            //code for upadating the billing section in the file            
            ofstream patientDatabase(patientFile, ios::binary | ios:: out | ios:: app);
            patientDatabase.write((char*)this, sizeof(patient));
             cout<<" paid amount : "<<paidamount<<endl;
             cout<<" after the paymet "<<endl;
             cout<<" Unpaid Bill amount :"<<billamount<<endl;
            }else{
                cout<<"-------Record not found!!!!!!!-------"<<endl;
                return ;
            }
    }
     void showpatientDataFromFile(){
        ifstream readdataformdatabase( patientFile, ios::binary | ios::in);
        while(!readdataformdatabase.eof()){
            if(readdataformdatabase.read((char*)this,sizeof(patient))){
                showpatientdata();
                cout<<"patient ID: "<<patienId<<endl;
            }
        }
     }
     void dischargepatient(){
        int n , flag = 0;
        cout<<"\n Enter the id of the patient you want to dischage : "<<endl;
        cin>>n;
        ifstream ifpatinet;
        ifpatinet.open(patientFile, ios::in | ios:: binary);

        ofstream ofpatient ;
        ofpatient.open(patinetTempFile, ios::out | ios::binary);
        while(!ifpatinet.eof()){
            ifpatinet.read((char*)this , sizeof(patient));
            if( ifpatinet){
                if(n==patienId)
               { 
                flag = 1;
                }else {
                ofpatient.write((char*)this,sizeof(patient));
            }
            
            }
        }
        ifpatinet.close();
        ofpatient.close();
        remove(patientFile);
        rename(patinetTempFile, patientFile);
        
        if(flag == 1){
            cout<<"\n Record sucessfully deleted \n"<<endl;
        }
        else{
            cout<<"\n record not found \n";
        }

     }
     void editPatient() {
    int n, pos, flag = 0;
    cout << "\nEnter the ID of the patient you want to edit: " << endl;
    cin >> n;

    fstream fpatient;
    fpatient.open(patientFile, ios::binary | ios::in | ios::out);  // ios::out instead of ios::app

    if (!fpatient) {
        cout << "File could not be opened." << endl;
        return;
    }

    while (!fpatient.eof()) {
        pos = fpatient.tellg();  // Get the current position of the "get" pointer
        fpatient.read((char*)this, sizeof(patient));
        if (fpatient) {
            if (n == patienId) {
                flag = 1;

                getPatientInfo();  // Modify the patient info

                fpatient.seekp(pos);  // Move the "put" pointer to the correct position
                fpatient.write((char*)this, sizeof(patient));

                showpatientdata();  // Display the modified data
                break;
            }
        }
    }

    fpatient.close();

    if (flag == 1) {
        cout << "Record is successfully modified." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}
//for doing patient related work
     void dopatientrelatework(){
        char flag;
        int choice;
        do{
            cout<<"enter option 1 to add patinet "<<endl;
            cout<<"enter option 2 to show all data "<<endl;
            cout<<"enter option 3 to discharge  patinet "<<endl;
            cout<<"enter option 4 to edit patinet's data "<<endl;
            cout<<"enter option 5 to to exit program "<<endl;
            cin>>choice;
            
            if(choice == 1){
                do{
                    addPatient();
                    cout<<"add another patient 1 for yes "<<endl;
                }while(flag==1);
            }
            else if (choice== 2){
                showpatientDataFromFile();
            }
            else if(choice == 3){
                dischargepatient();
            }
            else if(choice == 4){
                editPatient();
            }
        }while(choice==1 | choice == 2 | choice == 3 | choice == 4);
     }
};
// patientmin bala
class patientmain:  public  patient{
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

// doctor main bala 
class doctormain:  public patient {
    private :
    int choice ;

    public:
    void generaldoctor(){
    do{
        cout<<"Enter option 1 for see the patient condtion"<<endl;
        cout<<"Enter option 2 for Modify patient condition detail"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1: cout<<"*****Patient condition*****"<<endl;
        showpatientDataFromFile();
        break;
        case 2: cout<<"*****Modify status*****"<<endl;
        editPatient();
        break; 
        default:
        break;
        }
    }while(choice == 1 | choice == 2);
    }
};

// accountant bala 
class accountant:  public patient{
   private:
   int ch;

   public:
   void accoutant(){
      do{
     cout<<"\n Enter the option 1 for add bill amount"<<endl;
     cout<<" Enter the option 2 for check bill amount"<<endl;
     cout<<" Enter the option 3 for payment "<<endl;
     cin>>ch;
     switch (ch)
     {
     case 1: cout<<"********* Add Bill *********"<<endl;
        addpatientamount();
        break;
     case 2: cout<<"*******  Bill  Details *****"<<endl;
      checkbill();
        //pp2.showpatientDataFromFile();
        break;
     case 3: cout<<"********* Do payment *********"<<endl;
        payment();
        break;
     default:
        break;
     }
    }while(ch == 1 | ch == 2 | ch==3);
   }
};

// portio of admin 
class admin : patient{
    
};