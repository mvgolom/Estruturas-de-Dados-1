#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ItemType int

typedef struct node {
    ItemType data;
    struct node *next;
} Node;

typedef struct {
    Node *first;
    Node *last;
    int size;
} Queue;



Queue *createQueue();
void initializeQueue(Queue *q);
int enqueue(Queue* q, ItemType e);
int dequeue(Queue* q, ItemType* e);
int peek(Queue* q, ItemType* e); //primeiro elemento
int contains(Queue* q, ItemType* e); //procurar elemento 1 
int sizeQueue(Queue* q); //tamanho da fila
int isEmptyQueue(Queue* q); //a fila esta vazia
void printQueue(Queue* q); // imprimir a fila

Queue *createQueue() {
    Queue* p;
    p = (Queue*) malloc(sizeof (Queue));
    if (p != NULL) {
        initializeQueue(p);
        return p;
    } else {
        printf("Erro Queue not allocated");
    }
}

void initializeQueue(Queue *q) {
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
}

int enqueue(Queue* q, ItemType e) {
    Node* novo;
    novo = (Node*) malloc(sizeof (Node));
    novo->next = NULL;
    novo->data = e;
    if (q->size == 0) {
        q->last = novo;
        q->first = novo;
        q->size++;
    } else {
        q->last->next = novo;
        q->last = novo;
        q->size++;
    }
}

int dequeue(Queue* q, ItemType* e) {
    Node* p;
    if (q->size == 0) {
        return 0;
    } else if (q->size == 1) {
        p = q->first;
        q->first = NULL;
        q->last = NULL;
        *e = p->data;
        free(p);
        q->size--;
        return 1;
    } else {
        p = q->first;
        q->first = q->first->next;
        *e = p->data;
        free(p);
        q->size--;
        return 1;
    }
}

int peek(Queue* q, ItemType* e) {
    if (q->size == 0) {
        return 0;
    } else {
        *e = q->first->data;
    }
}

int contains(Queue* q, ItemType* e) {
    Node* jumper = q->first;
    if (q == NULL) {
        return 0;
    }
    while (jumper != NULL) {
        if (jumper->data == *e) {
            return 1;
        }
        jumper = jumper->next;
    }
    return 0;
}

int sizeQueue(Queue* q) {
    int aux;
    aux = q->size;
    return aux;
}

int isEmptyQueue(Queue* q) {
    if ((q->last == NULL) && (q->first == NULL)) {
        return 1;
    } else {
        return 0;
    }
}

void printQueue(Queue* q) {
    Node* jumper = q->first;
    printf("|");
    while (jumper != NULL) {
        printf("%d |", jumper->data);
        jumper = jumper->next;
    }
    printf("|\n");
    getchar();
    getchar();
    system("clear");
}