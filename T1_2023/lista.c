#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct node {
    Item info;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list {
    int size, max;
    Node *head;
    Node *tail;
} List;

Lista createLst(int capacidade){
    List *l = calloc(1, sizeof(List));
    if (capacidade < 0)
    {
      l->max = __INT_MAX__;
    } else {
      l->max = capacidade;
    }
    return l;
}

int lengthLst(Lista l){
    List *list = (List*) l;
    return list->size;
}

int maxLengthLst(Lista l){
    List *list = (List*) l;
    return list->max;
}

bool isEmptyLst(Lista l){
    List *list = (List*) l;
    return list->size == 0;
}

bool isFullLst(Lista l){
    return false;
}

Posic insertLst(Lista l, Item i){
    List *list = (List*) l;
    Node *n = calloc(1, sizeof(Node));
    n->info = i;
    n->next = NULL;
    n->prev = NULL;
    if (list->size == 0)
    {
      list->head = n;
      list->tail = n;
    } else {
      list->tail->next = n;
      n->prev = list->tail;
      list->tail = n;
    }
    list->size++;
    return n;
}

//Perguntar se o primeiro seria a head ou a tail

Item popLst(Lista l){
    List *list = (List*) l;
    Node *n = list->head;
    Item i = n->info;
    list->head = n->prev;
    list->head->next = NULL;
    free(n);
    list->size--;
    return i;
}

void removeLst(Lista l, Posic p){
    List *list = (List*) l;
    Node *n = (Node*) p;
    if (n->prev == NULL)
    {
      list->head = n->next;
      list->head->prev = NULL;
    } else if (n->next == NULL)
    {
      list->tail = n->prev;
      list->tail->next = NULL;
    } else {
      n->prev->next = n->next;
      n->next->prev = n->prev;
    }
    free(n);
    list->size--;
}

Item getLst (Lista l, Posic p){
    Node *n = (Node*) p;
    return n->info;
}

Posic insertBefore(Lista l, Posic p, Item info){
    List *list = (List*) l;
    Node *n = calloc(1, sizeof(Node));
    n->info = info;
    n->next = NULL;
    n->prev = NULL;
    Node *aux = (Node*) p;
    if (aux->prev == NULL)
    {
      list->head = n;
      n->next = aux;
      aux->prev = n;
    } else {
      aux->prev->next = n;
      n->prev = aux->prev;
      n->next = aux;
      aux->prev = n;
    }
    list->size++;
    return n;
}

Posic insertAfterLst(Lista l, Posic p, Item info){
    List *list = (List*) l;
    Node *n = calloc(1, sizeof(Node));
    n->info = info;
    n->next = NULL;
    n->prev = NULL;
    Node *aux = (Node*) p;
    if (aux->next == NULL)
    {
      list->tail = n;
      n->prev = aux;
      aux->next = n;
    } else {
      aux->next->prev = n;
      n->next = aux->next;
      n->prev = aux;
      aux->next = n;
    }
    list->size++;
    return n;
}

//verificar essas funçoes!!

Posic getFirstLst(Lista l){
    List *list = (List*) l;
    return list->head;
}

Posic getNextLst(Lista l, Posic p){
    Node *n = (Node*) p;
    return n->next;
}

Posic getLastLst(Lista l){
    List *list = (List*) l;
    return list->tail;
}

Posic getPrevLst(Lista l, Posic p){
    Node *n = (Node*) p;
    return n->prev;
}

void killLst(Lista l){
    List *list = (List*) l;
    Node *n = list->head;
    while (n != NULL)
    {
      Node *aux = n;
      n = n->next;
      free(aux);
    }
    free(list);
}
