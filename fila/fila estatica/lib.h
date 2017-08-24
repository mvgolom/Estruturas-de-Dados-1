#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ItemType int

typedef struct{
    int first;
    int last;
    int length;
    ItemType *items;
}Queue;


Queue *createQueue ();

void initializeQueue(Queue *q);

int enqueue(Queue* q, ItemType e);

int dequeue(Queue* q, ItemType* e);

int peek(Queue* q, ItemType* e); // colocar o first no *e

int contains(Queue* q, ItemType *e); //contem na fila se existe 1 se nao 0

int sizeQueue(Queue* q); //tamanho da fila

int isEmptyQueue(Queue* q); // fila esta vazia?

void printQueue(Queue* q);//impreimir a fila

Queue *createQueue (){
 Queue* p;
 	p=(Queue*)malloc(sizeof(Queue));
 	if(p != NULL){
 		initializeQueue(p);
 		return p;
 	}
 	else{
 		printf("Erro Queue not allocated");
 	}
}

void initializeQueue(Queue *q){
	q->first = 0;
	q->last = 0;
	q->items = (ItemType*)malloc(10*sizeof(ItemType));
	q->length = 10;
}

int enqueue(Queue* q, ItemType e){
	 if(q->last >= q->length){
        printf("Sua fila esta cheia!!\n");
        return 0;
     }

	q->items[q->last] = e;
	q->last++;
}

int dequeue(Queue* q, ItemType *e){
    *e = q->items[q->first];
    q->items[q->first] = 0;
	q->first++;
}

int peek(Queue* q, ItemType* e){
	*e = q->items[q->first];

}

int contains(Queue* q, ItemType *e)
{
	int i,j=0;
	for(i=0;i<=q->length;i++)
	{
		if(q->items[i] == *e)
		{
			return 1;
			j++;
		}
	}
	  if(j==0){
	  	return 0;
	  }
	   	
}

int sizeQueue(Queue* q)
{
	int aux;
	aux = q->length;
	return aux;
}

int isEmptyQueue(Queue* q)
{
    if(q->last == q->first)
    {
        printf("A fila esta vazia\n");
    }
    else
    {
      printf("A fila contem alguns elementos\n");
    } 
 }

 void printQueue(Queue* q){
 	int i;
 	for(i=0;i<=q->length-1;i++)
	{
		printf("%d ->",q->items[i]);
		printf("\n");
	}
 }
