#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	float azucar = 3, cafe = 0.72, Dolar, k_azucar = 0, k_cafe = 0, d_sobrante = 0;
	
	cout<<"Ingrese la cantidad de $ disponible"; cin>>Dolar;
	
	k_azucar = (Dolar / 2) / azucar;
	k_cafe = (Dolar / 2) / 3 / cafe;
	d_sobrante = (Dolar / 2) / 3;
	
	cout<<"Se puede comprar de azucar: "<<k_azucar<<endl;
	cout<<"Se puede comprar de cafe: "<<k_cafe<<endl;
	cout<<"Dinero sobrante: "<<d_sobrante<<endl;
	
	getch();
	return 0;
}


	
