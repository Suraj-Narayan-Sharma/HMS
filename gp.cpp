#include <graphics.h>
#include<iostream>
#include <conio.h>
#include "forcheck.cpp"
using namespace std;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	circle(200,200,100);
	demo d1;
	d1.getdata();
	getch();
	closegraph();
    return 0;
} 