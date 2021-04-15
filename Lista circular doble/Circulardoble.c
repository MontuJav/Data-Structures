#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
	struct nodo* atras;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void buscarNodo();
void desplegarListaPU();
void desplegarListaUP();
void modificarNodo();
void eliminarNodo();
int main(){
	int opcionMenu = 0;
	do{
		printf("\nMENU\n 1.Insertar\n2.Buscar\n3.Modificar\n4.Eliminar\n5.Desplegar primero al ultimo\n6.Desplegar Ultimo al primero\n7.Salir");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				insertarNodo();
				break;
			case 2:
				buscarNodo();
				break;	
			case 3:
				modificarNodo();
				break;
			case 4:
				eliminarNodo();
				break;
			case 5:
				desplegarListaPU();
				break;
			case 6:
				desplegarListaUP();
				break;
			case 7:
				printf("\n\n Programa finalizado...");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcionMenu != 7);
	return 0;
}



void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
		primero->atras = ultimo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		nuevo->atras = ultimo;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
	printf("\n\n Nodo Ingresado\n\n");
}

void desplegarListaPU(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}while(actual != primero);
	}else{
		printf("\n\n La Lista se encuentra vacia\n\n");
	}
}

void desplegarListaUP(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = ultimo;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->atras;
		}while(actual != ultimo);
	}else{
		printf("\n\n La Lista se encuentra vacia\n\n");
	}
}
void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado=0,encontrado=0;
	printf("Ingrese el dato del nodo a buscar:\n");
	scanf("\n%d",&nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato==nodoBuscado){
				printf("\n\nNodo con el dato %d encontrado\n",nodoBuscado);
				encontrado=1;
			}
			actual = actual->siguiente;
		}while(actual != primero);
		if(encontrado==0){
			printf("\n\nNodo no encontrado\n");
		}
	}else{
		printf("\n\n La Lista se encuentra vacia\n\n");
	}
}
void modificarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado=0,encontrado=0,modificado=0;
	printf("\nIngrese el dato del nodo a modificar:\n");
	scanf("\n%d",&nodoBuscado);
	printf("\nIngrese el nuevo dato del nodo:\n");
	scanf("\n%d",&modificado);
	
	if(primero!=NULL){
		do{
			if(actual->dato==nodoBuscado){
				printf("\nNodo con el dato %d modificado a %d\n",nodoBuscado,modificado);
				actual->dato=modificado;
				encontrado=1;
				break;
			}
			actual = actual->siguiente;
		}while(actual != primero);
		if(encontrado==0){
			printf("\nNodo no encontrado\n");
		}
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
}
void eliminarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n\n Nodo con el dato ( %d ) Encontrado", nodoBuscado);
				
				if(actual==primero){
					if(primero == ultimo)
						primero = ultimo = NULL;
					else
					{
						if(primero == ultimo)
							primero = ultimo = NULL;
						else
						{
							primero = primero->siguiente;
							primero->atras = ultimo;
							ultimo->siguiente = primero;
						}
					}					
				}else if(actual==ultimo){
					ultimo = anterior;
					ultimo->siguiente = primero;
					primero->atras = ultimo;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n\n Nodo eliminado\n\n");
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\n\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n\n La Lista se encuentra vacia\n\n");
	}
}
