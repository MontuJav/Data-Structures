#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"

typedef char QueueEntry;
typedef char StackEntry;

typedef struct node{
	QueueEntry data;
	struct node* next;
}Node;

typedef struct stack{
	int top;
	StackEntry entry[MAXSTACK];
}stack;

Node* front = NULL;
Node* rear = NULL;

void enqueue(QueueEntry x){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	
	if(front==NULL && rear==NULL){
		front=rear=temp;
	}
	else{
		rear->next=temp;
		rear=temp;
	}
}

QueueEntry dequeue(void){
	Node* temp=front;
	QueueEntry item=-1;
	if(front==NULL){
		printf("La cola esta vacia");
		return item;
	}
	
	else if(front==rear){
		item=front->data;
		front=rear=NULL;
	}
	else{
		item=front->data;
		front=front->next;
	}
	free(temp);
	return item;
}

QueueEntry Front(void){
	if(front==NULL){
		printf("La cola esta vacia");
		return -1;
	}
	else
		return front->data;
}

void printQueue(void){
	Node* temp=front;
	
	while(temp!=NULL){
		printf("%d", temp->data);
		temp=temp->next;
	}
	printf("\n");
}



void enqueue(QueueEntry x);
QueueEntry dequeue(void);
void printQueue(void);
QueueEntry Front(void);

int main(){
	int opc;
	QueueEntry item;
	
	do{
		printf("\n------------MENU------------\n");
		printf("1.- Encolar\n");
		printf("2.- Desencolar\n");
		printf("3.- Frente\n");
		printf("4.- Imprime toda la cola\n");
		printf("5.- Salir\n");
		printf("Escoje una opcion: ");
		scanf("%d", &opc);
		
		if(opc==1){
			printf("----------------------------------");
			printf("\nQue quiere encolar a la cola: ");
			scanf("%i", &item);
			enqueue(item);
		}
			
		else if(opc==2){
			printf("----------------------------------");
			dequeue();
		}
			
		else if(opc==3){
			printf("----------------------------------");
			item = Front();
			if(item==-1)
				printf("\nNo hay frente");
			else{
				printf("\nEl frente es: %i", item);
			}
		}
			
		else if(opc==4){
			printQueue();
		}
	}while(opc!=5);
	
	
	return 0;
}