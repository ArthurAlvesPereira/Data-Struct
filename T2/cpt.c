#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cpt.h"


typedef struct node {
    Info info;
    double x, y;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree {
    int size;
    Node *root;
    int epsilon;
} Tree;

CPTree createCPT(double epsilon){
    Tree *t = malloc(sizeof(Tree));
    t->size = 0;
    t->root = NULL;
    t->epsilon = epsilon;
    return t;
}

// void *VisitaNo (double x, double y, Info info, double xc, double yc, double r, void *extra){

// }


bool insertCPT(CPTree b, double x, double y, Info info,VisitaNo vfindo, VisitaNo vfvoltando, void *extra){
    Tree *t = b;
    Node *n = malloc(sizeof(Node));
    if (t->root == NULL){
        n->x = x;
        n->y = y;
        n->info = info;
        n->left = NULL;
        n->right = NULL;
        t->root = n;
        t->size++;
        return true;
    } else {
        if 
    }

    
    
}
