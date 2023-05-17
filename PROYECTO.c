#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N 50
bool apertura=false; 
bool extraba=false;
bool sali_dep=false;


struct empleado{
  char name[N],lastn[N],dep[N],car[N];
  int ci,day,month,year,sal;

  
}empleados[100];


/////////////////////////////////////////////////////////////////////////////////////////////

//prototipos de funciones
void validar_numero(int *op,char aux[N]);
void consultar();
void consult_cedula();
void cons_depa();
void cons_carg();
void mayor_menor();
void ingreso(struct empleado empleados[],FILE *salida);
void eliminar(FILE *salida,FILE *datos);
void puesto(char aux[N]);
void depart(char aux[N]);
void modificar(FILE *salida);
void leer_info(FILE *datos,int *cedula,char nombre[N],char apellido[N],char departamento[N],char cargo[N],int *salario,int *dia,int *mes,int *year);

////////////////////////////////////////////////////////////////////////////////////////////


int main(){

  bool band=false;
  char aux[N]="joda";
  FILE *datos,*salida;


  

  struct empleado empleados[100];
  int opcion;
 
   do{
       printf("\nFUTURE, C.A. \n");
       printf("\n1) Registrar Empleado ");
       printf("\n2) Consultar Empleado");
       printf("\n3) Modificar Empleado");
       printf("\n4) Eliminar Empleado");
       printf("\n5) Salir\n");

       do{
       	
       printf("\nINGRESE UNA OPCION: ");
       scanf("%s",aux);
       if(atoi(aux)<=0 || atoi(aux)>5)
        printf("\nOPCION INCORRECTA, INTENTE CCON UNA OPCION VALIDA\n");
      }while(atoi(aux)<=0 || atoi(aux)>5);

        opcion=atoi(aux);
         switch(opcion){

               case 1:

               	 if(!apertura){
               	 	datos=fopen("trabajadores.in","w");
               	 	fclose(datos);
               	 	apertura=true;
               	 	salida=fopen("trabajadores.in","a");
               	 	ingreso(empleados,salida);

               	}else{

                 	salida=fopen("trabajadores.in","a");
                	 ingreso(empleados,salida);
       			}

               break;
               case 2:
            	consultar();
               break;
               case 3:
                modificar(salida);
               break;
               case 4:
                salida=fopen("trabajadores.in","r");
                datos=fopen("auxiliar.txt","w");

                eliminar(salida,datos);
               break;

               case 5:
                  band=true;
               break;
               
         }

    }while(!band);
    return 0;
} 


void ingreso(struct empleado empleados[],FILE *salida){ 

   int i,log  ;
   char aux[N];

   if(salida==NULL){
      printf("\nERROR EN LA APERTURA DEL ARCHIVO TRABAJADORES.IN");
   }else{
   
    do{

      printf("\nCUANTOS EMPLEADOS DESEA REGISTRAR: ");

      scanf("%s",aux);
      if(atoi(aux)<=0)

        printf("\nSOLO PUEDE INGRESAR UN NUMERO ENTERO MAYOR A 0,INTENTE DE NUEVO\n");

    }while(atoi(aux)<=0);
   
    log=atoi(aux);

    for(i=0;i<log;i++){
      
       printf("\nIngrese la Cedula: ");
       scanf("%d",&empleados[i].ci);
       
        printf("\nIngrese el Nombre: ");
       scanf("%s",empleados[i].name);
       
       printf("\nIngrese el Apellido: ");
       scanf("%s",empleados[i].lastn);
       
       depart(empleados[i].dep);
       
       puesto(empleados[i].car); 
       
       printf("\nIngrese el Salario: ");
       scanf("%d",&empleados[i].sal);
      
       printf("\nColoque la Fecha de Ingreso: \n");
       
       printf("\nIngrese el dia: ");
       scanf("%d",&empleados[i].day);
       
       printf("\nIngrese el Mes: ");
       scanf("%d",&empleados[i].month);
       
       printf("\nIngrese el year: ");
       scanf("%d",&empleados[i].year);
    }

    for(i=0;i<log;i++){

       fprintf(salida, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d", empleados[i].ci,empleados[i].name,empleados[i].lastn,
                empleados[i].dep,empleados[i].car,empleados[i].sal,empleados[i].day,empleados[i].month,empleados[i].year);

       fprintf(salida, "\n");
    }

    fclose(salida);
   }
}

void eliminar(FILE *salida,FILE *datos){

  FILE *nuevo;
  int ci1=0,cedula,salario,dia,mes,year,opcion;
  char aux[N],aux2[N]="no",nombre[N],apellido[N],departamento[N],cargo[N];
  bool eliminado=false;

  if(salida==NULL){

      printf("\nERROR AL ABRIR TRABAJADORES.IN\n");
  }else{

    do{

        printf("INGRESE EL NUMERO DE CEDULA DE LA PERSONA A ELIMINAR\n");

       scanf("%s",aux);
       validar_numero(&ci1,aux);
      }while(ci1<=0);

      
      
      while(!feof(salida) && !eliminado){

        leer_info(salida,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);
      
        if(cedula==ci1){ 

       
         printf("\nDATOS DEL TRABAJADOR A ELIMINAR \n");
         printf("CEDULA: %d\n",cedula);
         printf("NOMBRE: %s\n",nombre);
         printf("APELLIDO: %s\n",apellido);
         printf("DEPARTAMENTO: %s\n",departamento); 
         printf("CARGO: %s\n",cargo);
         printf("SALARIO: %d\n",salario);
         printf("FECHA DE INCORPORACION: %d-%d-%d\n",dia,mes,year);

          printf("\nESTA SEGURO DE QUERER ELIMINAR \n");
          printf("INGRESAR SI PARA ELIMINAR NO PARA CONSERVAR\n");
          scanf("%s",aux);
        
          

            if(strcmp(aux,aux2) == 0){
    			
         
              fprintf(datos, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d", cedula,nombre,apellido,
                    departamento,cargo,salario,dia,mes,year);

              fprintf(datos, "\n");
            }else{

              eliminado=true;
            	if(!extraba){
              	nuevo=fopen("estrabajadores.txt","w");
              	extraba=true;
              }else
              	{
              		nuevo=fopen("estrabajadores.txt","a");
              	}
                  fprintf(nuevo, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d", cedula,nombre,apellido,
                        departamento,cargo,salario,dia,mes,year);
                   
            
             do{
  			         printf("\n: ");
                 printf("INGRESE LA CAUSA \n");
                 printf("\n1) TRASLADO");
                 printf("\n2) RENUNCIA");
                 printf("\n3) DESPIDO");
                 printf("\n4) OTRO");
                 printf("\n: ");
                 scanf("%s",aux);
                 printf("\n: ");
                 
                  if(atoi(aux)>0 || atoi(aux)<5){
                    printf("INGRESE LA FECHA\n");
                    printf("DIA: ");
                    scanf("%d",&dia);
                    printf("MES: ");
                    scanf("%d",&mes);
                    printf("YEAR: ");
                    scanf("%d",&year);
                  	
                   opcion=atoi(aux);
                   switch(opcion){
                  
                     case 1:
                     fprintf(nuevo, " %s","TRASLADO");
                     fprintf(nuevo, " %d-%d-%d\n",dia,mes,year);
                     break;
                     case 2:
                     fprintf(nuevo, " %s","RENUNCIA");
                     fprintf(nuevo, " %d-%d-%d\n",dia,mes,year);
                     break;
                     case 3:
                     fprintf(nuevo, " %s","DESPIDO");
                     fprintf(nuevo, " %d-%d-%d\n",dia,mes,year);
                     break;
                     case 4:
                     fprintf(nuevo, " %s","OTRO");
                     fprintf(nuevo, " %d-%d-%d\n",dia,mes,year);
                     break;
                   
                    }
                  }
              }while(atoi(aux)<=0 || atoi(aux)>=5);
               fclose(nuevo);
            }  
           
   

         }else{
  				    if(!feof(salida)){
    		          fprintf(datos, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d", cedula,nombre,apellido,
                  departamento,cargo,salario,dia,mes,year);
                  fprintf(datos, "\n");
              }
          }
        
      }
         
          fclose(salida);
          fclose(datos);
      //   
         remove("trabajadores.in");
        rename("auxiliar.txt","trabajadores.in");
  }  
  
}

void modificar(FILE *salida){

  FILE *datos;
  int cedula,salario,dia,mes,year,ci;
  char nombre[N],apellido[N],aux[N],departamento[N],cargo[N];
  datos=fopen("auxiliar.txt","w");
  salida=fopen("trabajadores.in","r");

  if(salida==NULL){

      printf("\nERROR AL ABRIR TRABAJADORES.IN\n");
  }else{

    while(!feof(salida)){

        leer_info(salida,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);
        
        if(!feof(salida)){
          printf("%d %s %s %s %s %d %d-%d-%d\n",cedula,nombre,apellido,departamento,cargo,salario,dia,mes,year );
        }

    }
    printf("\n");
    rewind(salida);

    do{
        printf("INGRESE LA CEDULA DEL TRABAJADOR A MODIFICAR\n");
        scanf("%s",aux);
        if(atoi(aux)<=0)
          printf("INGRESE UNA CEDULA VALIDA\n");
    }while(atoi(aux)<=0);

      ci=atoi(aux);

      while(!feof(salida)){

        leer_info(salida,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);
        

       if(cedula==ci){

       if(!feof(salida)){
        printf("\nINGRESE LOS NUEVOS DATOS\n");

        printf("NOMBRE\n");
        scanf("%s",nombre);
        printf("APELLIDO\n");
        scanf("%s",apellido);
        printf("DEPARTAMENTO\n");
        depart(departamento);
        printf("CARGO\n");
        puesto(cargo);
        printf("SALARIO\n");
        scanf("%d",&salario);
        printf("DIA\n");
        scanf("%d",&dia);
        printf("MES\n");
        scanf("%d",&mes);
        printf("YEAR\n");
        scanf("%d",&year);
       
        fprintf(datos, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d", cedula,nombre,apellido,
                  departamento,cargo,salario,dia,mes,year);
        }
       }else{

            if(!feof(salida)){
            fprintf(datos, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d", cedula,nombre,apellido,
                  departamento,cargo,salario,dia,mes,year);
            
          }
       }

      fprintf(datos,"\n");

    }
    fclose(salida);
    fclose(datos);
    remove("trabajadores.in");
    rename("auxiliar.txt","trabajadores.in");
  }
}

void puesto(char aux[N]){

  bool band=false;
  char opcion[N];
  int op;
      do{

       printf("\nIngrese el Cargo: ");
       printf("\n1) Gerente");
       printf("\n2) Supervisor");
       printf("\n3) Analista");
       printf("\n4) Disenador");
       printf("\n5) Desarrollador");
       printf("\n6) Auditor");
       printf("\n: ");
       scanf("%s",opcion);

       if(atoi(opcion)<=0 || atoi(opcion)>6){

        printf("\nPOR FAVOR DIGITE UNA OPCION VALIDA\n\n");
       }
       else
          band=true;


     }while(!band);
    	op=atoi(opcion);
     switch(op){
              

            case 1:

              strcpy( aux, "Gerente" );
            break;
            case 2:
              strcpy( aux, "Supervisor" );
            break;
            case 3:
              strcpy( aux, "Analista" );
            break;
            case 4:
              strcpy( aux, "Disenador" );
            break;

            case 5:
               strcpy( aux, "Desarrolador" );
            break;

            case 6:
               strcpy( aux, "Auditor" );
            break;   


     }

}
void depart(char aux[N]){

  bool band=false;
  char opcion[N];
  int op;
      do{

       printf("\nIngrese el Departamento: ");
       printf("\n1) RRHH");
       printf("\n2) Consultoria");
       printf("\n3) Diseno");
       printf("\n4) Produccion");
       printf("\n5) Calidad"); 
       printf("\n6) Distribucion");
       printf("\n: ");
       scanf("%s",opcion);

       if(atoi(opcion)<=0 || atoi(opcion)>6){

        printf("\nPOR FAVOR DIGITE UNA OPCION VALIDA\n\n");
       }
       else
          band=true;


     }while(!band);
     
     op=atoi(opcion);

     switch(op){
              

            case 1:

              strcpy( aux, "RRHH" );
            break;
            case 2:
              strcpy( aux, "Consultoria" );
            break;
            case 3:
              strcpy( aux, "Diseno" );
            break;
            case 4:
              strcpy( aux, "Produccion" );
            break;

            case 5:
               strcpy( aux, "Calidad" );
            break;

            case 6:
               strcpy( aux, "Distribucion" );
            break;   


     }

}

void consultar(){

	int opcion=0;
	char aux[N];

	do{

		printf("\nINGRESE UNA OPCION\n");

		printf(" 1) CONSULTA POR CEDULA\n");
		printf(" 2) CONSULTA POR DEPARTAMENTO\n");
		printf(" 3) CONSULTA POR CARGO\n");
		printf(" 4) TRABAJADOR CON MAYOR Y MENOR SUELDO\n");
		scanf("%s",aux);

		validar_numero(&opcion,aux);	

	 switch(opcion){

	         case 1:

	       		consult_cedula();
	       
	          break;
	          case 2:
	            cons_depa();
	          break;
	          case 3:
	          	cons_carg();
	          break;
	          case 4:
	    	    mayor_menor();
	          break;
	               
	         }
	}while(opcion>=5 || opcion<=0);

}

void validar_numero(int *op,char aux[N]){


	if(atoi(aux)<=0 ){

		printf("\nPOR FAVOR DIGITE SOLO NUMEROS MAYORES A 0\n");
	}else
		*op=atoi(aux);

}

void consult_cedula(){

	FILE *datos;
	bool band=false;
	int ci=0,cedula,salario,dia,mes,year;
	char aux[N],nombre[N],apellido[N],departamento[N],cargo[N];

	datos=fopen("trabajadores.in","r");
	
  if(datos==NULL){

      printf("\nERROR AL ABRIR TRABAJADORES.IN\n");
  }else{


	  do{

  		printf("\nINGRESE EL NUMERO DE CI A CONSULTAR\n");
  		scanf("%s",aux);
  		validar_numero(&ci,aux);

  	}while(ci<=0);


  	while(!feof(datos)){

        leer_info(datos,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);
  	    

        if(cedula==ci){
        		printf("\nTRABAJOR SELECCIONADO\n");
        		printf("%d %s %s %s %s %d %d-%d-%d\n",cedula,nombre,apellido,departamento,cargo,salario,dia,mes,year );
        		band=true; 
        }
        		
    }

  	if(!band)
  		printf("\nEL NUMERO DE CI: %d NO ESTA ASOCIADA A NINGUN TRABAJADOR\n",ci);
  	 fclose(datos);
    }
}

void mayor_menor(){

	FILE *datos,*temporal,*temporal1;
	int mayor=0,menor=0,cedula,salario,dia,mes,year;
	char nombre[N],apellido[N],departamento[N],cargo[N];

	datos=fopen("trabajadores.in","r");

	if(datos==NULL){

	
		printf("\nERROR AL ABRIR EL ARCHIVO TRABAJADORE.TXT\n");

	}else{

	
	while(!feof(datos)){


	    leer_info(datos,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);

       if(!feof(datos)){
          if(salario>mayor){
        	 mayor=salario;

      		
           temporal=fopen("sueldo.txt","w");
      			fprintf(temporal, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d\n", cedula,nombre,apellido,
                  departamento,cargo,salario,dia,mes,year);
      		

      	  }
       }
	}

	menor=mayor;
	fclose(temporal);
	rewind(datos);

	while(!feof(datos)){

        leer_info(datos,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);

        if(!feof(datos)){
          if(salario<menor){
          	menor=salario;

      		  temporal1=fopen("sueldo2.txt","w");

      			fprintf(temporal1, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d\n", cedula,nombre,apellido,
                  departamento,cargo,salario,dia,mes,year);
      		}

    	}
	}


	fclose(datos);
	fclose(temporal1);
	temporal=fopen("sueldo.txt","r");

	printf("\nTRABAJADOR CON MAYOR SUELDO:\n");

	    leer_info(temporal,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);

	     printf("CEDULA: %d\n",cedula);
       printf("NOMBRE: %s\n",nombre);
       printf("APELLIDO: %s\n",apellido);
       printf("DEPARTAMENTO: %s\n",departamento); 
       printf("CARGO: %s\n",cargo);
       printf("SALARIO: %d\n",salario);
       printf("FECHA DE INCORPORACION: %d-%d-%d\n",dia,mes,year);

  temporal1=fopen("sueldo2.txt","r");

	   printf("\nTRABAJADOR CON MENOR SUELDO\n");

	    leer_info(temporal1,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);

	     printf("CEDULA: %d\n",cedula);
       printf("NOMBRE: %s\n",nombre);
       printf("APELLIDO: %s\n",apellido);
       printf("DEPARTAMENTO: %s\n",departamento); 
       printf("CARGO: %s\n",cargo);
       printf("SALARIO: %d\n",salario);
       printf("FECHA DE INCORPORACION: %d-%d-%d\n",dia,mes,year);

       fclose(temporal);
       fclose(temporal1);
       remove("sueldo.txt");
       remove("sueldo2.txt");
      }
}


void cons_depa(){

	FILE *datos,*salida;
	int cont=0,total=0,cedula,salario,dia,mes,year;
	char aux[N],nombre[N],apellido[N],departamento[N],cargo[N];
	bool registro=false;

	datos=fopen("trabajadores.in","r");

	depart(aux);
	registro=true;

  if(datos==NULL){

      printf("\nERROR AL ABRIR TRABAJADORES.IN\n");
  }else{

      while(!feof(datos)){
        
        leer_info(datos,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);

        if(!(feof(datos))){
        if(strcmp(aux,departamento) == 0){

        	cont=cont+1;
        	total=total+salario;

        	if(!sali_dep){

        		salida=fopen("departamento.txt","w");
        		
        		fclose(salida);
        		sali_dep=true;
        	}

        	 salida=fopen("departamento.txt","a");

        	 if(registro){
        	 fprintf(salida, "TRABAJADORES DEL DEPARTAMENTO %s\n",departamento );
        	 registro=false;
        	}
        	 fprintf(salida, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d\n", cedula,nombre,apellido,
                  departamento,cargo,salario,dia,mes,year);
        	
        	 fclose(salida);
          }
      }
  	}

  	printf("\nTOTAL DE TRABAJADORES DEL DEPARTAMENTO %s: %d\n",aux,cont);
  	printf("\nTOTAL DE SUELDO DEVENGADOS DEL DEPARTAMENTO %s: %d\n",aux,total);

  }
}

void cons_carg(){

	FILE *datos,*salida;
	int cont=0,total=0,cedula,salario,dia,mes,year;
	char aux[N],nombre[N],apellido[N],departamento[N],cargo[N];
	bool registro=false;

	datos=fopen("trabajadores.in","r");

	puesto(aux);
	registro=true;

  if(datos==NULL){

      printf("\nERROR AL ABRIR TRABAJADORES.IN\n");
  }else{

    	while(!feof(datos)){
          leer_info(datos,&cedula,nombre,apellido,departamento,cargo,&salario,&dia,&mes,&year);
    	   
        if(!(feof(datos))){
          if(strcmp(aux,cargo) == 0){

          	cont=cont+1;
          	total=total+salario;

          	if(!sali_dep){

          		salida=fopen("cargo.txt","w");
          		
          		fclose(salida);
          		sali_dep=true;
          	}

          	 salida=fopen("cargo.txt","a");

          	 if(registro){
            	 fprintf(salida, "TRABAJADORES DEL CARGO %s\n",cargo );
            	 registro=false;
          	 }
          	 fprintf(salida, "%d " "%s " "%s " "%s " "%s " "%d " "%d " "%d " "%d\n", cedula,nombre,apellido,
                    departamento,cargo,salario,dia,mes,year);
          	
          	 fclose(salida);
          }
        }
    	}

  	printf("\nTOTAL DE TRABAJADORES DEL CARGO %s: %d\n",aux,cont);
  	printf("\nTOTAL DE SUELDO DEVENGADOS DEL CARGO %s: %d\n",aux,total);
  }

}


void leer_info(FILE *datos,int *cedula,char nombre[N],char apellido[N],char departamento[N],char cargo[N],int *salario,int *dia,int *mes,int *year){

  if(!feof(datos)){
      fscanf(datos,"%d",&(*cedula));
      fscanf(datos,"%s",nombre);
      fscanf(datos,"%s",apellido);
      fscanf(datos,"%s",departamento);
      fscanf(datos,"%s",cargo);
      fscanf(datos,"%d",&(*salario));
      fscanf(datos,"%d",&(*dia));
      fscanf(datos,"%d",&(*mes));
      fscanf(datos,"%d",&(*year));
  }
  

}

