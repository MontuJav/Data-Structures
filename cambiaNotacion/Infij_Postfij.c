#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"
#define MAXSTACK 35 //Maximo numero de elemento

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

StackEntry Pop(stack* s){
	StackEntry a;
	
	if(StackEmpty(s))
		printf("\nError, la pila esta vacia\n");
	else{
		s->top--;
		a=s->entry[s->top];
	}
	return a;
}

StackEntry TopeDePila(stack* s){
	if(!StackEmpty(s)){
		StackEntry x;
		x=Pop(s);
		Push(x,s);
		return x;
	}
}

void CreateStack(stack* s){
	s->top=0;
}

int ambito(char* A){
	int longitud=strlen(A);
	int ambito,i;
	ambito=0;
	for(i=0;i<longitud;i++){
		if(A[i]=='(') ambito++;
		else if(A[i]==')') ambito--;
	}
	return ambito;
}

int es_operador(char a){
	if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^' || a=='(' || a==')')
		return 1;
	else return 0;
}

int prioridad(char a){
	switch(a){
		case '(':
			return -1;
		case ')':
			return 0;
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

void apila(char a, stack* pila, char* B){
	char aux[2];	
	if(a=='(') Push(a, pila);
	else if(prioridad(a)> prioridad(TopeDePila(pila))){
		Push(a, pila);
		if(TopeDePila(pila)==')'){
			Pop(pila);
			Pop(pila);
		}
	}
	else{
		aux[0]=Pop(pila);
		aux[1]='\0';
		strcat(B, aux);
		apila(a, pila, B);
	}
	return;
}

void inf_pos(char* A, char* B){
	stack pila;
	int i;
	int longitud=strlen(A);
	
	if(ambito(A)){
		printf("Error en los parentesis de la expresion\n");
		strcat(B,"-");
		return;
	}
	else{
		CreateStack(&pila);
		Push('(', &pila);
		for(i=0;i<longitud;i++){
			char aux[2];
			aux[0]=A[i];
			aux[1]='\0';
			if(!es_operador(A[i])) strcat(B,aux);
			else apila(A[i], &pila, B);
		}
		apila(')', &pila, B);
	}
}

void Push(StackEntry item, stack* s);
StackEntry Pop(stack* s);
int StackEmpty(stack* s);
int StackFull(stack* s);
void CreateStack(stack* s);
StackEntry TopeDePila(stack* s);
void apila(char a, stack* pila, char* B);
int prioridad(char a);
int ambito(char* A);
int es_operador(char a);
void inf_pos(char* A, char* B);



int main(){
	char A[50],B[50];
	int i;
	strcpy(A,"");
	strcpy(B,"");
	
	printf("Ingrese una operacion en notacion infija, A:");
	scanf("%s", A);
	inf_pos(A, B);
	printf("Notacion postfija B:");
	printf("%s",B);
		
}
