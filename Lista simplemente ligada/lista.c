#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

typedef int NodeEntry;

typedef struct node{
	NodeEntry data;
	struct node* next;
}node;

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

//Inserta en una posicion de la lista (1,2,3,...,tamanio)
void insert(NodeEntry item, int posicion){
	int tamanio=sizeofList();
	int i;
	node* temp=head;
	node* newnode=(node*)malloc(sizeof(node));
	node* prev=head;
	node* pos=head;
	
	
	if(posicion==1){//Insertar al principio
		newnode->next=head;
		head=newnode;
		newnode->data=item;
	}
	else{
		if(posicion>tamanio){
			if(posicion==(tamanio+1)){//Insertar al final
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=newnode;
				newnode->data=item;
				newnode->next=NULL;
			}
			else{
				printf("\nError, la posicion es mayor al tamanio\n");
				free(newnode);
			}
		}
		else{//Posicion m-esima
			pos=pos->next;
			for(i=2;i<posicion;i++){
				prev=prev->next;
				pos=pos->next;
			}
			prev->next=newnode;
			newnode->next=pos;
			newnode->data=item;
		}
	}	
}

void delete(int posicion){
	int tamanio=sizeofList();
	int i;
	node* prev=head;
	node* temp;//Previo al que quiero eliminar
	
	if(tamanio==0){
		printf("\nLista vacia\n");
	}
	else{
		if(posicion==1){
			head=prev;
			head=head->next;
			free(prev);
		}
		else if(posicion>tamanio)
			printf("\nError, la posicion es mayor al tamanio\n");
		else{
			for(i=2;i<posicion;i++){
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
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
}

void VaciarLista(){
	head=NULL;
}

NodeEntry SearchIndex(int posicion){
	NodeEntry item;
	node* temp=head;
	int i;
	
	if(posicion>sizeofList()){
		printf("\nNo hay nada en esa posicion\n");
	}
	else{
		for(i=1;i<posicion;i++){
			temp=temp->next;
		}
		item=temp->data;
		printf("\nEL dato de la posicion %d es: %d\n", posicion, item);
	}
	return item;
}

//Busca un elemento y regresa el indice, en caso de no encontrarlo regresa la bandera -1
int Search(NodeEntry elemento){
	int tamanio=sizeofList();
	node* temp=head;
	int i=1;
	
	if(tamanio==0){
		printf("\nLista vacia, elemento no encontrado\n");
		return -1;
	}
	
	else{
		while(temp!=NULL){
			if((temp->data)==elemento){
				printf("\nEl elemento %d esta en el indice %d\n", elemento, i);
				return i;
			}
			i++;
			temp=temp->next;
		}
		printf("\nElemento no encontrado\n");
		return -1;
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

//Mueve n posiciones a la izq o derecha
//Posiciones: (-) Mueve a la izquierda
//Posiciones: (+) Mueve a la derecha
//Posiciones: (0) Se queda igual
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


void insert(NodeEntry item, int posicion);
void delete(int posicion);
void mostrarLista();
void VaciarLista();
int sizeofList();
NodeEntry SearchIndex(int posicion);
int Search(NodeEntry elemento);
void intercambiarElemento(int indiceInicial, int indiceFinal);
void moverElemento(int indice, int posiciones);

int main(){
	int opc=0;
	NodeEntry elemento;
	int posicion, indexi, indexf, movimientos;
	
	do{
	system("CLS");
	printf("6666666666666 M E N U 6666666666666");
	printf("\n1.-Insertar elemento");
	printf("\n2.- Eliminar");
	printf("\n3.- Imprimir");
	printf("\n4.- Buscar por posicion");
	printf("\n5.- Buscar elemento");
	printf("\n6.- Vaciar lista");
	printf("\n7.- Intercambiar elemento");
	printf("\n8.- Mover elemento");
	printf("\n9.- Salir");
	printf("\nElija una opcion: ");
	scanf("%d", &opc);
	
	if(opc==1){
		printf("\nElemento a insertar: ");
		scanf("%d", &elemento);
		printf("\nPosicion: ");
		scanf("%d", &posicion);
		insert(elemento, posicion);
		Sleep(1000);
	}
	
	else if(opc==2){
		printf("\nPosicion: ");
		scanf("%d", &posicion);
		delete(posicion);
		Sleep(1000);
	}
	
	else if(opc==3){
		mostrarLista();
		Sleep(3000);
	}
	
	else if(opc==4){
		printf("\nPosicion: ");
		scanf("%d", &posicion);
		SearchIndex(posicion);
		Sleep(3000);
	}
	
	else if(opc==5){
		printf("\nDato: ");
		scanf("%d", &elemento);
		Search(elemento);
		Sleep(3000);
	}
	
	else if(opc==6){
		VaciarLista();
	}
	
	else if(opc==7){
		printf("\nIndice indice inicial: ");
		scanf("%d", &indexi);
		printf("\nIndice final: ");
		scanf("%d", &indexf);
		intercambiarElemento(indexi, indexf);
		Sleep(3000);
	}
	
	else if(opc==8){
		printf("\nIndice: ");
		scanf("%d", &indexi);
		printf("\nMovimientos: ");
		scanf("%d", &movimientos);
		moverElemento(indexi, movimientos);
		Sleep(3000);
	}
	
	}while(opc!=9);
	system("CLS");
	return 0;
}













