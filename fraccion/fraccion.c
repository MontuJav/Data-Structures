#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"
#include "fraccion.h"



/*-------------------------
	CONSTRUCTOR TIPOS
---------------------------*/
/* Definimos a la funcion constructora del tipo tabla */
void iniFraccion(fraccion* f, const int num, const int den){
	f->numerador=num;
	f->denominador=den;
}

/*-------------------------
	OPERACIONES DE LOS TIPOS
---------------------------*/
/* Definimos a los sets y gets de cada celda de la tabla */
int getNum(fraccion* f){
	 return f->numerador;
 }
 
 int getDen(fraccion* f){
	 return f->denominador;
 }

void suma(fraccion* resultado, fraccion* f1, fraccion* f2){
	int n1,n2,d1,d2;
	
	n1=getNum(f1);
	n2=getNum(f2);
	d1=getDen(f1);
	d2=getDen(f2);
	resultado->numerador=(n1*d2)+(n2*d1);
	resultado->denominador=d1*d2;
}

void resta(fraccion* resultado, fraccion* f1, fraccion* f2){
	/* Se especifican->	         minuendo		sustraendo */
	int n1,n2,d1,d2;
	
	n1=getNum(f1);
	n2=getNum(f2);
	d1=getDen(f1);
	d2=getDen(f2);
	resultado->numerador=(n1*d2)-(n2*d1);
	resultado->denominador=d1*d2;
}

void multiplicacion(fraccion* resultado, fraccion* f1, fraccion* f2){
	int n1,n2,d1,d2;
	
	n1=getNum(f1);
	n2=getNum(f2);
	d1=getDen(f1);
	d2=getDen(f2);
	resultado->numerador=n1*n2;
	resultado->denominador=d1*d2;
}

void division(fraccion* resultado, fraccion* f1, fraccion* f2){
	/* Se especifican->		dividendo		divisor */
	int n1,n2,d1,d2;
	
	n1=getNum(f1);
	n2=getNum(f2);
	d1=getDen(f1);
	d2=getDen(f2);
	resultado->numerador=n1*d2;
	resultado->denominador=d1*n2;
}

void find_q_r(const int a, const int b, int* q, int* r){
	int residuo,counter=0;
	residuo=a;
	if(a<b){
		*q=0;
		*r=a;
	}
	
	else{
		do{
			residuo=residuo-b;
			counter+=1;
		}while(residuo>=b);
	*r=residuo;
	*q=counter;
	}
}

void MCD (const int a, const int b, int* mcd){
	int a1,b1=0;
	int q,r=0;
	int aux;
	
	*mcd=1;
	
	/*MCD=(a,b)=(|a|,|b|)*/
	a1=abs(a);
	b1=abs(b);
	
	/*Asegurarnos que a1>=b1*/
	if(b1>a1){
		aux=b1;
		b1=a1;
		a1=aux;
	}
	
	if(b1==0)
		*mcd=a1;
	else{
		find_q_r(a1,b1,&q,&r);
		if(r==0)
			*mcd=b1;
		else{
			do{
				a1=b1;
				b1=r;
				find_q_r(a1,b1,&q,&r);
			}while(r!=0);
			*mcd=b1;
		}
	}	
}

void simplificacion(fraccion* resultado, fraccion* f){
	int n,d,mcd;
	
	n=f->numerador;
	d=f->denominador;
	MCD(n,d,&mcd);
	resultado->numerador=n/mcd;
	resultado->denominador=d/mcd;
}

void toStringFraccion(char* salida, fraccion* f){
	char bufer[10];
	int n=getNum(f);
	int d=getDen(f);
	strcpy(salida,"");
	strcpy(bufer,"");
	
	sprintf(bufer, "%i", n);
	strcat(salida, bufer);
	strcat(salida, "/");
	sprintf(bufer, "%i", d);
	strcat(salida, bufer);
}