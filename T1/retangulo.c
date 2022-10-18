#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "retangulo.h"

typedef struct retangulo{
  char tipo;
  int id;
  double x;
  double y;
  double w;
  double h;
  char corb[100];
  char corp[100];
} Retangulo;

Rectangle CreateRectangle(char* tipe, int id, double x, double y, double w, double h, char corb[100], char corp[100]){
  Retangulo *r = (Retangulo*) malloc(sizeof(Retangulo));
  r -> tipo = tipe[0];
  r->id = id;
  r->x = x;
  r->y = y;
  r->w = w;
  r->h = h;
  strcpy(r->corb, corb);
  strcpy(r->corp, corp);
  return r;
}