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
    int protec;
    int tiros;
    int pd;
}Forma;

Form CreateCircle(int id, double x, double y, double r, char corb[100], char corp[100]){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    f->type = 'c';
    f->id = id;
    f->x = x;
    f->y = y;
    f->r = r;
    f->protec = 60;
    f->tiros = 2;
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
    f->protec = 60;
    f->tiros = 0;
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
    f->protec = 50;
    f->tiros = 1;
    strcpy(f->corb, cor);

    return f;
}

Form CreateText(int id, double x, double y, char corb[100], char corp[100], char* anchor, char* text){
    Forma *f = (Forma*) calloc(1, sizeof(Forma));
    f->type = 't';
    f->id = id;
    f->x = x;
    f->y = y;
    f->protec = 5;
    f->tiros = 1;
    if (anchor[0] == 'i'){
        strcpy(f->anchor, "start");
    } else if (anchor[0] == 'm'){
        strcpy(f->anchor, "middle");
    } else if (anchor[0] == 'f'){
        strcpy(f->anchor, "end");
    }
    strcpy(f->corb, corb);
    strcpy(f->corp, corp);
    strcpy(f->text, text);
    return f;
}


// Gets

char GetType(void* l){
    Forma *f = (Forma*) l;
    return f->type;
}

int GetTypeInt(void* l){
    Forma *f = (Forma*) l;
    if (f->type == 'c'){
        return 1;
    } else if (f->type == 'r'){
        return 2;
    } else if (f->type == 'l'){
        return 3;
    } else if (f->type == 't'){
        return 4;
    }
    return 0;
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
    return f->corb;
}

int GetProtec(void* l){
    Forma *f = (Forma*) l;
    return f->protec;
}

int GetShots(void* l){
    Forma *f = (Forma*) l;
    return f->tiros;
}

double GetLength(double x1, double y1, double x2, double y2)
{
    if (x1 == x2) //Vertical line
    {
        return fabs(y2 - y1);
    }
    else if (y1 == y2) //Horizontal line
    {
        return fabs(x2 - x1);
    }
    else //Diagonal line
    {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
}

//sets

void SetId(void* l, int id){
    Forma *f = (Forma*) l;
    f->id = id;
}

void SetShots(void* l, int tiros){
    Forma *f = (Forma*) l;
    f->tiros = tiros;
}