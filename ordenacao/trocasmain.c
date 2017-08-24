#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "mysort.c"
#include <time.h>

int main(){
	int op,n, i;
	int* vet;
printf("informe o tamanho do vetor \n");
scanf("%d", &n);
vet = (int *) calloc (n+1, sizeof(int));
	srand(time(NULL));
	for(i=0;i<n;i++){
		printf("Informe o valor da posicao %d \n",i+1 );
		scanf("%d", &vet[i]);
	}

	printf("Escolha uma opcao a seguir \n 1 - Bubble sort \n 2 - Selection sort\n 3 - insertion sort\n 4-shell sort\n");
	scanf("%d", &op);
	if(op == 1){
		bubble_sort(vet,n);
	}
	else if(op==2){
		selection_sort(vet,n);
	}
	else if(op==3){
		insertion_sort(vet,n);
	}
	else if(op==4){
		shell_sort(vet,n);
	}
printf("\n\n");
for(i=0;i<n;i++){
	printf(" %d ",vet[i]);
}



return 0;
}