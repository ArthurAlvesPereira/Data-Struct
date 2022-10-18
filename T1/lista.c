#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "geo.h"
#include "formas.h"

typedef struct node {
    Item info;
    struct node *next;
} Node;

typedef struct list {
    int size, max;
    Node *head;
    Node *tail;
} List;

Lista createLista(int capacidade){
    List *l = calloc(1, sizeof(List));
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
    if (capacidade < 0)
    {
      l->max = CAPAC_ILIMITADA;
    } else {
      l->max = capacidade;
    }
    return l;
}

int lengthLista(Lista l){
    List *list = (List*) l;
    return list->size;
}

int maxLength(Lista l){
    List *list = (List*) l;
    return list->max;
}

bool isEmpty(Lista l){
    List *list = (List*) l;
    return list->size == 0;
}

bool isFull(Lista l){
    return false;
}

Posic insert(Lista l, Item i){
    List *list = (List*) l;
    Node *n = calloc(1, sizeof(Node));
    n->info = i;
    n->next = NULL;
    if (list->size == 0)
    {
      list->head = n;
      list->tail = n;
    } else {
      list->tail->next = n;
      list->tail = n;
    }
    list->size++;
    return n;
}

Item pop(Lista l){
    List *list = (List*) l;
    Node *n = list->head;
    Item i = n->info;
    list->head = n->next;
    free(n);
    list->size--;
    return i;
}

void remover(Lista l, Posic p){
    List *list = (List*) l;
    Node *n = (Node*) p;
    Node *aux = list->head;
    if (aux == n)
    {
      list->head = n->next;
      free(n);
      list->size--;
      return;
    }
    while (aux->next != n)
    {
      aux = aux->next;
    }
    aux->next = n->next;
    free(n);
    list->size--;
}

Item get(Lista l, Posic p){
    Node *n = (Node*) p;
    return n->info;
}

Posic insertBefore(Lista l, Posic p, Item i){
    List *list = (List*) l;
    Node *n = calloc(1, sizeof(Node));
    n->info = i;
    Node *aux = list->head;
    if (aux == p)
    {
      n->next = aux;
      list->head = n;
      list->size++;
      return n;
    }
    while (aux->next != p)
    {
      aux = aux->next;
    }
    n->next = aux->next;
    aux->next = n;
    list->size++;
    return n;
}

Posic insertAfter(Lista l, Posic p, Item i){
    List *list = (List*) l;
    Node *n = calloc(1, sizeof(Node));
    n->info = i;
    Node *aux = list->head;
    while (aux != p)
    {
      aux = aux->next;
    }
    n->next = aux->next;
    aux->next = n;
    list->size++;
    return n;
}

Posic getFirst(Lista l){
    List *list = (List*) l;
    return list->head;
}

Posic getNext(Lista l, Posic p){
    Node *n = (Node*) p;
    return n->next;
}

Posic getLast(Lista l){
    List *list = (List*) l;
    return list->tail;
}

Posic getPrevious(Lista l, Posic p){
    List *list = (List*) l;
    Node *n = list->head;
    if (n == p)
    {
      return NULL;
    }
    while (n->next != p)
    {
      n = n->next;
    }
    return n;
}

void killLista(Lista l){
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