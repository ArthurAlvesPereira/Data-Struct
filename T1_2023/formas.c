#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <boolean.h>
#include "lista.h"
#include "formas.h"

typedef struct forma{
    char type;
    int id;
    double x;
    double y;
    double r;
    double w;
    double h;
    double x2;
    double y2;
    char text[200];
    char anchor[7];
    char corb[100];
    char corp[100];
    char cor[100];
    char family[100];
    char weight[100];
    int size;
    bool txtstl;
}

Form CreateCircle(int id, double x, double y, double r, char corb[100], char corp[100]){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    f->type = 'c';
    f->id = id;
    f->x = x;
    f->y = y;
    f->r = r;
    strcpy(f->corb, corb);
    strcpy(f->corp, corp);
    return f;
}

Form CreateRect(int id, double x, double y, double w, double h, char corb[100], char corp[100]){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    f->type = 'r';
    f->id = id;
    f->x = x;
    f->y = y;
    f->w = w;
    f->h = h;
    strcpy(f->corb, corb);
    strcpy(f->corp, corp);
    return f;
}

Form CreateLine(int id, double x, double y, double x2, double y2, char cor[100]){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    f->type = 'l';
    f->id = id;
    f->x = x;
    f->y = y;
    f->x2 = x2;
    f->y2 = y2;
    strcpy(f->cor, cor);
    return f;
}

Form CreateText(int id, double x, double y, char corb[100], char corp[100], char* anchor, char* text){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    f->type = 't';
    f->id = id;
    f->x = x;
    f->y = y;
    strcpy(f->corb, corb);
    strcpy(f->corp, corp);
    strcpy(f->anchor, anchor);
    strcpy(f->text, text);
    return f;

Form TextStyle(Form f, char family[100], char weight[100], int size){
    Forma *forma = (Forma*) f;
    strcpy(forma->family, family);
    strcpy(forma->weight, weight);
    forma->size = size;
    forma->txtstl = true;
    return forma;
}
