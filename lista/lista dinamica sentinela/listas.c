#include <stdio.h>
#include "lib.h"

#define ItemType int

int main(){
int down=0,op,dash=0,pos;
ItemType removed,take;
List* lista=createList();

do{
        printf("+---------------------------------------+\n");
        printf("|                                       |\n");
        printf("|  1 - Inserir elemento                 |\n");
        printf("|  2 - Inserir elemento por posicao     |\n");
        printf("|  3 - Excluir elemento por posicao     |\n");
        printf("|  4 - Excluir por elemento             |\n");
        printf("|  5 - recuperar um elemento na posicao |\n");
        printf("|  6 - Trocar elemento na lista         |\n");
        printf("|  7 - Procurar elemento na lista       |\n");
        printf("|  8 - O elemento esta contido na lista |\n");
        printf("|  9 - O tamanho da lista               |\n");
        printf("| 10 - A lista esta vazia               |\n");
        printf("| 11 - Imprimir a lista                 |\n");
        printf("| 12 - Sair                             |\n");
        printf("|                                       |\n");
        printf("+---------------------------------------+\n");
        scanf("%i", &op);
        system ("clear"); 
        
    if(op == 1){
        printf("Informe o elemento para ser adicionado a lista\n");
        scanf("%d", &dash);
        addLastList(lista,dash);
    }    
    
        else if(op == 2)
        {
            take = sizeList(lista);
            printf("Informe a posicao para a insercao de 0 -- %d\n",take);
            printf(" \n");
            scanf("%d",&pos);
            printf("Informe o elemento para ser adicionado a lista\n");
            scanf("%d", &dash);
            addList(lista,dash,pos);
        }
        else if(op == 3){
            take = sizeList(lista);
            printf("Informe a posicao para a remocao de 0 -- %d\n",take);
            printf("Informe a posicao para a  \n");
            scanf("%d",&pos);            
            removeList(lista,pos,&removed);
        }
        else if(op == 4){
            printf("Informe o valor a ser deletado\n");
            scanf("%d",&dash);
            take = removeElementList(lista,&dash);
                if(take == 1){
                   printf("Elemento deletado com sucesso!!!\n"); 
                }

                    else{
                      printf("O elemento nao foi encontrado!!\n");  
                    }
            getchar();
            getchar();
            system ("clear");
        }
        else if(op == 5){
            printf("Informe a posicao a ser recuperada \n");
            scanf("%d",&pos);
            dash =  getList(lista,pos,&take);
            if(dash == 1){
                printf("A posicao foi recuperada com sucesso!!\n");
            }
            else{
                printf("A posicao nao foi recuperada!!\n");
            }
            getchar();
            getchar();
            system ("clear");
        }
        
        else if(op == 6){
            printf("Informe a posicao do numero a ser trocado \n");
            scanf("%d",&pos);
            printf("Informe o numero para a troca \n");
            scanf("%d",&dash);
            take = setList(lista,pos,&dash);
            getchar();
            getchar();
            system ("clear");
        }
        
        else if(op == 7){
            printf("Informe o numero a ser procurado \n");
            scanf("%d",&dash);
            take = indexOfList(lista,&dash);
                if(take > 0){
                  printf("O elemento se enconta na posicao %d \n", take);  
                }
            else{
              printf("O elemento nao foi encontrado \n");      
            }
            getchar();
            getchar();
            system ("clear");
        }

        else if(op == 8){
            printf("Informe o numero a ser procurado \n");
            scanf("%d",&dash);
            take = containsList(lista,&dash);
                if(take == 1){
                  printf("O elemento se encontra na lista \n");  
                }
            else{
              printf("O elemento nao foi encontrado \n");      
            }
            getchar();
            getchar();
            system ("clear");
        }
        
        else if(op == 9){
            take=sizeList(lista);
            printf("O tamanho da lista e %d\n", take);
        }
        
        else if(op == 10){
           take = isEmptyList(lista);
           if(take == 1){
               printf("A lista esta vazia \n");
           getchar();
           getchar();
           system ("clear");
           }
           else{
              printf("A lista ainda contem elementos \n"); 
           }
           getchar();
           getchar();
           system ("clear");
        }
        
        if(op == 11){
           printList(lista); 
           getchar();
           getchar();
           system ("clear");
        }
    
    else if(op == 12){
        down = 10;
    }    
}while(down==0);
    
}
