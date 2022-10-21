#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "geo.h"
#include "svg.h"
#include "formas.h"

int main(int argc, char **argv){

  int capacidade = -1;
  Lista l = createLista(capacidade);

  int i = 0;
  printf("%d\n", argc);

  if (strcmp(argv[1], "-e") == 0){
    //ler path no argv[2]
    printf("path: %s\n", argv[2]);
    //ler .geo no argv[4]
    printf("arquivo: %s\n", argv[4]);
    geo_init(argv[4], l);
    //ler diretorio de saida no argv[6]
    printf("diretorio de saida: %s\n", argv[6]);
    if (argc > 7)
    {
      //ler .qry no argv[8]
      printf("arquivo qry: %s", argv[8]);
    }
  } else {
    //ler .geo no argv[2]
    printf("arquivo: %s\n", argv[2]);
    geo_init(argv[2], l);
    //ler diretorio de saida no argv[4]
    printf("diretorio de saida: %s\n", argv[4]);
    if (argc > 5)
    {
      //ler .qry no argv[6]
      printf("arquivo qry: %s", argv[6]);
    }
  }
  printf("AAAAA\n");
  printf("tamanho da lista: %d\n", length(l));

  //PrintList(l);

  PrintSVG(l);
  printf("T\n");
  killLista(l);


  return 0;
}