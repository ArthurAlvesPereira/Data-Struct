#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


typedef struct qry{
    char linha[100];
    char comando[3];
    double v, x, y, dx, dy, r;
    int id, j, k;
}Qry;

void scanqry(){
    char linha[100];
    char comando[3];

    FILE *fp;
    fp = fopen("qry.txt", "r");
    if (fp == NULL){
        exit(1);
    }else{
    while (!feof(fp)){
        fgets(linha, 200, fp);
        sscanf(linha, "%s", comando);
        if (strcmp(comando, "na")){
            
        }
    }
    
}