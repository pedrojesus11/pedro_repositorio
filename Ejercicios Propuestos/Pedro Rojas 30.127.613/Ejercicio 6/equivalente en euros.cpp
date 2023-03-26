#include <iostream>
#include<conio.h>

using namespace std;

int main(){
	int dol;
	float e_eu;
	
	cout<<"Ingrese la cantidad en $"; cin>>dol;
	
	e_eu = dol * 0.93;
	
	cout<<"Su equivalente en euros es: "<<e_eu<<endl;

getch();
return 0;
}
