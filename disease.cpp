#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class disease{
    private:
    char diseaseName[25], virusname[25];

    public:
    void getdiseasedetail(){
        cout<<"\n enter the name of disease : "<<endl;
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
