/*Ejercicio 2*/ /*Jose Gonzlez, Pedro Rojas, Gustavo Perez*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int genero, i, n, masculino = 0, femenino = 0, edad, mayor_ed = 0, menor_ed = 0, dia, mes, anio, ci, desc_f = 0, desc_m = 0;
    
    printf ("\n Ingrese la cantidad de pacientes: ");
    scanf ("%d", &n);
    
	for (i=1; i<=n; i++)
    
	{
        printf ("\n Paciente %d\n", i);
        printf ("Selecciona el genero.\n");
        printf ("\t1.- femenino\n");
        printf ("\t2.- masculino\n");
        printf ("\t: ");
		do {
            scanf ("%d", & genero);
            if (genero < 1 || genero > 2)
                printf ("\n Valor incorrecto. Ingresalo nuevamente.: ");
            }	 
        while (genero < 1 || genero > 2);
        if (genero == 1)
            femenino = femenino + 1;
        else
            masculino = masculino + 1;
        putchar ('\n');
        printf("\n Ingrese la cedula de identidad del paciente: ");
        scanf("%d", &ci);
        if (ci % 2 == 0 && femenino)
         desc_f = desc_f + 1;
         if (masculino == edad > 60)
         desc_m = desc_m + 1;

        printf( "\n   Ingrese la edad del paciente: " );
        scanf( "%d", & edad );
        if(edad >= 18)
            mayor_ed = mayor_ed + 1;
        else
            menor_ed = menor_ed + 1;
        putchar ('\n');
        
        printf("\n Ingrese la fecha de nacimiento del paciente:");
        printf("\n Dia: ");
        scanf( "%d", &dia);
        printf("\n Mes: ");
        scanf( "%d", &mes);
        printf("\n Anio: ");
        scanf( "%d", &anio);
        if ( mes >= 1 && mes <= 12 )
    {
    	
        switch ( mes )
        {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 : if ( dia >= 1 && dia <= 31 )
                          printf( "\n   LA FECHA ES CORRECTA" );
                      else
                          printf( "\n   LA FECHA ES INCORRECTA" );
                      break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : if ( dia >= 1 && dia <= 30 )
                          printf( "\n   LA FECHA ES CORRECTA" );
                      else
                          printf( "\n   LA FECHA ES INCORRECTA" );
                      break;

            case  2 : if( anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0 )
                          if ( dia >= 1 && dia <= 29 )
                              printf( "\n   LA FECHA ES CORRECTA" );
                          else
                              printf( "\n   LA FECHA ES INCORRECTA" );
                      else
                          if ( dia >= 1 && dia <= 28 )
                              printf( "\n   LA FECHA ES CORRECTA" );
                          else
                              printf( "\n   LA FECHA ES INCORRECTA" );
        }
    }
    
    else
        printf( "\n   LA FECHA ES INCORRECTA" );
    }

    printf ("\n La cantidad de pacientes masculinos son: %d", masculino);
    printf ("\n La cantidad de pacientes femeninos son: %d", femenino);
    printf ("\n La cantidad de pacientes mayores de edad son: %d", mayor_ed);
    printf ("\n La cantidad de pacientes menores de edad son: %d", menor_ed);
    printf ("\n %d Paciente/s tendra/n un descuento de 15 por ciento sobre el costo de la consulta", desc_f);
    printf ("\n %d Paciente/s mayor/es de 60 tendran un descuento de 30 por ciento", desc_m);

    getch();
    return 0;
    
}
