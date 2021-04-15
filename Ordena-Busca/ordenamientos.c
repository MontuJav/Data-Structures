#include<stdio.h>


void QuickSort(int S[], int izq, int der);
int pivotear(int S[], int izq, int der);
void swap(int S[], int i, int j);
void ImprimeArray(int S[], int tam);
int BubbleSort(int S[], int tam);
int BubbleSortMejorado(int S[], int tam);

int main(){
	int i;
	int S[]={10,9,1,7,6,0,0,0,5,4,3,2,1,0};
	int tamanio=sizeof(S)/4;
	ImprimeArray(S, tamanio);
	//QuickSort(S,0,tamanio-1);
	//printf("\nIteraciones=%d\n",BubbleSort(S,tamanio));
	printf("\nIteraciones=%d\n",BubbleSortMejorado(S,tamanio));
	ImprimeArray(S, tamanio);
}

void QuickSort(int S[], int izq, int der){
	int pivote;
	if(izq<der){
		pivote=pivotear(S, izq, der);
		QuickSort(S, izq, pivote-1);
		QuickSort(S, pivote+1, der);
	}
}

int pivotear(int S[], int izq, int der){
	int PosPiv=(izq+der)/2;
	int ValPiv=S[PosPiv];
	int IndexL, IndexA;
	swap(S, PosPiv, der);
	IndexA=izq;
	
	for(IndexL=izq; IndexL<der; IndexL++){
		if(S[IndexL]<=ValPiv){
			ImprimeArray(S,10);
			swap(S, IndexL, IndexA);
			IndexA++;
		}
	}
	//Al salir IndexA dice donde debe ir el pivote en el nuevo arreglo.
	swap(S, IndexA, der);
	return IndexA;
}

int BubbleSort(int S[], int tam){
	//En la primera iteracion, colocamos un elemento en su posicion correcta
	//Asi en N-1 iteraciones, colocaremos N-1 elementos en su posicion correcta.
	//Iteraciones (N-1)N
	int i,j,iteraciones=0;
	
	for(j=0; j<tam-1; j++){//n-1 veces
		for(i=0; i<tam; i++){
			iteraciones++;
			if(S[i]>S[i+1]){
				swap(S, i, i+1);
			}
		}
	}
	return iteraciones;

}

int BubbleSortMejorado(int S[], int tam){
	//Consideraciones, no necesitamos mas iteraciones si en la iteracion anterior no se registro nungun SWAP.
	//No necesitamos atravesar el Loop interno hasta el final de las iteraciones, ya que si i=3, entonces 3 elementos ya estan ordenados.
	int i,j,iteraciones=0;
	int BooleanSwap=0;
	
	for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
			iteraciones++;
            if(S[i]>S[j]){
                swap(S,i,j);
			BooleanSwap=1;	
			}
        }
		if(!BooleanSwap)
				break;
    }
	return iteraciones;
}

void ImprimeArray(int S[], int tam){
	int i;
	
	for(i=0; i<tam; i++){
		if(i==0)
			printf("[ ");
		printf("%d ",S[i]);
		if(i==(tam-1))
			printf("]");
	}
}

void swap(int S[], int i, int j){
	int aux=S[j];
	S[j]=S[i];
	S[i]=aux;
}