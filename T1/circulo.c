#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "geo.h"
#include "circulo.h"

typedef struct circulo{
  char tipo;
  int id;
  double x;
  double y;
  double r;
  char corb[100];
  char corp[100];
} Circulo;

Circle CreateCircle(char* type, int id, double x, double y, double r, char corb[100], char corp[100]){
  Circulo *c = (Circulo*) malloc(sizeof(Circulo));
  c -> tipo = type[0];
  c->id = id;
  c->x = x;
  c->y = y;
  c->r = r;
  strcpy(c->corb, corb);
  strcpy(c->corp, corp);
  return c;
}