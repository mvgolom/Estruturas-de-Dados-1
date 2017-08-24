#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ItemType int

typedef struct node{
    struct node *cima;
    int data;
    struct node *baixo;
}Node;

typedef struct stack{
    Node *top;
    Node *base;
    int limite;
    int size;
}Stack;



Stack* createStack();
void initializeStack(Stack* stack);
int push(Stack* p, ItemType e);
int pop(Stack* p, ItemType* e);
int top(Stack* p, ItemType* e);
void printStack(Stack* p);
int containsStack(Stack* p, ItemType *e);
int sizeStack(Stack* p);
int isEmptyStack(Stack* p);



Stack *createStack(){
Stack* p;   
    p = (Stack*) malloc(sizeof(Stack));
 if(p != NULL){   
    initializeStack(p);
    return p;
 }  
}

/** comentarios para alteracoes se futuramente necessarias  */

void initializeStack(Stack *p){
        p->limite = 4; 
        p->size=0;
}

int push(Stack* p, int e){
Node *novo;
Node *q;
    novo = (Node*) malloc(sizeof(Node));
    novo->baixo = NULL;
    novo->cima = NULL;
    novo->data = e;
    
    if(p->size==0){ // Se for o primeiro elemento
        p->top = novo;
        p->base = novo;
        p->size++;
        return 1;
    }
    
    
        if(p->size == 4){
            q = p->base;
            p->base = p->base->cima;
            p->base->baixo = NULL;
            q->cima = NULL;
            free(q);
            p->size--;
        }
        novo->baixo = p->top;
        p->top->cima = novo;
        p->top = novo;
        p->size++;
        return 1;
    } 
        


int pop(Stack *p, ItemType* e){
Node *q;    
    if(p->size == 0){
        return 0;
    }
    
    else if(p->size == 1){
      q=p->top;
      p->top = NULL;
      p->base = NULL;
      *e = q->data;
      free(q);
      p->size--;
      return 1;
    }
    else{
        
      q = p->top;
      p->top = p->top->baixo;
      p->top->cima = NULL;
      q->baixo = NULL;
      *e = q->data;
      free(p);
      p->size--;
      return 1;
    }
}

int isEmptyStack(Stack *p){
 if(p->size == 0){
      return 1; // Se estiver vazia, retorna 0
 }
 return 0; // Senão retorna 1
}

int sizeStack(Stack *p){
 return p->size;
}
void printStack(Stack *p){
      if(sizeStack(p) > 0){
        printf("Elementos da pilha:\n");
        Node *aux; // Variavel auxiliar p/ armazenar endereço
        aux = p->top; // define como o endereço do atual p->top
        while(aux != NULL){
            printf("%d\n" ,aux->data);
            aux = aux->baixo; // define ele mesmo como o anterior
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
            aux = aux->cima;
        }
    }
    return 0;
}