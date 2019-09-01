#include <stdio.h>


int pedirSuma (float a, float b){
	float suma;

	suma = a + b;
	return suma;
}
int pedirResta (float a, float b){
	float resta;

	resta = a - b;
	return resta;
}
int pedirMultiplicar (float a, float b){
	float multiplicacion;

	multiplicacion = a * b;
	return multiplicacion;
}
int pedirDivision (float a, float b){
	float division;

	if (b == 0) {
		printf("No se puede dividir por cero");

		}
	else {
			division = a / b;
		}
	return division;
}
int pedirFactorial (float numero){
	float factorial = 1;
	int i;
	for(i=1;i<=numero;i++){
		factorial = factorial*i;
	}
	return factorial;

}
