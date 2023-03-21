#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "path.h"

typedef void* path;

int main(int argc, char **argv)
{
    
    Lista l = createLst(-1);

    path p = readParamter(argc, argv);

    killLst(l);
    //KillPath(p);

    return 0;

}