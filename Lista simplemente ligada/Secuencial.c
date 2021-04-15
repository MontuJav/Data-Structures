#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

typedef int NodeEntry;

typedef struct node{
	NodeEntry llave;
	float promedio;
	char[30] nombre;
	int edad;
	struct node* next;
}node;

typedef struct data{
	float prom;
	char[30] nomb;
	int age;
}data;

node* head=NULL;

int sizeofList(){
	node* temp=head;
	int c=0;
	
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}

void pideDatos(node* newnode){
	int edad;
	float calif;
	char[30] nombre;
	
	printf("\nCalificacion: ");
	scanf("%f", &calf);
	printf("\nNombre: ");
	scanf("%s", &nomb);
	printf("\nEdad: ");
	scanf("%d", &edad);
	
	newnode->promedio=calf;
	newnode->nombre=nomb;
	newnode->edad=edad;
}

//Inserta en una llave de la lista (1,2,3,...,tamanio)
void insert(int llave){
	int tamanio=sizeofList();
	int i;
	node* temp=head;
	node* newnode=(node*)malloc(sizeof(node));
	node* prev=head;
	node* pos=head;
	
	
	if(llave==1){//Insertar al principio
		newnode->next=head;
		head=newnode;
		pideDatos(newnode);
	}
	else{
		if(llave>tamanio){
			if(llave==(tamanio+1)){//Insertar al final
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=newnode;
				pideDatos(newnode);
				newnode->next=NULL;
			}
			else{
				printf("\nError, la llave es mayor al tamanio\n");
				free(newnode);
			}
		}
		else{//llave m-esima
			pos=pos->next;
			for(i=2;i<llave;i++){
				prev=prev->next;
				pos=pos->next;
			}
			prev->next=newnode;
			newnode->next=pos;
			pideDatos(newnode);
		}
	}	
}

void delete(int llave){
	int tamanio=sizeofList();
	int i;
	node* prev=head;
	node* temp;//Previo al que quiero eliminar
	
	if(tamanio==0){
		printf("\nLista vacia\n");
	}
	else{
		if(llave==1){
			head=prev;
			head=head->next;
			free(prev);
		}
		else if(llave>tamanio)
			printf("\nError, la llave es mayor al tamanio\n");
		else{
			for(i=2;i<llave;i++){
				prev=prev->next;
			}
			temp=prev->next;
			prev->next=temp->next;
			free(temp);
		}
	}
}

void mostrarLista(){
	node* temp=head;
	int i=1;
	
	while(temp!=NULL){
		printf("------------------");
		printf("\nLlave %d ", i);
		printf("\n%f ", temp->promedio);
		printf("\n%s ", temp->nombre);
		printf("\n%d ", temp->edad);
		temp=temp->next;
	}
}

void VaciarLista(){
	head=NULL;
}

void SearchIndex(int llave){
	node* temp=head;
	int i;
	
	if(llave>sizeofList()){
		printf("\nNo hay nada en esa llave\n");
	}
	else{
		for(i=1;i<llave;i++){
			temp=temp->next;
		}
		printf("\nLos datos de la llave %d son:\n", llave);
		printf("|llave %d      |\n|promedio=%.2f|\n|nombre: %s|\n|edad=%d      |", llave, temp->promedio,temp->nombre,temp->edad);
	}
}

//Busca un elemento y regresa la llave, en caso de no encontrarlo regresa la bandera -1.
int Search(){
	int opc;
	int llave;
	char[30] name;
	int tamanio=sizeofList();
	node* temp=head;
	int i=1;
	
	printf("\n Buscar por Nombre(1)");
	printf("\n Buscar por Llave(2)");
	printf("\n Elija una opc: ");
	scanf("%d", &opc);
	
	if(opc==2){
		printf("\n Que llave: ");
		scanf("%d", &llave);
		SearchIndex(llave);
	}
	
	else{
		printf("\nNombre del estudiante buscado: ");
		scanf("%s", &name);

		if(tamanio==0){
			printf("\nLista vacia, elemento no encontrado\n");
			return -1;
		}
		
		else{
			while(temp!=NULL){
				if((temp->nombre)==name){
					printf("\nEl estudiante %s esta en la llave %d\n", name, i);
					moverElemento(i,-1);//Cada que se acceda a un elemento se mueve a la izquierda.
					return (i-1);
				}
				i++;
				temp=temp->next;
			}
			printf("\nElemento no encontrado\n");
			return -1;
		}
	}
}

void intercambiarElemento(int indiceInicial, int indiceFinal){
	node* tempi=head;
	node* tempf=head;
	int i,j;
	NodeEntry aux1, aux2, aux3;
	
	if((indiceInicial>sizeofList())||(indiceFinal>sizeofList())){
		printf("\nError, indices mayores al tamanioo de la lista\n");
	}
	
	else{
		for(i=1;i<indiceInicial;i++){
			tempi=tempi->next;
		}
		for(j=1;j<indiceFinal;j++){
			tempf=tempf->next;
		}
		
		aux1=tempf->data;
		tempf->data=tempi->data;
		tempi->data=aux1;
	}
}

//Mueve n llavees a la izq o derecha
//llavees: (-) Mueve a la izquierda
//llavees: (+) Mueve a la derecha
//llavees: (0) Se queda igual
void moverElemento(int indice, int movimientos){
	if(movimientos>0){
		intercambiarElemento(indice, indice++);
		movimientos--;
		moverElemento(indice, movimientos);
	}
	
	else if(movimientos==0){
		return;
	}
	
	else if(movimientos<0){
		intercambiarElemento(indice, indice--);
		movimientos++;
		moverElemento(indice, movimientos);
	}
}


void insert(NodeEntry item, int llave);
void delete(int llave);
void mostrarLista();
void VaciarLista();
int sizeofList();
NodeEntry SearchIndex(int llave);
int Search(NodeEntry elemento);
void intercambiarElemento(int indiceInicial, int indiceFinal);
void moverElemento(int indice, int llavees);

int main(){
	int opc=0;
	NodeEntry elemento;
	int llave, indexi, indexf, movimientos;
	
	do{
	system("CLS");
	printf("6666666666666 M E N U 6666666666666");
	printf("\n1.-Insertar registro");
	printf("\n2.- Eliminar");
	printf("\n3.- Imprimir");
	printf("\n4.- Buscar");
	printf("\n5.- Vaciar lista");
	printf("\n6.- Salir");
	printf("\nElija una opcion: ");
	scanf("%d", &opc);
	
	if(opc==1){
		printf("\nllave: ");
		scanf("%d", &llave);
		insert(elemento, llave);
		Sleep(1000);
	}
	
	else if(opc==2){
		printf("\nllave: ");
		scanf("%d", &llave);
		delete(llave);
		Sleep(1000);
	}
	
	else if(opc==3){
		mostrarLista();
		Sleep(3000);
	}
	
	else if(opc==4){
		printf("\nllave: ");
		scanf("%d", &llave);
		SearchIndex(llave);
		Sleep(3000);
	}
	
	else if(opc==6){
		VaciarLista();
	}
	
	}while(opc!=6);
	system("CLS");
	return 0;
}













