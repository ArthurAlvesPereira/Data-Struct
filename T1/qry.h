#include <stdio.h>
#include <math.h>

#ifndef QRY_H
#define QRY_H

int insideCirc(void* currentnode, double x, double y);
int insideRect(void* currentnode, double x, double y);
int insideLine(void* currentnode, double x, double y);
int insideText(void* currentnode, double x, double y);




double na(FILE* qry,FILE* txt, double v);
int tpcounter(void* l, int count, double x, double y, FILE* svg, FILE* txt);
void tp(FILE* svg, FILE* txt, void* l, double x, double y);
void tr(void* l, double x, double y, double x2, double y2,int id,FILE* svg, FILE* txt);
int trcounter(void* l, double x, double y, double x2, double y2,int id, FILE* svg, FILE* txt);
void be(FILE* qry, FILE* txt);
void se(FILE* qry, FILE* txt);
void sec(FILE* qry, FILE* txt);
void mvh(FILE* qry, FILE* txt);
void mvv(FILE* qry, FILE* txt);

#endif