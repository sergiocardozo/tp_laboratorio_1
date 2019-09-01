#include <stdio.h>

int pedirSuma (int a, int b){
	int suma;

	suma = a + b;
	return suma;
}
int pedirResta (int a, int b){
	int resta;

	resta = a - b;
	return resta;
}
int pedirMultiplicar (int a, int b){
	int multiplicacion;

	multiplicacion = a * b;
	return multiplicacion;
}
int pedirDivision (int a, int b){
	int division;

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
