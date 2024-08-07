
#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class person{
    private:
    int age;
    char name[25], address[25], email[25], phoneNo[10];
    public:
    void getpatientdata(){
        cout<<"enter name" <<endl;
        cin>>name;
        cout<<"enter age"<<endl;
        cin>>age;
        cout<<"enter address"<<endl;
        cin>>address;
        cout<<
        "enter email"<<endl;
        cin>>email;
        cout<<"enter phoneNo"<<endl;
        cin>>phoneNo;
    }
    void showpatientdata(){
        cout<<"<----------------------------------------------------------->"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"age  : "<<age<<endl;
        cout<<"address: "<<address<<endl;
        cout<<"email : "<<email<<endl;
        cout<<"phoneNO : "<<phoneNo<<endl;
    }
};
// int main(){
//      person p1;
//      p1.getpatientdata();
//      p1.showpatientdata();
//     return 0;
// }