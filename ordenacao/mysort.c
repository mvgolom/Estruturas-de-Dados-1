#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int* a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int* v, int n){
		 int i,fim;
			  for(fim=n-1;fim>0;fim--){
				int houve_troca = 0;
				for(i=0;i<fim;i++){
				  	if(v[i]>v[i+1]){
				  		troca(&v[i], &v[i+1]);
				  		houve_troca = 1;
				  	}
			  }
			if(houve_troca == 0) return;
	}
}


int menorElemeto(int v[],int n,int indice){
	int i,min = indice;
			for(i=indice+1;i<n;i++){
					if (v[i]<v[min]){
							min = i;
						}
			}
return min;
}

void selection_sort(int* v, int n){
	int i, min,count_troca;
		count_troca = 0;
		for(i=0; i<n-1;i++){
			min = menorElemeto(v, n, i);
			troca(&v[i], &v[min]);
		}
}

void insertion_sort(int* numeros, int n) {
   int i, j, eleito;
   for (i = 1; i < n; i++){
      eleito = numeros[i];
	      j = i - 1;
	      while ((j>=0) && (eleito < numeros[j])) {
	         numeros[j+1] = numeros[j];
	         j--;
      }
      numeros[j+1] = eleito;
   }
}

void shell_sort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}




void quickSort(int* vetor, int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) quickSort(vetor, inicio, j);
   if(i < fim) quickSort(vetor, i, fim);

}


void intercala(int* v,int inicio,int meio,int fim){
            int *temp, n1,n2,tam,i,j,k;
            int fim1=0,fim2=0;
              tam = fim-inicio+1;
              n1=inicio;
              n2=meio+1;
            temp = (int *) malloc (tam*sizeof(int));
            if(temp !=NULL){
                for(i=0;i<tam;i++){
                  if(!fim1 && !fim2){
                    if(v[n1] < v[n2])
                        temp[i]=v[n1++];
                     else
                        temp[i]=v[n2++];

                     if(n1>meio) fim1=1;
                     if(n2>fim)  fim2=1;
                   }else{
                      if(!fim1)
                         temp[i]=v[n1++];
                      else
                         temp[i]=v[n2++];

                   }
                }
                  for(j=0,k=inicio;j<tam;j++,k++)
                        v[k]=temp[j];
                   }
             free(temp);
}



void merge_Sort(int* v, int inicio, int fim){
   int meio;
    if(inicio < fim){
        meio = (inicio+fim)/2;
        merge_Sort(v, inicio, meio);
        merge_Sort(v,meio+1,fim);
        intercala(v,inicio,meio,fim);
      }

    }
















