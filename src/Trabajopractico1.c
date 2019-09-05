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

	do {
		printf("MENU DE OPCIONES\n");
		printf("1- Ingrese el 1er operando: \n");
		printf("2- Ingrese el 2do operando: \n");
		printf("3- Calcular todas las operaciones \n");
		printf("4- Informe de los resultados: \n");
		printf("5- Salir. \n");
		printf("Primer numero ingresado: %.2f\n", a);
		printf("Segundo numero ingresado: %.2f\n", b);
		printf("Elija una opcion: \n");
		scanf("%d",&opciones);
			switch (opciones) {
			case 1:
			a = getNumero("Ingresar primer operando: ");
			break;
			case 2:
			b = getNumero("Ingresar segundo operando: ");
			break;
			case 3:
				suma = pedirSuma(a,b);
				resta = pedirResta(a,b);
				multiplicacion = pedirMultiplicar(a,b);
				division = pedirDivision(a,b);
				factorialA = (int) pedirFactorial(a);
				factorialB = (int) pedirFactorial(b);
				break;
			case 4:
				printf("El resultado de A+B es: %.2f",suma);
				printf("\nEl resultado de A-B es: %.2f",resta);
				printf("\nEl resultado de A/B es: %.2f",division);
				printf("\nEl resultado de A*B es: %.2f",multiplicacion);
				printf("\nEl factorial de A es: %d",factorialA);
				printf("\nEl resultado del factorial B es: %d\n",factorialB);
				break;
			case 5:
			printf("Saliendo de la calculadora.");
			break;
			default:
			printf("La opcion ingresada no es correcta.\n");
			break;
		}

	} while (opciones != 5);
return 0;
}
