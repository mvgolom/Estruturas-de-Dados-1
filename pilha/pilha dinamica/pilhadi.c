#include <stdio.h>
#include "lib.h"


int main(){
    Stack *pilha = create();
    int aux=0;
    int num;
    inicialize(pilha);
    do{
    printf("+-------------------------------+\n");
    printf("|                               |\n");
    printf("|                               |\n");
    printf("|      Tamanho da pilha: %i     |\n", sizeStack(pilha));
    printf("|                               |\n");
    printf("|                               |\n");
    printf("+-------------------------------+\n");
    printf("1-Inserir elemento na pilha\n");
    printf("2-Excluir ultimo elemento da pilha\n");
    printf("3-Imprimir pilha\n");
    printf("4-Verificar se determinado elemento esta na pilha\n");
    printf("5-Sair\n\n");
    scanf("%d", &aux);
    system("clear");
    if(aux == 1){
            printf("Digite um numero: ");
            scanf("%d", &num);
            push(pilha, num);
    }
    else if(aux == 2){
        pop(pilha);
    }
    else if(aux == 3){
        printStack(pilha);
        getchar();
        getchar();
    }
    else if(aux == 4){
            printf("Digite um numero: ");
            scanf("%d", &num);
            if(containsStack(pilha, num)){
             printf("\n\nEste numero esta na pilha!");
            }
            else if (sizeStack(pilha)== 0){
             printf("\n\nEste numero nao esta na pilha afinal ela esta vazia!");
            }
            else{
             printf("\n\nEste numero nao esta na pilha!");
            }
            getchar();
            getchar();
    }
    system("clear");
    }while(aux != 5);
     exit(1);
}