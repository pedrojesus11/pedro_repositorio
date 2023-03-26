#include <iostream>
#include<conio.h>

using namespace std;

int main(){
	float n1, n2, n3, nota_final = 0;
	
	cout<<"Ingrese la nota 1"; cin>>n1;
	cout<<"Ingrese la nota 2"; cin>>n2;
	cout<<"Ingrese la nota 3"; cin>>n3;
	
	n1 = n1 * 0.40;
	n2 = n2 * 0.40;
	n3 = n3 * 0.20;
	
	nota_final = n1 + n2 + n3; 
	
	cout<<"la nota final es: "<<nota_final<<endl;
	
getch();	
return 0;
}
