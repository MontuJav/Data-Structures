#include <stdio.h>
#include <stdlib.h>

void hanoi(int discos, char palo_inicial, char palo_intermedio, char palo_final);
int potencia(int a, int b);
int combina(int n, int k);
int main(){
	/* HANOI
	int n;
	printf("Introduzca el numero de discos: ");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	*/
	
	/* POTENCIA
	int a,b;
	
	printf("a?: ");
	scanf("%d", &a);
	printf("b?: ");
	scanf("%d", &b);
	printf("\na^b=%d", potencia(a,b));
	*/
	
	int n,k;
	printf("Introduzca n: ");
	scanf("%d", &n);
	printf("Introduzca k: ");
	scanf("%d", &k);
	printf("\n%dC%d=%d",n,k, n,k,combina(n,k));
	
}

// Disco inicial, intermedio, final
void hanoi(int n, char a, char b, char c){
	if(n==1){
		printf("Mover el disco 1 de %c a %c\n", a, c);
	}
	// n=2, hanoi(1, A, C, B), mover disco 2 de A a C, hanoi(1, B, A, C); Se interpreta como mover 1 disco a (B), luego el disco 2 al palo final (C) y al final mover un disco de donde estaba (B) al palo final (C).
	// n=3, hanoi(2, A, C, B), mover disco 3 de A a C, hanoi(2, B, A, C); Se interpreta como mover 2 discos a (B), luego el disco 3 al palo final (C) y al final mover 2 discos de donde estaban (B) al palo final (C).
	/*
	En general si se quieren moder n discos 
	1.-movemos (n-1) discos al palo intermedio
	2.-movemos el disco n al palo final
	3.-movemos (n-1) discos al palo final
	*/
	
	else{
		hanoi(n-1, a, c, b);
		printf("Mover el disco %d de %c a %c\n",n, a, c);
		hanoi(n-1, b, a, c);
	}
}

int potencia(int a, int b){
	if(b==0) return 1;
	else return (a*potencia(a,b-1));
}

int combina(int n, int k){
	if(n<k)
		printf("\nError menos elementos que ordenar que cajas\n");
	else if(n==k){
		return 1; //Caso base igual numero de elementos que cajas
	}
	else{
		printf("\nEstado, n=%d", n);
		return n*(combina(n-1, k));
	}
}

