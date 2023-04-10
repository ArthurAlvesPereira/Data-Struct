#ifndef FORMAS_H
#define FORMAS_H

typedef void* Form;

Form CreateCircle(int id, double x, double y, double r, char corb[100], char corp[100]);
Form CreateRect(int id, double x, double y, double w, double h, char corb[100], char corp[100]);
Form CreateLine(int id, double x, double y, double x2, double y2, char cor[100]);
Form CreateText(int id, double x, double y, char* text, char* anchor, char corb[100], char corp[100]);

char GetType(void* l);
int GetTypeInt(void* l);
int GetId(void* l);
double GetX(void* l);
double GetY(void* l);
double GetR(void* l);
double GetW(void* l);
double GetH(void* l);
double GetX2(void* l);
double GetY2(void* l);
char* GetText(void* l);
char* GetAnchor(void* l);
char* GetCorb(void* l);
char* GetCorp(void* l);
char* GetCor(void* l);
int GetShots(void* l);
int GetProtec(void* l);
double GetLength(double x1, double y1, double x2, double y2);

void SetShots(void* l, int tiros);





#endif