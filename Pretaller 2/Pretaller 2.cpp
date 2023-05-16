#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee {
 char name[50];
 int age;
 float salary;
};
void saveEmployees(struct employee employees[], int size, char* filename);
int loadEmployees(struct employee employees[], char* filename);
void printEmployee(struct employee employee);
void printEmployees(struct employee employees[], int size);
int findEmployee(struct employee employees[], int size, char* name);
void addEmployee(struct employee employees[], int* size);
void modifyEmployee(struct employee employees[], int size);
void deleteEmployee(struct employee employees[], int* size);
int main() {
 struct employee employees[100];
 int size = loadEmployees(employees, "employees.dat");
 int choice = 0;
 while (choice != 5) {
 printf("\nSistema de administracion de empleados\n");
 printf("1. Registrar empleado\n");
 printf("2. Modificar empleado\n");
 printf("3. Eliminar empleado\n");
 printf("4. Listar empleado\n");
 printf("5. Exit\n");
 printf("Elija una opcion: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 addEmployee(employees, &size);
 break;
 case 2:
 modifyEmployee(employees, size);
 break;
 case 3:
 deleteEmployee(employees, &size);
 break;
 case 4:
 printEmployees(employees, size);
 break;
 case 5:
 saveEmployees(employees, size, "employees.dat");
 break;
 default:
 printf("Invalid choice\n");
 }
 }
 return 0;
}
void saveEmployees(struct employee employees[], int size, char* filename) {
 FILE* file = fopen(filename, "wb");
 if (file == NULL) {
 printf("Error opening file.");
 exit(1);
 }
 fwrite(&size, sizeof(int), 1, file);
 fwrite(employees, sizeof(struct employee), size, file);
 fclose(file);
}
int loadEmployees(struct employee employees[], char* filename) {
 FILE* file = fopen(filename, "rb");
 if (file == NULL) {
 return 0;
 }
 int size;
 fread(&size, sizeof(int), 1, file);
 fread(employees, sizeof(struct employee), size, file);
 fclose(file);
 return size;
}
void printEmployee(struct employee employee) {
 printf("Name: %s\n", employee.name);
 printf("Age: %d\n", employee.age);
 printf("Salary: %.2f\n", employee.salary);
}
void printEmployees(struct employee employees[], int size) {
 for (int i = 0; i < size; i++) {
 printf("Employee %d:\n", i + 1);
 printEmployee(employees[i]);
 }
}
int findEmployee(struct employee employees[], int size, char* name) {
 for (int i = 0; i < size; i++) {
 if (strcmp(employees[i].name, name) == 0) {
 return i;
 }
 }
 return -1;
}
void addEmployee(struct employee employees[], int* size) {
 printf("Enter name: ");
 scanf("%s", employees[*size].name);
 printf("Enter age: ");
 scanf("%d", &employees[*size].age);
 printf("Enter salary: ");
 scanf("%f", &employees[*size].salary);
 (*size)++;
}
void modifyEmployee(struct employee employees[], int size) {
 char name[50];
 printf("Enter name of employee to modify: ");
 scanf("%s", name);
 int index = findEmployee(employees, size, name);
 if (index == -1) {
 printf("Employee not found.\n");
 } else {
 printf("Enter new age: ");
 scanf("%d", &employees[index].age);
 printf("Enter new salary: ");
 scanf("%f", &employees[index].salary);
 }
}
void deleteEmployee(struct employee employees[], int* size) {
 char name[50];
 printf("Enter name of employee to delete: ");
 scanf("%s", name);
 int index = findEmployee(employees, *size, name);
 if (index == -1) {
 printf("Employee not found.\n");
 } else {
 for (int i = index; i < *size - 1; i++) {
 employees[i] = employees[i + 1];
 }
 (*size)--;
 }
}
