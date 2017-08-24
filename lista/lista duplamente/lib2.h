#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ItemType int


typedef struct node{
	ItemType data;
	struct node *prev;
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
    novo->prev = NULL;
    novo->next = NULL;
    
        if(l->size == 0){
            l->first = novo;
            l->last = novo;
            l->size++;
        }
        else{
            novo->prev = l->last;
            
            l->last->next = novo;
            l->last = novo;
            l->size++;
        }
}      

int addList(List* l, ItemType e, int index){
    int pos=0,middle;
    int lPos = l->size;
    Node* i;
    Node *ponte;
    middle = l->size/2;

        Node* novo;
        novo = (Node*)malloc(sizeof(Node));
        novo->data = e;
        novo->prev = NULL;
        novo->next = NULL;        

        if(index > l->size){
            return 0;
        }
        
            else if(index == l->size)
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
                         if(index <= middle){
                                for (ponte = l->first; ponte != NULL ; ponte = ponte->next){   

                                            if(lPos == index)
                                            {
                                                novo->next = ponte;

                                                novo->prev = ponte->prev;
                                                novo->prev->next = novo;
                                                ponte->prev = novo;
                                                l->size++;
                                                return 0;
                                            }
                                    lPos--;
                                }
                            }
                            else
                            {
                               for (ponte = l->last; ponte != NULL ; ponte = ponte->prev){   

                                            if(pos == index)
                                            {
                                                novo->next = ponte;

                                                novo->prev = ponte->prev;
                                                novo->prev->next = novo;
                                                ponte->prev = novo;
                                                l->size++;
                                                return 0;
                                            }
                                    pos++;
                                } 
                            }
                    }
}
int removeList(List* l, int index, ItemType *e)
{   
    int pos=0,middle,lPos;
    Node *ponte;
    lPos = l->size;
    middle = l->size/2;
        if(index == 0)
        {
           ponte = l->first;
           
           l->first = l->first->next;   
           l->first->prev = NULL;
           ponte->next = NULL;
           *e = ponte->data;
           free(ponte);
           l->size--;
        }
        
    
            else if(l->size == 1)
            {
               *e = l->first->data;
               ponte=l->first;
               l->first = NULL;
               l->last = NULL;
               free(ponte);
               l->size--;
            } 
            else if((index > 0)&&(index <= l->size))
            {
                
                if(index <= middle){  
                        for (ponte = l->first; ponte != NULL ; ponte = ponte->next)
                        { 
                             if(pos == index)
                             {   
                                if(ponte->next==NULL){
                                    ponte->prev->next = NULL;
                                    *e = ponte->data;
                                    free(ponte);
                                    l->size--;
                                    return 1;
                                }          
                                ponte->prev->next = ponte->next;
                                ponte->next->prev = ponte->prev;
                                *e = ponte->data;
                                free(ponte);
                                l->size--;
                                return 1;
                            }
                            pos++;
                        }
                      return 0;
                    }

                else if(index > middle){
                    for (ponte = l->last; ponte != NULL ; ponte = ponte->prev)
                    { 
                         if(lPos == index)
                         {   
                            if(ponte->next==NULL){
                                ponte->prev->next = NULL;
                                *e = ponte->data;
                                free(ponte);
                                l->size--;
                                return 1;
                            }          
                            ponte->prev->next = ponte->next;
                            ponte->next->prev = ponte->prev;
                            *e = ponte->data;
                            free(ponte);
                            l->size--;
                            return 1;
                        }
                        lPos--;
                    }
                  return 0;
                }
            }   
}
          

int removeElementList(List* l, ItemType* e){
Node *ponte;    
    
    if(l->first->data == *e)
    {
        ponte = l->first;
        l->first = l->first->next;
        l->first->prev = NULL;
        if(l->first == NULL) l->last = NULL;
        
        *e = ponte->data;
        free(ponte);
        l->size--;           
    }else{
        for(ponte = l->first->next;ponte != NULL;ponte = ponte->next)
        {
            if(ponte->data == *e)
            {
                if(ponte->next==NULL){
                    ponte->prev->next = NULL;
                    *e = ponte->data;
                    free(ponte);
                    l->size--;
                    return 1;
                }
                                    
                ponte->prev->next = ponte->next;
                ponte->next->prev = ponte->prev;
                *e = ponte->data;
                free(ponte);
                l->size--;
                return 1;
            }
        }
        return 0;
    }
}

int getList(List* l, int index, ItemType* e){
 int pos=0,lPos,middle;
 Node *ponte;
 lPos = l->size;
 middle = l->size/2;
       
       if(index == 0){
           *e = l->first->data;
           return 0;
       }    
 
        else
        {    
	            if(index <= middle){
		            for(ponte = l->first;ponte != NULL;ponte = ponte->next){
		                if(pos == index){
		                  *e = ponte->data;
		                  return 1;
		                }
		              pos++;
		            }
		        }
		        
		        else if(index > middle){
		            for(ponte = l->last;ponte != NULL;ponte = ponte->prev){
		                if(lPos == index){
		                  *e = ponte->data;
		                  return 1;
		                }
		              lPos--;
	            	}
	            }	

          return 0;  
        }    
}

int setList(List* l, int index, ItemType* e)
{
Node *ponte;
int pos=0,middle,lPos;
lPos = l->size;
middle = l->size/2;

        if(index <= l->size)
        {
        	if(index <= middle){
	            for(ponte = l->first;ponte != NULL;ponte = ponte->next){
	                if(pos==index){
	                  ponte->data = *e;
	                  return 1;
	                }
	            	pos++;
	            }
	        }
	        else if(index > middle){
	            for(ponte = l->last;ponte != NULL;ponte = ponte->prev){
	                if(lPos==index){
	                  ponte->data = *e;
	                  return 1;
	                }
	            	lPos--;
	            }
	        }    
        
        }

    else
    {
        return 0;
    }
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