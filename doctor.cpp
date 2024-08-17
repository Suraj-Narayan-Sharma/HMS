#include "availableon.cpp"
#include "disease.cpp"
#include "main.cpp"

#include "iostream"
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
class doctor : public person{
      private:
      int doctorid;
      Available available;
      disease Disease;
      char doctorFile[20] = "doctorData.dat";
      char doctorTempFile[20] = "doctorData2.dat";

      public: 
      void getdoctordata(){
        cout<<"enter data of doctor "<<endl;
        getpatientdata();

        cout<<"enter doctor Id : ";
        cin>>doctorid;
        cout<<"enter the name of specialization : " ;
        Disease.getdiseasedetail();
        available.whenAvilable();
      }
      void showDoctorData(){
        cout<<"\n \t Details of doctors are : "<<endl;
        cout<<"Doctor Id is : "<<doctorid<<endl;
        showpatientdata();
        Disease.showdiseaselist();
        available.displayavailable();
        cout<<endl;
      }
      
    //adding Doctor data 
    void addDoctorData(){
        getdoctordata();
        ofstream dosctorDatabase(doctorFile, ios::binary | ios::out | ios::app);
        dosctorDatabase.write((char*)this , sizeof(doctor));
    }
    void showDoctorDataFromFile(){
        ifstream readDataFromDatabase(doctorFile, ios:: binary | ios::in);
        while(!readDataFromDatabase.eof()){
            if(readDataFromDatabase.read((char*)this, sizeof(doctor))){              
                cout<<"\t\t Details of doctors"<<endl;
                showpatientdata();
                cout<<"Doctor Id is : "<<doctorid<<endl;
                cout<<"<----------------------------------------------------------->"<<endl;
            }
        }
    }
    void deleteDoctor(){
        int n , flag = 0;
        cout<<"enter the doctorId of the doctor you want to delete ."<<endl;
        cin>>n;

        ifstream ifdoctor;
        ifdoctor.open(doctorFile, ios::binary | ios::in );
        ofstream ofdoctor;
        ofdoctor.open( doctorTempFile, ios::binary | ios::out);
        while(!ifdoctor.eof() ){
            ifdoctor.read((char*)this, sizeof(doctor));
            
            if(ifdoctor){
                if(n == doctorid){
                   flag = 1;
                }else {
                    ofdoctor.write((char*)this, sizeof(doctor));
                }
            }
        }
        ifdoctor.close();
        ofdoctor.close();
        remove(doctorFile);
        rename(doctorTempFile,doctorFile);

        if(flag == 1){
            cout<<"\n Record sucessfully deleted \n";
        }else{
            cout<<" \n Record not found \n";
        }
    }

    void editDoctor(){
        int n , pos, flag = 0;
        cout<<"Enter the doctorId of the doctor you want to delete : ";
        cin>>n;
        
        fstream fdoctor;
        fdoctor.open(doctorFile, ios:: binary | ios :: in | ios::out);

        while(!fdoctor.eof()){
            pos = fdoctor.tellg();
            
            fdoctor.read((char*)this, sizeof(doctor));

            if(fdoctor){
                if(n == doctorid){
                    flag = 1;
                    getdoctordata();

                    fdoctor.seekp(pos);
                    fdoctor.write((char*)this, sizeof(doctor));

                    showDoctorData();
                    break;
                }
            }
        }
        fdoctor.close();
        if(flag == 1){
            cout<<"\n  Record sucessfully modified \n";
        }else{
            cout<<"\n Record not found \n ";
        }
    }
         void doDoctorRelatedWork(){
        char flag;
        int choice;
        do{
            cout<<"enter option 1 to add doctor "<<endl;
            cout<<"enter option 2 to show all data "<<endl;
            cout<<"enter option 3 to delete "<<endl;
            cout<<"enter option 4 to edit doctor's data "<<endl;
            cout<<"enter option 5 to to exit program "<<endl;
            cin>>choice;
            
            if(choice == 1){
                do{
                   addDoctorData();
                    cout<<"add another patient 1 for yes "<<endl;
                }while(flag==1);
            }
            else if (choice== 2){
                showDoctorDataFromFile();
            }
            else if(choice == 3){
               deleteDoctor();
            }
            else if(choice == 4){
                editDoctor();
            }
        }while(choice==1 | choice == 2 | choice == 3 | choice == 4);
     }
};

// int main(){
//     doctor d;
//     d.doDoctorRelatedWork();
//     return 0;
// }
