#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
    int data;
    struct node *anterior;
}Node;

typedef struct stack{
    int tam;
    Node *top;
}Stack;

Stack *create(){
    Stack* teste = (Stack*) malloc(sizeof(Stack));
    return teste;
}

/** comentarios para alteracoes se futuramente necessarias  */

void inicialize(Stack *p){
        p->tam=0;
}

void push(Stack *p, int e){

    if(p->tam==0){ // Se for o primeiro elemento
     p->top = (Node*) malloc(sizeof(Node));
     p->top->anterior = NULL; // O anterior dele será NULL <--
    }
    else{
        Node *test = (Node*) malloc(sizeof(Node)); // Crio um novo espaço
        test->anterior = p->top; // Armazeno o endereço atual do p->top no anterior deste novo espaço
        p->top = test; // Defino o endereço atual do p->top como o nosso novo espaço
    }
        p->top->data = e; // Insere o valor
        p->tam++;
}

void pop(Stack *p){
    Node *atual = p->top;
    p->top = p->top->anterior;
    p->tam--;
    free(atual);
}

int isEmptyStack(Stack *p){
 if(p->top == NULL){
            return 1; // Se estiver vazia, retorna 0
 }
 return 0; // Senão retorna 1
}

int sizeStack(Stack *p){
 return p->tam;
}
void printStack(Stack *p){
    if(sizeStack(p) > 0){
    printf("Elementos da pilha:\n");
    Node *aux; // Variavel auxiliar p/ armazenar endereço
    aux = p->top; // define como o endereço do atual p->top
    while(aux != NULL){
        printf("%d\n" ,aux->data);
        aux = aux->anterior; // define ele mesmo como o anterior
    }// loop para quando ele mesmo for NULL
    }
    else{
    printf("\nSem elementos na pilha!\n");
    }
}

int containsStack(Stack* p, int e){ // Retorna 1 se tiver, 0 se não tiver
    if(sizeStack(p) > 0){
    Node *aux;
    aux = p->top;
    while(aux != NULL){
        if(aux->data == e) return 1;
        aux = aux->anterior;
    }
    }
    return 0;
}