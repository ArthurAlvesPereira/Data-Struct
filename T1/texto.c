#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "geo.h"
#include "texto.h"

typedef struct texto{
  char tipo;
  int id;
  double x;
  double y;
  char corb[100];
  char corp[100];
  char a;
  char texto[100];
} Texto;

Text CreateText(char* type, int id, double x, double y, char corb[100], char corp[100], char* a, char text[100]){
  Texto *t = (Texto*) malloc(sizeof(Texto));
  t -> tipo = type[0];
  t->id = id;
  t->x = x;
  t->y = y;
  strcpy(t->corb, corb);
  strcpy(t->corp, corp);
  t->a = a[0];
  strcpy(t->texto, text);
  return t;
}