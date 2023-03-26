#include <iostream>
#include<conio.h>

using namespace std;

int main(){
	float h, min, seg, seg_pas = 0;
	
	cout<<"Ingrese las horas"; cin>>h;
	cout<<"Ingrese los minutos"; cin>>min;
	cout<<"Ingrese los segundos"; cin>>seg;
	
	h = h * 3600;
	min = min * 60;
	seg = seg / 60;
	
	seg_pas = h + min + seg; 
	
	cout<<"segundos han pasado desde las 0:0:0 horas: "<<seg_pas<<endl;

getch();
return 0;
}
