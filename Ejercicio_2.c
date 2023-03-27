/*Programa que reigstra las citas medicas de la clinica ABC*/

/* Representantes:
José González - 29.834.290 
Pedro Rojas - 30.127.613
Gustavo Pérez - 30.350.803 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int genero, i, n, masc = 0, fem = 0, edad, mayor = 0, menor = 0, dia, mes, año, ci, descont_f = 0, descont_m = 0;
    
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
            fem = fem + 1;
        else
            masc = masc + 1;
        putchar ('\n');
        printf("\n Ingrese la cedula de identidad del paciente: (POR FAVOR NO UTILICE PUNTOS NI COMAS)");
        scanf("%d", &ci);
        if (ci % 2 == 0 && fem)
         descont_f = descont_f + 1;
         if (masc == edad > 60)
         descont_m = descont_m + 1;

        printf( "\n   Ingrese la edad del paciente: " );
        scanf( "%d", & edad );
        if(edad >= 18)
            mayor = mayor + 1;
        else
            menor = menor + 1;
        putchar ('\n');
        
        printf("\n Ingrese la fecha de nacimiento del paciente:");
        printf("\n Dia/Mes/Año: ");
        scanf( "%d/%d/%d", &dia, &mes, &año);
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
                          printf( "\n   la fecha es válida" );
                      else
                          printf( "\n   ¡fecha invalida!" );
                      break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : if ( dia >= 1 && dia <= 30 )
                          printf( "\n   la fecha es válida" );
                      else
                          printf( "\n   ¡fecha invalida!" );
                      break;

            case  2 : if( año % 4 == 0 && año % 100 != 0 || año % 400 == 0 )
                          if ( dia >= 1 && dia <= 29 )
                              printf( "\n   la fecha es válida" );
                          else
                              printf( "\n   ¡fecha invalida!" );
                      else
                          if ( dia >= 1 && dia <= 28 )
                              printf( "\n   la fecha es válida" );
                          else
                              printf( "\n   ¡fecha invalida!" );
        }
    }
    
    else
        printf( "\n   ¡fecha invalida!" );
    }

    printf ("\n\t La cantidad de pacientes masculinos son: %d", masc);
    printf ("\n\t La cantidad de pacientes femeninos son: %d", fem);
    printf ("\n\t La cantidad de pacientes mayores de edad son: %d", mayor);
    printf ("\n\t La cantidad de pacientes menores de edad son: %d", menor);
    printf ("\n\t Hay %d de Pacientes tendrán un descuento de 15% de descuento sobre el costo de la consulta", descont_f);
    printf ("\n\t Hay %d de Pacientes mayores de 60 años qué tendrán un descuento del 30 porciento \n\v", descont_m);

    return 0;
    
}
