#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "geo.h"
#include "svg.h"

/*void* createSVG(Lista l){
  FILE *arq;
  arq = fopen("svg.svg", "w");
  fprintf(arq, "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
  return arq;
}*/

void PrintSVG(Lista l){

  FILE *arq;
  arq = fopen("svg.svg", "w");
  fprintf(arq, "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
  int id;
  double x, x2, y, y2, w, h, r;
  char corb[100], corp[100],cor[100], a[1], tipo[100];
  
  for (int i = 0; i < getTamanho(l); i++){
    get(l, i, &id, &x, &y, &w, &h, &r, &corb, &corp, &cor, &a, &tipo);
    if (strcmp(tipo, "c") == 0){
      fprintf(arq, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />\n", x, y, r, corb, corp);
    } else if (strcmp(tipo, "r") == 0){
      fprintf(arq, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" style=\"fill:%s;stroke:%s;stroke-width:1\" />\n", x, y, w, h, corp, corb);
    } else if (strcmp(tipo, "t") == 0){
      fprintf(arq, "<text x=\"%lf\" y=\"%lf\" fill=\"%s\">%s</text>\n", x, y, cor, a);
    } else if (strcmp(tipo, "l") == 0){
      fprintf(arq, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:%s;stroke-width:1\" />\n", x, y, x2, y2, cor);
    }
  }
  fprintf(arq, "</svg>");
  fclose(arq);
}