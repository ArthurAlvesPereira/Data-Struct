#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"
#include "path.h"
#include "system.h"
#include "formas.h"
// #include "qry.h"
// #include "svg.h"

typedef struct Path
{
	char *fullpath;
	char *path;
	char *name;
	char *normpath;
	char *extension;
	char *BED;
	char *BSD;
	char *GenGeo;
	char *GeoSVG;
	char *PathQry;
	char *GenTxt;
	char *QrySVG;
	char *nameQry;
	char *QRY;
	char *GEO;
	char *SVG;
	char *TXT;
	
} Paths;

void KillPath(void *p)
{
	Paths *path = (Paths *)p;
	free(path->fullpath);
	free(path->path);
	free(path->name);
	free(path->normpath);
	free(path->extension);
	free(path->BED);
	free(path->BSD);
	free(path->GenGeo);
	free(path->PathQry);
	free(path->GeoSVG);
	free(path->QRY);
	free(path->GEO);
	free(path->SVG);
	free(path->TXT);
	free(path->GenTxt);
	free(path->QrySVG);
	free(path->nameQry);
	free(path);
}

path readParamter(int argc, char **argv)
{
	Paths *p = calloc(1, sizeof(Paths));
	char *aux;
	for (int i = 0; i < argc; i++)
	{
		if (!strcmp(argv[i], "-e"))
		{
			i++;
			p->BED = calloc(strlen(argv[i]) + 1, sizeof(char));
			strcpy(p->BED, argv[i]);
		}
		else if (!strcmp(argv[i], "-f"))
		{
			i++;
			p->GEO = calloc(strlen(argv[i]) + 1, sizeof(char));
			strcpy(p->GEO, argv[i]);
		}
		else if (!strcmp(argv[i], "-o"))
		{
			i++;
			p->BSD = calloc(strlen(argv[i]) + 1, sizeof(char));
			strcpy(p->BSD, argv[i]);
		}
		else if (!strcmp(argv[i], "-q"))
		{
			i++;
			p->QRY = calloc(strlen(argv[i]) + 1, sizeof(char));
			strcpy(p->QRY, argv[i]);
		}
	}
	p->path = calloc(strlen(p->BED) + 2, sizeof(char));
	normalizePath(p->BED, p->path, 50);
	p->fullpath = calloc(strlen(p->path) + strlen(p->GEO) + 2, sizeof(char));
	joinFilePath(p->path, p->GEO, p->fullpath, strlen(p->path) + strlen(p->GEO) + 5);
	p->name = calloc(strlen(p->GEO) + 1, sizeof(char));
	p->extension = calloc(4, sizeof(char));
	splitPath(p->fullpath, p->path, strlen(p->fullpath), p->name, strlen(p->name), p->extension, strlen(p->extension));
	p->GeoSVG = calloc(strlen(p->fullpath) + 5, sizeof(char));
	p->SVG = calloc(5, sizeof(char));
	p->TXT = calloc(5, sizeof(char));
	p->PathQry = calloc(strlen(p->fullpath) + strlen(p->QRY), sizeof(char));
	p->GenTxt = calloc(strlen(p->fullpath) + 5, sizeof(char));
	p->QrySVG = calloc(strlen(p->fullpath) + 8, sizeof(char));
	p->nameQry = calloc(strlen(p->QRY) + 6, sizeof(char));
	strcpy(p->nameQry, p->name);
	strcat(p->nameQry, "-arqcons");
	strcpy(p->TXT, ".txt");
	strcpy(p->SVG, ".svg");
	printf("%s\n", p->QRY);
	//getPath(p->QRY, p->, strlen(p->fullpath) + 5);
	joinAll(p->BSD, p->name, p->SVG, p->GeoSVG, strlen(p->path) + strlen(p->name) + 4);
	joinFilePath(p->path, p->QRY, p->PathQry, strlen(p->path) + strlen(p->QRY) + strlen(p->PathQry));
	joinAll(p->BSD, p->name, p->TXT, p->GenTxt, strlen(p->path) + strlen(p->name) + 4);
	joinAll(p->BSD, p->nameQry, p->SVG, p->QrySVG, strlen(p->path) + strlen(p->nameQry) + 4);
	joinAll(p->BSD, p->name, p->TXT, p->GenTxt, strlen(p->path) + strlen(p->name) + 4);


	return p;
}

void geo_read(path pPath, Lista l)
{
	int id;
	double x, x2, y, y2, w, h, r, fSize;
	char corb[100], corp[100], cor[100], a[10], tipo[2], texto[100];
	char fFamily[100], fWeight[100];
	bool txtstl = false;
	//char caminho[100];

	Paths *p = pPath;
	//strcpy(caminho, p->fullpath);
	printf("%s\n", p->fullpath);
	printf("%s\n", p->GeoSVG);

	FILE *arq = fopen(p->GeoSVG, "w");

	FILE *fp = fopen(p->fullpath, "r");
	fprintf(arq, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
	while (!feof(fp))
	{

		fscanf(fp, "%s", tipo);
		if (!strcmp(tipo, "c"))
		{
			fscanf(fp, "%d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp);
			Form circle = CreateCircle(id, x, y, r, corb, corp);
			insertLst(l, circle);
			fprintf(arq, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", x, y, r, corp, corb);
		}

		if (!strcmp(tipo, "r"))
		{
			fscanf(fp, "%d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp);
			Form rectangle = CreateRect(id, x, y, w, h, corb, corp);
			insertLst(l, rectangle);
			fprintf(arq, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", x, y, w, h, corp, corb);
		}

		if (!strcmp(tipo, "l"))
		{
			fscanf(fp, "%d %lf %lf %lf %lf %s", &id, &x, &y, &x2, &y2, cor);
			Form line = CreateLine(id, x, y, x2, y2, cor);
			insertLst(l, line);
			fprintf(arq, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:%s;stroke-width:1\"/>\n", x, y, x2, y2, cor);
		}

		if (!strcmp(tipo, "t"))
		{
			if (txtstl == true){ //É inserido na lista o txtstl?
				fscanf(fp, "%d %lf %lf %s %s %s %s", &id, &x, &y, corb, corp, a, texto);
				Form text = CreateText(id, x, y, corb, corp, a, texto);
				insertLst(l, text);
				fprintf(arq, "<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"%f\" font-family=\"%s\" font-weight=\"%s\" text-anchor=\"%s\">%s</text>\n", x, y, corp, corb, fSize, fFamily, fWeight, a, texto);
			} else {
				fscanf(fp, "%d %lf %lf %s %s %s %s", &id, &x, &y, corb, corp, a, texto);
				Form text = CreateText(id, x, y, corb, corp, a, texto);
				insertLst(l, text);
				fprintf(arq, "<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"20\" text-anchor=\"%s\">%s</text>\n", x, y, corp, corb, a, texto);}
			
		}

		if (!strcmp(tipo, "ts"))
		{
			bool txtstl = true;
			fscanf(fp, "%s %s %lf", fFamily, fWeight, &fSize);
		}
	}
	fprintf(arq, "</svg>");
	fclose(fp);
	fclose(arq);
}

// void qry_read(path pPath, Lista l){
// 	char linha[100];
// 	char comando[3];
// 	double v, x, y, dx, dy, r;
// 	int id, j, k;

// 	Paths *p = pPath;

// 	// printf("QRY: %s", p->PathQry);

// 	FILE *read = fopen(p->PathQry, "r");

// 	printf("\n\nQrySVG: %s\n\n", p->QrySVG);
// 	FILE *writesvg = fopen(p->QrySVG, "w");
// 	FILE *writetxt = fopen(p->GenTxt, "w");
// 	fprintf(writesvg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
// 	PrintSVG(l, writesvg);
// 	while (!feof(read))
// 	{
// 		fscanf(read, "%s", comando);
// 		if (!strcmp(comando, "na"))
// 		{
// 			printf("na");
// 			//v = na(read, writetxt);
// 			fprintf(writetxt, "na: %lf", v);
// 		}
// 		else if (!strcmp(comando, "tp"))
// 		{	
// 			fscanf(read, "%lf %lf", &x, &y);
// 			tp(writesvg, writetxt, l, x, y);
// 		}
// 		else if (!strcmp(comando, "tr"))
// 		{
// 			fscanf(read, "%lf %lf %lf %lf %d", &x, &y, &dx, &dy, &id);
// 			fprintf(writetxt, "tr: %lf %lf %lf %lf %d\n", x, y, dx, dy, id);
// 			tr(l, x, y, dx, dy, id, writesvg, writetxt);
// 		}
// 		else if (!strcmp(comando, "be"))
// 		{
// 			//printf("be");
// 			//be(read, writetxt);
// 			fscanf(read, "%lf %lf %lf", &x, &y, &r);
// 			fprintf(writetxt, "be: %lf %lf %lf\n", x, y, r);
// 		}
// 		else if (!strcmp(comando, "se"))
// 		{
// 			//printf("se");
// 			//se(read, writetxt);
// 			fscanf(read, "%d", &id);
// 			fprintf(writetxt, "se: %d\n", id);
// 		}
// 		else if (!strcmp(comando, "sec"))
// 		{
// 			//printf("sec");
// 			//sec(read, writetxt);
// 			fscanf(read, "%d %d", &id, &j);
// 			fprintf(writetxt, "sec: %d %d\n", id, j);
// 		}
// 		else if (!strcmp(comando, "mvh"))
// 		{
// 			//printf("mvh");
// 			//mvh(read, writetxt);
// 			fscanf(read, "%d %d %lf", &j, &k, &dx);
// 			fprintf(writetxt, "mvh: %d %d %lf\n", j, k, dx);
// 		}
// 		else if (!strcmp(comando, "mvv"))
// 		{
// 			//printf("mvv");
// 			//mvv(read, writetxt);
// 			fscanf(read, "%d %d %lf", &j, &k, &dy);
// 			fprintf(writetxt, "mvv: %d %d %lf\n", j, k, dy);
// 		}
// 	}
// 	// PrintSVG(l, writesvg);
// 	fprintf(writesvg, "</svg>");
// 	fclose(read);
// 	fclose(writesvg);
// 	fclose(writetxt);
// }
