#include <iostream>
#include<conio.h>

using namespace std;

int main(){
	int v1, v2;
	
	cout<<"Ingrese v1"; cin>>v1;
	cout<<"Ingrese v2"; cin>>v2;
	
	v1 = v1 + v2;
	v2 = v1 - v2;
	v1 = v1 - v2;
	
	cout<<"v1: "<<v1<<endl;
	cout<<"v2: "<<v2<<endl;

getch();	
return 0;
}
