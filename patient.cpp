#include "main.cpp"
#include "disease.cpp"
#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
class patient: public person {
     private:
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
         cout<<"----patient data----"<<endl;
         cout<<"patinet Id : "<<patienId<<endl;
         showpatientdata();
         Disease.showdiseaselist();
         cout<<"appointment data : "<<appointDate;
     }
     void showpatientDataFromFile(){
        ifstream readdataformdatabase( patientFile, ios::binary | ios::in);
        while(!readdataformdatabase.eof()){
            if(readdataformdatabase.read((char*)this,sizeof(patient))){
                showpatientdata();
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
     void editPatient(){
        int n , pos, flag = 0;
        cout<<"\n enter the ID of patient you want to edit "<<endl;
        cin>>n; 

        fstream fpatient ;
        fpatient.open(patientFile, ios::binary | ios::in | ios::out);
        while(!fpatient.eof()){
            fpatient.read((char*)this , sizeof(patient));
            if(fpatient){
                if(n == patienId){
                    flag = 1;

                    getPatientInfo();
                    
                    fpatient.seekp(pos);
                
                fpatient.write((char*)this, sizeof(patient));
                showpatientdata();
                break;
                }
            }
        }
        fpatient.close();
        if(flag = 1){
            cout<<"Record is sucessfully modifiend "<<endl;

        }
        else{
            cout<<" Record not found"<<endl;
        }

     }
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


// int main(){
//     patient p;
//     p.dopatientrelatework();
//     return 0;
// }