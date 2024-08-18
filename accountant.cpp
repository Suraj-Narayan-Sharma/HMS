
#include "patient.cpp"

#include<iostream>
using namespace std;
class accountant: public patient{
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
     case 3: cout<<"********* Do payment*********"<<endl;
        payment();
        break;
     default:
        break;
     }
    }while(ch == 1 | ch == 2 | ch==3);
   }
};