/*
Alumno: Montufar Perez Javier.
Grupo: 1CM12.
*/

#include <stdio.h>
#include "fraccion.h"
#include "string.h"

int main(){
	char aux[100];
	fraccion f1,f2,sum,res,mult,div,simple; /*Declaramos dos fracciones*/
	int a,b,c,d;
	char salir[1];
	
	do{
	printf("\nNumerador de la primera fraccion=");
	scanf("%d",&a);
	printf("\nDenominador de la primera fraccion=");
	scanf("%d",&b);
	printf("\nNumerador de la segunda fraccion=");
	scanf("%d",&c);
	printf("\nDenominador de la segunda fraccion=");
	scanf("%d",&d);
	
	iniFraccion(&f1,a,b);
	iniFraccion(&f2,c,d);
	suma(&sum,&f1,&f2);
	resta(&res,&f1,&f2);
	multiplicacion(&mult,&f1,&f2);
	division(&div,&f1,&f2);
	simplificacion(&simple,&f1);
	
	printf("\nDe las fracciones:");
	toStringFraccion(aux,&f1);
	printf(aux);
	toStringFraccion(aux,&f2);
	printf(" %s\n",aux);
	toStringFraccion(aux,&sum);
	printf("Suma: %s\n",aux);
	toStringFraccion(aux,&res);
	printf("Resta: %s\n",aux);
	toStringFraccion(aux,&mult);
	printf("Multiplicacion: %s\n",aux);
	toStringFraccion(aux,&div);
	printf("Division: %s\n",aux);
	toStringFraccion(aux,&simple);
	printf("Simplificacion: %s\n",aux);
	printf("Desea salir?[si/no]:");	
	} while(strcmp(salir, "no") == 0);
	
	return 0;
}