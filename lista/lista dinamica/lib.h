#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ItemType int

typedef struct node{
    ItemType data;
    struct node *next;
}Node;

typedef struct{
    Node *first;
    Node *last;
    int size;
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
        l=(List*)malloc(sizeof(List));
            if(l!=NULL){
               initializeList(l);
               return l;

            }
            else{
 			printf("Error List not allocated");
            }
}

void initializeList(List *l){
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
}


int addLastList(List *l, ItemType e){
    Node* novo;
    novo = (Node*)malloc(sizeof(Node));
    novo->data = e;
    novo->next = NULL;
    
        if(l->size == 0){
            l->first = novo;
            l->last = novo;
            l->size++;
        }
        else{
            l->last->next = novo;
            l->last = novo;
            l->size++;
        }
}        

int addList(List* l, ItemType e, int index)
{
    int pos=1;
    Node* i;
    Node *antes,*depois;    

        Node* novo;
        novo = (Node*)malloc(sizeof(Node));
        novo->data = e;
        novo->next = NULL;        


            if(index>l->size)
            {
                addLastList(l,e);
                return 0;
            }

        else if(index == 0)
        {
            novo->next = l->first;
            l->first = novo;
            l->size++;
        }

        else
        {  
            depois = l->first;
            for (i = l->first; i != NULL ; i = i->next)
            {   
                    antes = depois;
                    depois = depois->next;
                        if(pos == index)
                        {
                            novo->next = depois;
                            antes->next = novo;
                            return 0;
                        }
                    antes = antes->next;
                    pos++;
            }   
            l->size++;
        }
}


int removeList(List* l, int index, ItemType *e)
{
    int pos=1;
    Node *i,*p;
    Node *antes,*depois;     

        if(index == 0)
        {
           p = l->first;    
           *e = p->data;
           l->first = l->first->next;
           free(p);
           l->size--;
        }
        
    
        else if(l->size == 1){
           *e = l->first->data;
           p=l->first;
           l->first = NULL;
           l->last = NULL;
           free(p);
           l->size--;
        } 
            else if((index > 0)&&(index <= l->size)){
                    depois = l->first;
                        for (i = l->first; i != NULL ; i = i->next)
                        {   
                            antes = depois;
                            depois = depois->next;

                            if(depois->next==NULL){
                              l->last =antes; 
                              antes->next = NULL;
                              *e = depois->data;
                              free(depois);
                              l->size--;
                              return 1;
                            }

                                else if(pos == index){
                                    antes->next = depois->next;
                                    *e = depois->data;
                                    free(depois);
                                    l->size--;
                                    return 1;
                                }

                            antes = antes->next;
                            pos++;
                        }
            }
                
}


int removeElementList(List* l, ItemType* e){

Node *i,*p;
Node *antes,*depois;    
    if(l->first->data == *e){
        p = l->first;
        l->first = l->first->next;
        if(l->first == NULL) l->last = NULL;
        
        *e = p->data;
        free(p);
        l->size--;           
    }else{
        antes = l->first;
        for(depois = l->first->next;depois != NULL;depois = depois->next)
        {
            if(depois->data == *e)
            {
                antes->next = depois->next;
                if(antes->next == NULL) l->last = antes;                        
                free(depois);
                l->size--;
                return 1;
            }
        }
        return 0;
    }
}
                    

int getList(List* l, int index, ItemType* e){
 int pos = 1;
 Node *depois;
       if(index == 0){
           *e = l->first->data;
           return 0;
       }    
 
        else
        {    
            for(depois = l->first;depois->next != NULL;depois = depois->next){
                if(pos == index){
                  *e = depois->data;
                  return 1;
                }

              pos++;
            }
          return 0;  
        }    
}

int setList(List* l, int index, ItemType* e){
Node *ponte;
int pos=0;
ponte = l->first;

        if(pos <= l->size)
        {
            while(ponte != NULL){
                if(pos==index){
                  ponte->data = *e;
                  return 1;
                }
            ponte = ponte->next;
            pos++;
            }
        }

    else
    {
        return 0;
    }
return 0;
}

int indexOfList(List* l, ItemType* e){
Node *ponte;
int pos=0;
ponte = l->first;

        if(pos <= l->size)
        {
            while(ponte != NULL){
                if(ponte->data==*e){
                  return pos;
                }
            ponte = ponte->next;
            pos++;
            }
        }

    else
    {
        return 0;
    }
}


int containsList(List* l, ItemType *e){
Node *ponte;
int pos=0;
ponte = l->first;

        if(pos <= l->size)
        {
            while(ponte != NULL){
                if(ponte->data==*e){
                  return 1;
                }
            ponte = ponte->next;
            pos++;
            }
        }

    else
    {
        return 0;
    }
}

int sizeList(List* l){
   int p;
   p = l->size;
   return p;        
}

int isEmptyList(List* l){
    return ((l->first == NULL)&&(l->last == NULL));
}

void printList(List* l){
Node *i;
printf("|");
    for(i = l->first;i!=NULL;i=i->next){
        printf(" %d |",i->data);
    }
printf("\n");
}
