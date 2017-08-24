#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ItemType int

typedef struct{
    int first;
    int last;
    int length;
    int  Nelem;
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
        q->Nelem = 0;
	q->items = (ItemType*)malloc(5*sizeof(ItemType));
	q->length = 5;
}

int enqueue(Queue* q, ItemType e)
{
    int p;	
        if(q->Nelem >= q->length)
        {
                printf("sua lista esta cheia esvazie para continuar!!\n");
                return 0;
        }
        else if(q->Nelem < q->length)
        {
              if(q->last>=q->length)
              {
                p = q->last;
                p=p%5;
                q->items[p] = e;
                q->last++;
                q->Nelem++; 
              }  
            else
            {  
              q->items[q->last] = e;
              q->last++;
              q->Nelem++;
            }
        }
}

int dequeue(Queue* q, ItemType *e){
int p;
p = q->first;
p=p%5;
    if(q->Nelem < q->length)
        {
            if(q->first>=q->length)
            {
                *e = q->items[q->first];
                q->first++;
                q->Nelem--;
            }
        }
    else
    {
        *e = q->items[q->first];
	q->first++;
        q->Nelem--;
    }
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
 	for(i=q->first;i<=q->last-1;i++)
	{
		printf(" %d ",q->items[i%5]);
	}
	printf("\n");
 }
