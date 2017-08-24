#include <stdio.h>
#include "lib.h"

#define ItemType int //cria tipo ItemType

int main(){

int down=0,op,dash=0;
ItemType removed,take;//declara variaveis tipo ItemType
Queue *filad = createQueue();//cria vetor de Queue e cria a queue

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

	    	if(op == 1)
	    	{
	    		printf("Informe o elemento para inserir na fila\n");
	    		scanf("%d", &dash);
	    		system ("clear");
	    		enqueue(filad,dash);
	    	}

			
				if(op == 2)
				{
					take = dequeue(filad,&removed);
					if(take>0)
					{
						printf("Exclusao efetuada com sucesso\n");
					}
					else
                                            {
						printf("Erro na exclusao");	
					}
						getchar();
	    				getchar();
	    				system ("clear");

				}	

					
					if(op == 3)
					{
						take=0;
						peek(filad,&take);
						printf("%d\n",take);
						getchar();
	    				getchar();
	    				system ("clear");
					}


						else if(op == 4)
					    {
					    	printf("Informe o elemento a ser procurado\n");
		    				scanf("%d",&dash);
					    	take = contains(filad,&dash);
						    	if (take>0)
						    	{
						    		printf("O elemento foi encontrado\n");
						    	}
						    	else{
						    		printf("O elemento nao foi encontrado\n");
						    	}
						    	getchar();
	    						getchar();
	    						system ("clear");
						   
					    }

					     	else if(op == 5)
						     {
						     	take = sizeQueue(filad);
						     	printf("%d\n", take);
						     	getchar();
	    						getchar();
	    						system ("clear");
						     }

						     		
							     else if(op == 6)
							     {
							     	take = isEmptyQueue(filad);
							     		if(take>0)
							     		{
							     			printf("A fila esta vazia!!!\n");
							     		}
							     		else{
							     			printf("A fila contem elementos\n");
							     		}	
							     		getchar();
	    								getchar();
	    								system ("clear");
							     }else if(op == 10){printf("Marcos Vinicius Golom\n");}

							     	else if(op == 7){
							     		printQueue(filad);
							     	}
				else if(op == 8)
				{
		        	down = 10;
		    	}
	}while(down == 0);
        return 0;
}