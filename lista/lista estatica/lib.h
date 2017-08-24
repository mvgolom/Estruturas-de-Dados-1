#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define ItemType int

typedef struct{
    int size;
    int length;
    ItemType *items;
}List;


List *createList ();
void initializeList(List *l);
int addLastList(List *l, ItemType e);
int addList(List* l, ItemType e, int index);
int removeList(List* l, int index, ItemType *e);
int removeElementList(List* l, ItemType* e);
int getList(List* l, int index, ItemType* e);
int setList(List* l, int index, ItemType* e);
int indexOfList(List* l, ItemType* e);
int containsList(List* l, ItemType *e);
int sizeList(List* l);
int isEmptyList(List* l);
void printList(List* l);


List *createList (){
  List* l;
  l =(List*)malloc(sizeof(List));
    if(l != NULL){
        initializeList(l);
        return l;
    }
    else{
      printf("List not alloced \n");  
    }
}

void initializeList(List *l){
    l->size = 0;
    l->items = (ItemType*)calloc(10,sizeof(ItemType));
    l->length = 10;
}

int addLastList(List *l, ItemType e){
    l->items[l->size] = e;
    l->size++;
}

int addList(List* l, ItemType e, int index){
    
}