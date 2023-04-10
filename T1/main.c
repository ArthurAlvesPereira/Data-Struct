#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"
//#include "geo.h"
#include "svg.h"
#include "formas.h"
#include "path.h"
#include "system.h"
#include "qry.h"

int main(int argc, char **argv)
{
	
	Lista l = createLista(-1);

	path p = readParamter(argc, argv);


	geo_read(p, l);
	//PrintSVG(l, p);
	qry_read(p, l);
	printf("T\n");
	KillPath(p);
	killLista(l);

	//free(paths);
	return 0;
}