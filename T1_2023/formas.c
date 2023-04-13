#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
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
} Forma;

//mudar char, pois é uma string

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
}

Form TextStyle(char family[100], char weight[100], int size){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    strcpy(f->family, family);
    strcpy(f->weight, weight);
    f->size = size;
    f->txtstl = true;
    return f;
}

// Funções para obter informações de uma forma


char GetType(void* l){
    Forma *f = (Forma*) l;
    return f->type;
}

int GetTypeInt(void* l){
    Forma *f = (Forma*) l;
    if(f->type == 'c'){
        return 1;
    }
    else if(f->type == 'r'){
        return 2;
    }
    else if(f->type == 'l'){
        return 3;
    }
    else if(f->type == 't'){
        return 4;
    }
    else{
        return 0;
    }
}

int GetId(void* l){
    Forma *f = (Forma*) l;
    return f->id;
}

double GetX(void* l){
    Forma *f = (Forma*) l;
    return f->x;
}

double GetY(void* l){
    Forma *f = (Forma*) l;
    return f->y;
}

double GetR(void* l){
    Forma *f = (Forma*) l;
    return f->r;
}

double GetW(void* l){
    Forma *f = (Forma*) l;
    return f->w;
}

double GetH(void* l){
    Forma *f = (Forma*) l;
    return f->h;
}

double GetX2(void* l){
    Forma *f = (Forma*) l;
    return f->x2;
}

double GetY2(void* l){
    Forma *f = (Forma*) l;
    return f->y2;
}

char* GetText(void* l){
    Forma *f = (Forma*) l;
    return f->text;
}

char* GetAnchor(void* l){
    Forma *f = (Forma*) l;
    return f->anchor;
}

char* GetCorb(void* l){
    Forma *f = (Forma*) l;
    return f->corb;
}

char* GetCorp(void* l){
    Forma *f = (Forma*) l;
    return f->corp;
}

char* GetCor(void* l){
    Forma *f = (Forma*) l;
    return f->cor;
}

double GetLenght(double x1, double y1, double x2, double y2){
    double lenght = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return lenght;
}

//Sets

double SetX(void* l, double dx){
    double x;
    Forma *f = (Forma*) l;
    f->x = x + dx;
    return f->x;
}

double SetY(void* l, double dy){
    double y;
    Forma *f = (Forma*) l;
    f->y = y + dy;
    return f->y;
}

