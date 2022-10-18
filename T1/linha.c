#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "geo.h"
#include "linha.h"

typedef struct linha{
  char tipo;
  int id;
  double x1;
  double y1;
  double x2;
  double y2;
  char cor[100];
} Linha;

Line CreateLine(char* tipe, int id, double x, double y, double x2, double y2, char cor[100]){
  Linha *l = (Linha*) malloc(sizeof(Linha));
  l -> tipo = tipe[0];
  l->id = id;
  l->x1 = x;
  l->y1 = y;
  l->x2 = x2;
  l->y2 = y2;
  strcpy(l->cor, cor);
  return l;
}