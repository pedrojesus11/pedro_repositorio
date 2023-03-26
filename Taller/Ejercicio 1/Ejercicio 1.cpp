/*Ejercicio 1*/ /*Jose Gonzlez, Pedro Rojas, Gustavo Perez*/

#include<stdio.h>
#include <conio.h>


int main(){
   int n, num, i, aux, tem, cont_0 = 0, par = 0, impar = 0, primo = 0;
   
   printf("Ingrese la cantidad de numeros que desea ingresar: \n");
   scanf("%d", &n);

   for ( i = 1; i <= n; i++){

    printf("Ingrese el numero: \n");
    scanf("%d", &num);

    if(num % 2 == 0){
        par++;
    }else{
        impar++;
    }

    int j, es_primo = 1;
    for ( j = 2; j < num; j++){
        if (num % j == 0){
            es_primo = 0;
            break;
        }
    }
    if(es_primo && num > 1){
        primo++;
    }

    aux = num;
    do{
        tem = aux % 10;
        aux = aux / 10;
        if(tem == 0){
            cont_0++;
        }
    } while (aux != 0);
    
   }
   printf("cantidad de numeros pares: %d\n", par);
   printf("cantidad de numeros impares: %d\n", impar);
   printf("cantidad de numeros primos: %d\n", primo);
   printf("cantidad de ceros: %d\n", cont_0);
   
   getch();
   return 0;
   
}
