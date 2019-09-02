/*
 ============================================================================
 Name        : funciones.c
 Author      : Cardozo Sergio
 Version     :
 Copyright   : GLP
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include "funciones.h"


float pedirSuma (float a, float b){
	float suma;

	suma = a + b;
	return suma;
}
float pedirResta (float a, float b){
	float resta;

	resta = a - b;
	return resta;
}
float pedirMultiplicar (float a, float b){
	float multiplicacion;

	multiplicacion = a * b;
	return multiplicacion;
}
float pedirDivision (float a, float b){
	float division;

	if (b == 0) {
		printf("No se puede dividir por cero");


		}
	else {
			division = a / b;
		}
	return division;
}
int pedirFactorial (int numero){
	int factorial = 1;
	int i;
	for(i=1;i<=numero;i++){
		factorial = factorial*i;
	}
	return factorial;

}
float pedirNumero(char mensaje[])
{
    float auxFloat;
    printf("%s", mensaje);
    scanf("%f", &auxFloat);

    return auxFloat;
}
