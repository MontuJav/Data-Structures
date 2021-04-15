#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"
#define MAXSTACK 10 //Maximo numero de elemento

typedef char StackEntry; //Le pone un sinonimo al tipo que la pila va a almacenar

//Estructura pila
typedef struct stack{
	int top;
	StackEntry entry[MAXSTACK];
}stack;


int StackEmpty(stack* s){
	return s->top <= 0;
}

int StackFull(stack* s){
	return MAXSTACK <= s->top;
}

void Push(StackEntry item, stack* s){
	if(StackFull(s))
		printf("\nError, la pila esta llena\n");
	else
		s->entry[s->top++]=item; //x++ Postincremento.
}

void Pop(StackEntry* item, stack* s){
	if(StackEmpty(s))
		printf("\nError, la pila esta vacia\n");
	else
		*item=s->entry[--s->top]; //--x Predecremento
}

void CreateStack(stack* s){
	s->top=0;
}

StackEntry TopeDePila(stack* s){
	if(!StackEmpty(s)){
		StackEntry x;
		Pop(&x,s);
		Push(x,s);
		return x;
	}
}



void Push(StackEntry item, stack* s);
void Pop(StackEntry* item, stack* s);
int StackEmpty(stack* s);
int StackFull(stack* s);
void CreateStack(stack* s);
StackEntry TopeDePila(stack* s);

int main(){
	int opc;
	StackEntry item;
	stack pila;
	CreateStack(&pila);
	
	do{
		printf("-------------------MENU-------------------\n");
		printf("1.- Push\n");
		printf("2.- Pop\n");
		printf("3.- Tope de pila\n");
		printf("4.- Tamanio de la pila\n");
		printf("5.- Salir\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opc);
		
		if(opc==1){
			printf("----------------------------------");
			printf("\nQue quiere ingresar a la pila: ");
			scanf("%StackEntry", &item);
			Push(item,&pila);
		}
		
		else if(opc==2){
			printf("----------------------------------");
			Pop(&item, &pila);
		}
		
		else if(opc==3){
			printf("----------------------------------");
			if(StackEmpty(&pila))
				printf("\nError la pila esta vacia\n");
			else{
				printf("\nEl tope es: %c\n",TopeDePila(&pila));
			}
		}
		
		else if(opc==4){
			printf("----------------------------------");
			printf("\nTamanio=%d\n",pila.top);
		}
	}while(opc != 5);
}




