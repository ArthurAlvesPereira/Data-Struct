#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "lista.h"
#include "path.h"

//typedef void* path;

int main(int argc, char **argv)
{

    Lista l = createLst(-1);

    path p = readParamter(argc, argv);

    if (p == NULL)
    {
        printf("Erro ao ler os parametros\n");
        return 1;
    }

    geo_read(p, l);

    qry_read(p, l);

    killLst(l);
    // KillPath(p);

    return 0;

}