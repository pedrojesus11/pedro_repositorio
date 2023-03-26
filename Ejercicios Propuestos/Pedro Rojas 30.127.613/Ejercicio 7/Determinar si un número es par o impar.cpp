#include <iostream>
#include<conio.h>

using namespace std;

int main(){
	int num;
	
	cout<<"Ingrese un numero"; cin>>num;
	
	if(num==0){
		cout<<"El numero es 0";	
	}
	
	else if(num%2==0){
		cout<<"El numero es par";
		
	}
	else{
		cout<<"El numero es impar";
	}

getch();	
return 0;
}
