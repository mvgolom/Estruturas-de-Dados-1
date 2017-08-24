#include <stdio.h>
#include "lib.h"

#define ItemType int

int main(){
int down=0,op,dash;
ItemType removed,take;
Stack* pilha = createStack();

do{
        printf("+------------------------------------+\n");
        printf("| 1-Inserir elemento                 |\n");
        printf("| 2-Excluir elemento                 |\n");
        printf("| 3-primeiro elemento                |\n");
        printf("| 4-Imprimir a pilha                 |\n");
        printf("| 5-Procurar na pilha                |\n");
        printf("| 6-qual o tamanho da pilha          |\n");
        printf("| 7-A pilha esta vazia               |\n");
        printf("| 8-Sair                             |\n");
        printf("+------------------------------------+\n");
        scanf("%i", &op);
        system ("clear");

        if(op == 1){
            printf("Informe o elemento\n");
            scanf("%d",&dash);
            push(pilha,dash);
        }
            
        else if(op == 2){
            pop(pilha,&removed);
        }

                else if(op == 3){
                    top(pilha,&take);
                    printf("%d\n",take);
                }


                    else if(op == 4){
                             printStack(pilha);
                        }
                        
                        else if(op == 5){
                            printf("Informe o elemento a ser procurado\n");
    				scanf("%d",&dash);
			    	take = containsStack(pilha,&dash);
				    	if (take>0)
				    	{
				    		printf("O elemento foi encontrado\n");
				    	}
				    	else{
				    		printf("O elemento nao foi encontrado\n");
				    	}
                        }

                            else if(op == 6){
                                sizeStack(pilha);
                            }
                                
                                 else if(op == 7)
                                 {
                                   isEmptyStack(pilha);
                                 }

            else if(op == 8){
                down = 10;
            }


    }while(down == 0);

}