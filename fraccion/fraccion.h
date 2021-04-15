#ifndef VOCALES_H
#define VOCALES_H

/*-------------------------
	DEFINICIONES DE TIPOS
---------------------------*/
/* 
   Definimos al tipo de dato abstracto fraccion
   Elementos: Tiene dos numeros enteros, numerador y denominador, cuyo denominador 
   tiene que ser distinto de cero.
 */
typedef struct fraccion{
	int numerador;
	int denominador;
}fraccion;

void iniFraccion(fraccion* f, const int num, const int den);
int getNum(fraccion* f);
int getDen(fraccion* f);
void suma(fraccion* resultado, fraccion* f1, fraccion* f2);
void resta(fraccion* resultado, fraccion* f1, fraccion* f2);
void multiplicacion(fraccion* resultado, fraccion* f1, fraccion* f2);
void division(fraccion* resultado, fraccion* f1, fraccion* f2);
void find_q_r(const int a, const int b, int* q, int* r);
void MCD (const int a, const int b, int* mcd);
void simplificacion(fraccion* resultado, fraccion* f);
void toStringFraccion(char* salida, fraccion* f);

#endif