#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ItemType int

typedef struct{
    int top;
    int length;
    ItemType *items;
}Stack;


Stack* createStack();
void initializeStack(Stack* stack);
int push(Stack* stack, ItemType e);
int pop(Stack* stack, ItemType* e);
int top(Stack* stack, ItemType* e);
void printStack(Stack* stack);
int containsStack(Stack* stack, ItemType *e);
int sizeStack(Stack* stack);
int isEmptyStack(Stack* stack);

Stack* createStack(){
    Stack* p;
    p=(Stack*)malloc(sizeof(Stack));
        if(p != NULL){
            initializeStack(p);
            return p;
        }
        else{
 		printf("Erro Stack not allocated\n");
 	}
}

void initializeStack(Stack* stack){
    stack->top = 0;
    stack->items = (ItemType*)malloc(10 * sizeof(ItemType));
    stack->length = 0;
}

int push(Stack* stack, ItemType e){
   if(stack->top >= 10){
       printf("A fila esta cheia!!!\n");
       return 0;
   }
   stack->items[stack->top] = e;
   stack->top++;
   stack->length++;
}

int pop(Stack* stack, ItemType* e){
    *e = stack->items[stack->top-1];
    stack->items[stack->top-1] = 0;
	stack->top--;
	stack->length--;
}

int top(Stack* stack, ItemType* e){
    int i = stack->top;
    *e = stack->items[stack->top-1];
}

void printStack(Stack* stack){
 	int i;
            for(i=0;i<=stack->top-1;i++)
            {
                    printf("%d ",stack->items[i]);
                    printf("\n");
            }
 }

int containsStack(Stack* stack, ItemType* e){
    int i,j=0;
    for(i=0;i<stack->top;i++){
        if(stack->items[i] == *e){
            return 1;
            j++;
        }
    }
    return 0;
}

int sizeStack(Stack* stack){
    printf("%d\n",stack->length);
}

int isEmptyStack(Stack* stack){
    if(stack->top == 0){
        printf("A pilha esta vazia\n");
    }
    else
    {
      printf("A pilha contem alguns elementos\n");
    } 
 }