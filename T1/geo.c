#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "geo.h"
//#include "formas.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

void geo_read(void* fp, Lista l){
  char str[200];
  char info[8][50];
  while (!feof(fp)){
    fgets(str, 200, fp);
    if (str[0] == 'c')
    {
      sscanf(str, "%s %s %s %s %s %s %s %s", info[0], info[1], info[2], info[3], info[4], info[5], info[6], info[7]);
      Circle circle = CreateCircle(info[0], atoi(info[1]), atof(info[2]), atof(info[3]), atof(info[4]), info[5], info[6]);
      insert(l, circle);
    }

    if (str[0] == 'r')
    {
      sscanf(str, "%s %s %s %s %s %s %s %s", info[0], info[1], info[2], info[3], info[4], info[5], info[6], info[7]);
      Rectangle rectangle = CreateRectangle(info[0], atoi(info[1]), atof(info[2]), atof(info[3]), atof(info[4]), atof(info[5]), info[6], info[7]);
      insert(l, rectangle);
    }

    if (str[0] == 'l')
    {
      sscanf(str, "%s %s %s %s %s %s %s %s", info[0], info[1], info[2], info[3], info[4], info[5], info[6], info[7]);
      Line line = CreateLine(info[0], atoi(info[1]), atof(info[2]), atof(info[3]), atof(info[4]), atof(info[5]), info[6]);
      insert(l, line);
    }

    if (str[0] == 't')
    {
      sscanf(str, "%s %s %s %s %s %s %s %s %s", info[0], info[1], info[2], info[3], info[4], info[5], info[6], info[7], info[8]);
      Text text = CreateText(info[0], atoi(info[1]), atof(info[2]), atof(info[3]), info[4], info[5], info[6], info[7]);
      insert(l, text);
    }
    {
      /* code */
    }
    
    
    
  }
}

void geo_init(char *filename, Lista l){
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo %s", filename);
    exit(1);
  }

  geo_read(fp, l);
  //return fp;
  fclose(fp);
} // geo_init

