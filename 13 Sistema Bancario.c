#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PROTOTIPOS DE LAS FUNCIONES
void inactivo();
void menuPrincipal();
void actualizarInformacion();
void registrarCuenta();
void realizarDeposito();
void realizarRetiro();
void listaClientes();
void validarCuenta();
void eliminarCuenta();
void encabezado();


//ESTRUCTURA CON VARIABLES ESTATICAS Y DINAMICAS
struct cuenta{
	int numero_cuenta;
	char nombres[50];
	char *ciudad;
	char *correo;
	char *telefono;
	float saldo;
	int estado;
}arreglo[10];


int main(){
	inactivo();
	menuPrincipal();
}


//FUNCION QUE MUESTRA EN PANTALLA EL MENU DE OPCIONES
void menuPrincipal(){
	int op;
	
	do{
		system("cls");
		encabezado();
		printf("MENU DE OPCIONES\n\n");
		printf("1. Crear cuenta\n");
		printf("2. Realizar deposito\n");
		printf("3. Realizar retiro\n");
		printf("4. Actualizar informacion\n");
		printf("5. Validar detalles de una cuenta\n");
		printf("6. Eliminar cuenta\n");
		printf("7. Lista completa de Clientes\n");
		printf("8. Salir del Programa\n\n");
		printf("Ingrese opcion: ");
		scanf("%i",&op);	
	}while(op < 1 || op > 8);
	
	switch(op){
		case 1:
			registrarCuenta();
			break;
		
		case 2:
			realizarDeposito();
			break;
			
		case 3:
			realizarRetiro();
			break;
			
		case 4:
			actualizarInformacion();
			break;
		
		case 5:
			validarCuenta();
			break;
			
		case 6:
			eliminarCuenta();
			break;
		
		case 7:
			listaClientes();
			break;
		
		case 8:
			exit(0);
			break;
	}
}

//FUNCION QUE PERMITE REGISTRAR CUENTA
void registrarCuenta(){
	int i,j, n_cuenta, rep, aux = 0;
	char ciudad[50], correo[50], telefono[50];
	
	system("cls");
	encabezado();
	printf("REGISTRAR CLIENTE\n\n");
	
	for(i = 0; i < 10; i++){
		if(arreglo[i].estado == 0){
			aux = 1;
			
			do{
				rep = 0;
				printf("Ingrese numero de cuenta: ");
				scanf("%i",&n_cuenta);	
				
				for(j = 0; j < 10; j++){
					if(n_cuenta == arreglo[j].numero_cuenta){
						rep = 1;
					}	
				}
			}while(rep == 1);
			
			arreglo[i].numero_cuenta = n_cuenta;
			
			fflush(stdin); //LIMPIA BUFFER
			printf("Ingrese nombres:          ");
			gets(arreglo[i].nombres);
			
			printf("Ingrese ciudad:           ");
			gets(ciudad);
			
			arreglo[i].ciudad = (char*)malloc((strlen(ciudad)+1)*sizeof(char)); //ASIGNAMOS ESPACIO
			if(arreglo[i].ciudad == NULL){
				printf("\nNo se ha podido reservar memoria/\n");
				exit(1);
			}
			strcpy(arreglo[i].ciudad,ciudad);
			
			
			printf("Ingrese correo:           ");
			gets(correo);
			
			arreglo[i].correo = (char*)malloc((strlen(correo)+1)*sizeof(char));
			if(arreglo[i].correo == NULL){
				printf("\nNo se ha podido reservar memoria/\n");
				exit(1);
			}
			strcpy(arreglo[i].correo,correo);
			
	
			printf("Ingrese telefono:         ");
			gets(telefono);
			
			arreglo[i].telefono = (char*)malloc((strlen(telefono)+1)*sizeof(char));
			if(arreglo[i].telefono == NULL){
				printf("\nNo se ha podido reservar memoria/\n");
				exit(1);
			}
			strcpy(arreglo[i].telefono,telefono);
			
			arreglo[i].estado = 1;
			arreglo[i].saldo = 0;
			
			
			printf("\nSe registro al cliente correctamente.\n");
			system("pause");
			menuPrincipal();
		}
	}
	
	if(aux == 0){
		printf("\nNo se pueden registrar mas clientes.\n");
		system("pause");
		menuPrincipal();
	}	
}

//FUNCION QUE PERMITE REALIZAR UN DEPOSITO
void realizarDeposito(){
	int i,n_cuenta, aux = 0;
	float deposito;
	
	system("cls");
	encabezado();
	printf("REALIZAR DEPOSITO\n\n");
	
	printf("Ingrese Numero de Cuenta: ");
	scanf("%i",&n_cuenta);
	
	for(i = 0; i < 10; i++){
		if(n_cuenta == arreglo[i].numero_cuenta){
			aux = 1;
			printf("Ingrese valor a depositar: $");
			scanf("%f",&deposito);
			arreglo[i].saldo += deposito;
			printf("\nEl deposito se realizo correctamente.\n");
			
		}
	}
	
	if(aux == 0){
		printf("\nNumero de Cuenta no existe.\n");
	}
	
	
	system("pause");
	menuPrincipal();
}


//FUNCION QUE PERMITE REALIZAR UN RETIRO
void realizarRetiro(){
	int i,n_cuenta, aux = 0;
	float retiro;
	
	system("cls");
	encabezado();
	printf("REALIZAR RETIRO\n");
	printf("---------------\n\n");
	
	printf("Ingrese Numero de Cuenta: ");
	scanf("%i",&n_cuenta);
	
	for(i = 0; i < 10; i++){
		if(n_cuenta == arreglo[i].numero_cuenta){
			aux = 1;
			
			do{
				printf("Ingrese valor a retirar: $");
				scanf("%f",&retiro);
			}while(retiro > arreglo[i].saldo);
			
			arreglo[i].saldo -= retiro;
			printf("\nEl retiro se realizo correctamente.\n");
		}
	}
	
	if(aux == 0){
		printf("\nNumero de Cuenta no existe.\n");
	}
	
	
	system("pause");
	menuPrincipal();
}

//FUNCION QUE PERMITE ACTUALIZAR LOS DATOS DE LA CUENTA
void actualizarInformacion(){
	int i, opcion, n_cuenta, aux = 0;
	
	system("cls");
	encabezado();
	printf("ACTUALIZAR INFORMACION DE CUENTA\n\n");
	printf("Ingrese Numero de Cuenta: ");
	scanf("%i",&n_cuenta);
	
	for(i = 0; i < 10 && aux == 0; i++){
		if(n_cuenta == arreglo[i].numero_cuenta){
			system("cls");
			encabezado();
			printf("ACTUALIZAR INFORMACION DE CUENTA\n\n");
			printf("1. Nombres:          %s\n",arreglo[i].nombres);
			printf("2. Ciudad:           %s\n",arreglo[i].ciudad);
			printf("3. Correo:           %s\n",arreglo[i].correo);
			printf("4. Telefono:         %s\n",arreglo[i].telefono);
			printf("5. Saldo Actual:     $%.2f\n\n",arreglo[i].saldo);
			printf("Ingrese opcion a actualizar: ");
			scanf("%i",&opcion);
			fflush(stdin);
			
			switch(opcion){
				case 1:
					printf("\nNombre del Cliente:   %s\n",arreglo[i].nombres);
					printf("Ingrese nuevos Nombres: ");
					gets(arreglo[i].nombres);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
					
				case 2:
					printf("\nCiudad actual:      %s\n",arreglo[i].ciudad);
					printf("Ingrese nueva Ciudad: ");
					gets(arreglo[i].ciudad);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
					
				case 3:
					printf("Correo actual:        %s\n",arreglo[i].correo);
					printf("Ingrese nuevo Correo: ");
					gets(arreglo[i].correo);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
					
				case 4:
					printf("Telefono actual:        %s\n",arreglo[i].telefono);
					printf("Ingrese nuevo Telefono: ");
					gets(arreglo[i].telefono);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
					
				case 5:
					printf("Saldo Actual:        $%.2f\n\n",arreglo[i].saldo);
					printf("Ingrese nuevo Saldo:  ");
					scanf("%f",&arreglo[i].saldo);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
			}
			
			aux = 1;
		}
	}
	
	if(aux == 0){
		printf("\nNumero de Cuenta no existe.\n");
	}
	
	system("pause");
	menuPrincipal();
}

//FUNCION QUE VALIDA LA INFORMACION DE UNA CUENTA
void validarCuenta(){
	int i, n_cuenta, aux = 0;
	
	system("cls");
	encabezado();
	printf("VALIDAR CUENTA EXISTENTE\n\n");
	printf("Ingrese Numero de Cuenta: ");
	scanf("%i",&n_cuenta);
	
	for(i = 0; i < 10; i++){
		if(n_cuenta == arreglo[i].numero_cuenta){
			system("cls");
			encabezado();
			printf("VALIDAR CUENTA EXISTENTE\n\n");
			printf("Numero de Cuenta: %i\n",arreglo[i].numero_cuenta);
			printf("Nombre del Cliente: %s\n",arreglo[i].nombres);
			printf("Saldo Actual:     $%.2f\n\n",arreglo[i].saldo);
			aux = 1;
		}
	}
	
	if(aux == 0){
		printf("\nNumero de Cuenta no existe.\n");
	}
	
	system("pause");
	menuPrincipal();
}

//FUNCION QUE PERMITE ELIMINAR UNA CUENTA
void eliminarCuenta(){
	int i, n_cuenta, aux = 0;
	
	system("cls");
	encabezado();
	printf("ELIMINAR CUENTA\n\n");
	printf("Ingrese Numero de Cuenta: ");
	scanf("%i",&n_cuenta);
	
	for(i = 0; i < 10; i++){
		if(n_cuenta == arreglo[i].numero_cuenta){
			system("cls");
			encabezado();
			printf("ELIMINAR CUENTA\n\n");
			arreglo[i].estado = 0;
			aux = 1;
			printf("\nLa Cuenta ha sido eliminada correctamente.\n");
		}
	}
	
	if(aux == 0){
		printf("\nNumero de Cuenta no existe.\n");
	}
	
	system("pause");
	menuPrincipal();
}

//FUNCION QUE MUESTRA EN PATALLA TODAS LAS CUENTAS ACTIVAS
void listaClientes(){
	int i, aux = 0;
	
	system("cls");
	encabezado();
	printf("LISTA COMPLETA DE CLIENTES\n\n");
	
	for(i = 0; i < 10; i++){
		if(arreglo[i].estado == 1){
			aux++;
			printf("N Cuenta:        %i\n",arreglo[i].numero_cuenta);
			printf("Nombres:         %s\n",arreglo[i].nombres);
			printf("Ciudad:          %s\n",arreglo[i].ciudad);
			printf("Correo:          %s\n",arreglo[i].correo);
			printf("Telefono:        %s\n",arreglo[i].telefono);		
			printf("Saldo Actual:    %.2f\n\n",arreglo[i].saldo);
			printf("---------------------------------------\n\n");
		}
	}
	
	if(aux == 0){
		printf("No se encontraron Clientes registrados!\n");
	}
	
	system("pause");
	menuPrincipal();
}


//FUNCION QUE MUESTRA EL ENCABEZADO O TITULO DEL PROGRAMA
void encabezado(){
	static char titulo[50] = "SISTEMA DE ADMINISTRACION BANCARIO";
	static char linea[50] = "==================================";
	printf("\t\t\t\t\t%s\n",linea);
	printf("\t\t\t\t\t%s\n",titulo);
	printf("\t\t\t\t\t%s\n\n\n",linea);
}


//FUNCION QUE ASIGNA EL VALOR DE 0 A LA VARIABLE ESTADO DEL ARREGLO
void inactivo(){
	int i;
	for(i = 0; i < 10; i++){
		arreglo[i].estado = 0;
	}
}
