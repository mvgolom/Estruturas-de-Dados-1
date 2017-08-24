#include <stdio.h>
#include "lib.h"

#define ItemType int

ItemType removed,dash;
int down=0,op;

List *lista = createList ();

int main(){
    do{
            printf("+------------------------------------+\n");
            printf("| 1-Inserir elemento                 |\n");
            printf("| 2-Excluir elemento                 |\n");
            printf("| 3-primeiro elemento                |\n");
            printf("| 4-Procurar                         |\n");
            printf("| 5-qual o tamanho                   |\n");
            printf("| 6-       esta vazia                |\n");
            printf("| 7-Imprimir                         |\n");
            printf("| 8-Sair                             |\n");
            printf("+------------------------------------+\n");
            scanf("%i", &op);
            system ("clear");
        
            
            
            if(op == 1){
                printf("Informe o elemento para adicionar\n");
                scanf("%d", &dash);
                addLastList(lista,dash);
            }
            
            

            
            else if (op == 8){
                down = 10;
            }
            
            
    }while(down == 0);
return 0;
}