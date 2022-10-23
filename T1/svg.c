#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "geo.h"
#include "svg.h"
#include "formas.h"
#include "path.h"
#include "system.h"

/*void* createSVG(Lista l){
  FILE *arq;
  arq = fopen("svg.svg", "w");
  fprintf(arq, "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
  return arq;
}*/

// void PrintList(Lista l){
//   int id;
//   double x, x2, y, y2, w, h, r;
//   char corb[100], corp[100],cor[100], a[1], tipo, texto[100];

//   void* node;

//   for (node = getFirst(l); node; node = getNext(l, node)){
//     Form f = get(l, node);
//     tipo = GetType(f);
//     id = GetId(f);
//     printf("%c\n", tipo);
//     printf("%d\n", id);
//     x = GetX(f);
//     printf("%lf\n", x);
//     y = GetY(f);
//     r = GetR(f);
//     printf("%lf\n", y);
//     printf("%lf\n", r);
//     strcpy(corb, GetCorb(f));
//     printf("%s\n", corb);
//     //strcpy(a, GetAnchor(f));
//     /*
//     w = GetW(f);
//     h = GetH(f);
//     x2 = GetX2(f);
//     y2 = GetY2(f);
//     printf("%lf\n", x);
//     printf("%lf\n", y);
//     printf("%lf\n", r);
//     printf("%lf\n", w);
//     printf("%lf\n", h);
//     strcpy(corb, GetCorb(f));
//     strcpy(corp, GetCorp(f));
//     strcpy(cor, GetCor(f));
//     strcpy(a, GetAnchor(f));
//     strcpy(texto, GetText(f));*/

//     /*char* aux = calloc(10, sizeof(char));

//     if (strcmp(tipo, "c") == 0){
//       printf("Circulo: id = %d, x = %lf, y = %lf, r = %lf, corb = %s, corp = %s\n", id, x, y, r, corb, corp);
//     } else if (strcmp(tipo, "r") == 0){
//       printf("Retangulo: id = %d, x = %lf, y = %lf, w = %lf, h = %lf, corb = %s, corp = %s\n", id, x, y, w, h, corb, corp);
//     } else if (strcmp(tipo, "l") == 0){
//       printf("Linha: id = %d, x = %lf, y = %lf, x2 = %lf, y2 = %lf, cor = %s\n", id, x, y, x2, y2, cor);
//     } else if (strcmp(tipo, "t") == 0){
//       char* aux = calloc(10, sizeof(char));
//       if (a[0] == 'i'){
//         strcpy(aux, "start");
//       } else if (a[0] == 'm'){
//         strcpy(aux, "middle");
//       } else if (a[0] == 'f'){
//         strcpy(aux, "end");
//       }
      

//       printf("Texto: id = %d, x = %lf, y = %lf, text = %s, anchor = %s, corb = %s, corp = %s\n", id, x, y, texto, aux, corb, corp);
//       free(aux);
//     }*/
//   }
// }
  

// void PrintSVG(Lista l, path p){

//   Paths* paths = p;

//   char *nome = paths->nome;

//   FILE *arq;
//   strcat(nome, ".svg");
//   arq = fopen(nome, "w");
//   fprintf(arq, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");
//   int id;
//   double x, x2, y, y2, w, h, r;
//   char corb[100], corp[100],cor[100], a[10], tipo, texto[100];

//   void* node;

  
//   for (node = getFirst(l); node; node = getNext(l, node)){
//     Form f = get(l, node);
//     tipo = GetType(f);
//     if (tipo == 'c'){
//       id = GetId(f);
//       x = GetX(f);
//       y = GetY(f);
//       r = GetR(f);
//       strcpy(corb, GetCorb(f));
//       strcpy(corp, GetCorp(f));
//       fprintf(arq, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n", x, y, r, corb, corp);
//     }
//     else if (tipo == 'r'){
//       id = GetId(f);
//       x = GetX(f);
//       y = GetY(f);
//       w = GetW(f);
//       h = GetH(f);
//       strcpy(corb, GetCorb(f));
//       strcpy(corp, GetCorp(f));
//       fprintf(arq, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n", x, y, w, h, corb, corp);
//     }
//     else if (tipo == 'l'){
//       id = GetId(f);
//       x = GetX(f);
//       y = GetY(f);
//       x2 = GetX2(f);
//       y2 = GetY2(f);
//       strcpy(cor, GetCor(f));
//       fprintf(arq, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:%s;stroke-width:2\"/>\n", x, y, x2, y2, cor);
//     }
//     else if (tipo == 't'){
//       id = GetId(f);
//       x = GetX(f);
//       y = GetY(f);
//       strcpy(a, GetAnchor(f));
//       strcpy(corb, GetCorb(f));
//       strcpy(corp, GetCorp(f));
//       strcpy(texto, GetText(get(l, node)));
//       printf("%s\n", texto);
//       fprintf(arq, "<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>\n", x, y, corp, corb, a, texto);
//     }
    
//   }
//   fprintf(arq, "</svg>");
//   fclose(arq);
// }
