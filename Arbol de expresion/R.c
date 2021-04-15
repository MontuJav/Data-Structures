#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"
#define MAXSTACK 35 //Maximo numero de elemento

typedef struct arbol{
	char dato;
	struct arbol* izquierdo;
	struct arbol* derecho;
}arbol;

int prioridad(char a);
arbol* Busca_padre(arbol* n1, arbol* buscador);
void Cambia_nodo(arbol** n1, arbol** n2);
arbol* Crea_arbol(char* A);
void pre_orden(arbol* p);
void en_orden(arbol* p);
void post_orden(arbol* p);

/*Variables globales*/
arbol* raiz=NULL;

int main(){
	char A[50],B[50];
	int i;
	arbol* a;
	strcpy(A,"");
	strcpy(B,"");
	
	printf("Ingrese una operacion en notacion infija(no admite parentesis :c), A:");
	scanf("%s", A);
	a=Crea_arbol(A);
	
	printf("\nPre-orden, A:\n");
	pre_orden(a);
	printf("\nEn orden, A:\n");
	en_orden(a);
	printf("\nPost-orden, A:\n");
	post_orden(a);
	
		
}

int prioridad(char a){
	switch(a){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;	
	}
}

arbol* Crea_nodo(char dato){
	arbol* q=(arbol*)malloc(sizeof(arbol));
	q->dato=dato;
	q->izquierdo=NULL;
	q->derecho=NULL;
	return q;
}

//Invocar con buscador=raiz
arbol* Busca_padre(arbol* n1, arbol* buscador){
	if((buscador->izquierdo==n1) || (buscador->derecho==n1)) return buscador;
	else if(buscador->izquierdo != NULL)
		Busca_padre(n1, buscador->izquierdo);
	else if(buscador->derecho != NULL)
		Busca_padre(n1, buscador->derecho);
	else{
		return raiz;
	}	
}

void Cambia_nodo(arbol** n1, arbol** n2){
	char aux;
	arbol* auxp;
	
	aux=(*n1)->dato;
	(*n1)->dato=(*n2)->dato;
	(*n2)->dato=aux;
	
	auxp=*n1;
	*n1=*n2;
	*n2=auxp;
	
	
}

/*regresa un apuntador a la raiz del arbol*/
arbol* Crea_arbol(char* A){
	int i=0;
	int longitud=strlen(A);
	arbol* temp1,* temp2,* op1,* op2,* raiz;
	
	temp1=Crea_nodo(A[i]);
	raiz=temp1;
	i++;
	op1=Crea_nodo(A[i]);
	i++;
	temp2=Crea_nodo(A[i]);
	raiz->izquierdo=op1;
	raiz->derecho=temp2;
	Cambia_nodo(&temp1, &op1);
	temp1=temp2;	
	i++;
	
	while(i<longitud){
		op2=Crea_nodo(A[i]);
		i++;
		temp2=Crea_nodo(A[i]);
		
		//Crea subarbol
		if((prioridad(op1->dato)) < (prioridad(op2->dato))){
			temp1->izquierdo=op2;
			temp1->derecho=temp2;
			Cambia_nodo(&temp1,&op2);
		}
		
		//Asciende en el arbol
		else if(((prioridad(op1->dato)) > (prioridad(op2->dato))) || op1==raiz){
			temp1=raiz;
			raiz=op2;
			op2->izquierdo=temp1;
			op2->derecho=temp2;
		}
		
		//Reemplaza
		else{
			temp1=Busca_padre(op1, raiz);
			temp1->derecho=op2;
			op2->izquierdo=op1;
			op2->derecho=temp2;
		}
		
		temp1=temp2;
		i++;
		op1=op2;
	}
	return raiz;
}

void pre_orden(arbol* p){
	if(p!=NULL){
		printf("%c", p->dato);
		pre_orden(p->izquierdo);
		pre_orden(p->derecho);
	}
}

void en_orden(arbol* p){
	if(p!=NULL){
		en_orden(p->izquierdo);
		printf("%c", p->dato);
		en_orden(p->derecho);
	}
}

void post_orden(arbol* p){
	if(p!=NULL){
		post_orden(p->izquierdo);
		post_orden(p->derecho);
		printf("%c", p->dato);
	}
}