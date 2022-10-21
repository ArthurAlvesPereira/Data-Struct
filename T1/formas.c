#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
}Forma;

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
    strcpy(f->corb, cor);

    return f;
}

Form CreateText(int id, double x, double y, char corb[100], char corp[100], char* anchor, char* text){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    f->type = 't';
    f->id = id;
    f->x = x;
    f->y = y;
    if (anchor[0] == 's'){
        strcpy(f->anchor, "start");
    } else if (anchor[0] == 'm'){
        strcpy(f->anchor, "middle");
    } else if (anchor[0] == 'e'){
        strcpy(f->anchor, "end");
    }
    printf("aqui: %s\n", f->text);
    
    strcpy(f->corb, corb);
    strcpy(f->corp, corp);
    strcpy(f->text, text);
    return f;
}

// Gets

char GetType(void* l){
    Forma *f = (Forma*) l;
    return f->type;
    //printf("%c", f->&type);
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
    printf("aqui2: %s\n", f->text);
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
    return f->corb;
}