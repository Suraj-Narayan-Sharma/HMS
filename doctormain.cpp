#include "patient.cpp"

#include<iostream>
using namespace std;
class doctormain: public patient {
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