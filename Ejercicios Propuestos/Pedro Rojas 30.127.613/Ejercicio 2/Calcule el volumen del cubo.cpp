#include <iostream>
#include<conio.h>

using namespace std;

int main(){
	float arista, volumen_del_cubo;
	
	cout<<"Ingrese la arista del cubo"; cin>>arista;
	
	volumen_del_cubo = arista * arista * arista;  
	
	cout<<"el volumen del cubo es: "<<volumen_del_cubo<<endl;

getch();
return 0;
}
