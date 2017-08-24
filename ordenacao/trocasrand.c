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
		vet[i]=rand()%n;
	}

	printf("Escolha uma opcao a seguir \n 1 - Bubble sort \n 2 - Selection sort\n 3 - Insertion sort\n 4 - Merge sort\n 5-Shell sort\n 6 - Quick sort\n");
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
		merge_Sort(vet,0,n);
	}
	else if(op==5){
		shell_sort(vet,n);
	}
	else if(op==6){
		quickSort(vet, 0, n);
	}
printf("\n\n");
for(i=0;i<n;i++){
	printf(" %d \n",vet[i]);
}



return 0;
}
