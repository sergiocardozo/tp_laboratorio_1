/*
 ============================================================================
 Name        : Trabajopractico1.c
 Author      : Cardozo Sergio
 Version     :
 Copyright   : GLP
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{

	float a = 0;
	float b = 0;
	int opciones;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	int factorialA = 0;
	int factorialB = 0;
	int retornoA = 0;
	int retornoB = 0;

	do {
		printf("MENU DE OPCIONES\n");
		printf("1- Ingrese el 1er operando: \n");
		printf("2- Ingrese el 2do operando: \n");
		printf("3- Calcular todas las operaciones \n");
		printf("4- Informe de los resultados: \n");
		printf("5- Salir. \n");
		scanf("%d",&opciones);

		switch (opciones) {
		case 1:
			printf("\nIngresar primer operando: ");
			retornoA = 1;
			break;
		case 2:
			printf("\nIngresar segundo operando: ");
			retornoB = 1;
			break;
		case 3:
			if(retornoA == 1 && retornoB == 1){


			suma = pedirSuma (a,b);
			resta = pedirResta (a,b);
			multiplicacion = pedirMultiplicar (a,b);
			division = pedirDivision (a,b);
			factorialA = pedirFactorial (a);
			factorialB = pedirFactorial (b);
			}
			break;

		case 4:
			printf("El resultado de A+B es: %d", suma);
			printf("\nEl resultado de A-B es: %d", resta);
			printf("\nEl resultado de A/B es: %d", division);
			printf("\nEl resultado de A*B es: %d", multiplicacion);
			printf("\nEl factorial de A es: %d", factorialA, "\nEl resultado del factorial B es: %d", factorialB);

			break;
		case 5:
			opciones = 5;
			printf("Saliendo de la calculadora.");
			break;
		default:
			printf("La opcion ingresada no es correcta.");
		}
		system("cls");
		system("pause");

	} while (opciones != 5);
return 0;
}
