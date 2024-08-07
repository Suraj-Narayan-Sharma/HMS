#include<iostream>
#include<graphics.h>
using namespace std;
class demo{

private : 
char name[20];
int age , Id;
public:
void getdata(){
    cout<<"enter the name of patient : ";
    cin>>name;
    cout<<"\n enter the age : ";
    cin>>age;
    cout<<"\n enter the Id : ";
    cin>>Id;

}
void dispalydata(){
    cout<<"\n \n----------------------------------------------------------------"<<endl;
    cout<<"name :"<<name<<endl;
    cout<<"age : "<<age<<endl;
    cout<<"id : "<<Id <<endl;
    
}
};
// int main(){
//    initwindow(1366,768,"usr interface ");
//    readimagefile("background.jpeg",0,0,1366,768);
//    rectangle(1000,600,1200,700);
//     demo d;
//     d.getdata();
//     d.dispalydata();
//     return 0;
// }
