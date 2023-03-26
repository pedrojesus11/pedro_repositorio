#include <iostream>
#include<conio.h>

using namespace std;

int main(){
	int n1, n2, n3;
	
	cout<<"Ingrese un numero"; cin>>n1;
	cout<<"Ingrese otro numero"; cin>>n2;
	cout<<"Ingrese otro numero"; cin>>n3;
	
	if(n1>n2 && n1>n3){
		cout<<"El mayor es: "<<n1;	
	}
	
	else if(n2>n1 && n2>n3){
		cout<<"El mayor es: "<<n2;
		
	}
	else if(n3>n1 && n3>n2){
		cout<<"El mayor es: "<<n3;
	}
	else if(n1==n2 && n1==n3){
		cout<<"Lo tres numeros son iguales";
	}

getch();	
return 0;
}
