
#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class disease{
    private:
    char diseaseName[25], virusname[25];

    public:
    void getdiseasedetail(){
        cout<<"ener the name of disease : "<<endl;
        cin >>diseaseName;
        cout<<"enter the name of virus :"<<endl;
        cin>>virusname;
    }

    void showdiseaselist(){
        cout<<endl;
        cout<<"*****Disease  :" << diseaseName<<"*****"<<endl;
        cout<<"virus name : "<<virusname<<endl;

    }
};
// int main(){
//     disease d;
//     d.getdiseasedetail();
//     d.showdiseaselist();
//     return 0;
// }