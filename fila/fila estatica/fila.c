#include <stdio.h>
#include "lib.h"

#define ItemType int


int main(){
int down=0,op,dash=0;
ItemType removed,take;
Queue* fila=createQueue();

do{
        printf("+------------------------------------+\n");
        printf("| 1-Inserir elemento                 |\n");
        printf("| 2-Excluir elemento                 |\n");
        printf("| 3-primeiro elemento                |\n");
        printf("| 4-Procurar na lista                |\n");
        printf("| 5-qual o tamanho da fila           |\n");
        printf("| 6-A fila esta vazia                |\n");
        printf("| 7-Imprimir a fila                  |\n");
        printf("| 8-Sair                             |\n");
        printf("+------------------------------------+\n");
        scanf("%i", &op);
        system ("clear");

    if(op==1)
    {
    	printf("Informe o elemento\n");
    	scanf("%d",&dash);
    	enqueue(fila,dash);
    	
    }

	    else if(op == 2)
	    {
	        dequeue(fila,&removed);
	    }

		    else if(op == 3)
		    {
		    	peek(fila,&take);
		    	printf("%d\n",take);

		    }

			    else if(op == 4)
			    {
			    	printf("Informe o elemento a ser procurado\n");
    				scanf("%d",&dash);
			    	take = contains(fila,&dash);
				    	if (take>0)
				    	{
				    		printf("O elemento foi encontrado\n");
				    	}
				    	else{
				    		printf("O elemento nao foi encontrado\n");
				    	}
				   
			    }

				     else if(op == 5)
				     {
				     	take = sizeQueue(fila);
				     	printf("%d\n", take);
				     }

				     else if(op == 6)
				     {
				     	take = isEmptyQueue(fila);
				     }

				     else if(op == 7)
				     {
				     	printQueue(fila);
				     }	

    else if(op == 8){
        down = 10;
    }




}while(down == 0);

}
