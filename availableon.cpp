#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;
class Available{
    private:
    char Dayofweek[15][7], shift1[25], shift2[25];
    int i, noD;
    public:
    void whenAvilable(){
        cout<<"enter no of available days 1-7"<<endl;
        cin>>noD;
        while((noD >=1) && (noD > 7)){
            cout<<"error ! The number you have enered is out of range : "<<endl;
            cout<<"enter the number between  1 - 7 : "<<endl;
            cin >> noD;
        }
        cout<<"enter "<<noD<<"days of week for Doctor available "<<endl;
        for ( i = 0; i< noD ; i++){
            cin>>Dayofweek[i];
        }
        cout<<"enter Dr.fist shift : "<<endl;
        cin >>shift1;
        cout<<"enter Dr.secont shift : "<<endl;
        cin>>shift2;
    }
    void displayavailable(){
        time_t rawtime;
        struct tm * timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        cout<<"\n ************************************************************\n"<<endl;
        cout<<"local time : "<<endl;
        cout<<asctime(timeinfo); 
        cout<<"Dr.is available for "<<noD<<"days in week "<<endl;
        cout<<"** availabale days are ** "<<endl;
        for(i=0; i<noD; i++){
            cout<<Dayofweek[i]<<endl;
        }
        cout<<"** Dr.shift are ** "<<endl;
        cout<<shift1<<endl;
        cout<<shift2<<endl;
    }
};
// int main(){
//     Available a1;
//     a1.whenAvilable();
//     a1.displayavailable();
//     return 0;
// }