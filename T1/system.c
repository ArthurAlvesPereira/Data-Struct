#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "path.h"
#include "system.h"
#include "formas.h"

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
	char *GenQry;
	char *GenSvg;
	char *QRY;
	char *GEO;
	char *SVG;
} Paths;

void KillPath(void* p)
{
	Paths *path = (Paths*)p;
	free(path->fullpath);
	free(path->path);
	free(path->name);
	free(path->normpath);
	free(path->extension);
	free(path->BED);
	free(path->BSD);
	free(path->GenGeo);
	free(path->GenQry);
	free(path->GenSvg);
	free(path->QRY);
	free(path->GEO);
	free(path->SVG);
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
		joinFilePath(p->path, p->GEO, p->fullpath, strlen(p->path) + strlen(p->GEO)+5);
		p->name = calloc(strlen(p->GEO) + 1, sizeof(char));
		p->extension = calloc(4, sizeof(char));
		splitPath(p->fullpath, p->path, strlen(p->fullpath), p->name, strlen(p->name), p->extension, strlen(p->extension));
		p->GenSvg = calloc(strlen(p->fullpath) + 5, sizeof(char));
		p->SVG = calloc(5, sizeof(char));
		strcpy(p->SVG, ".svg");
		joinAll(p->BSD, p->name, p->SVG, p->GenSvg, strlen(p->path) + strlen(p->name) + 4);

	return p;
}

void geo_read(path pPath, Lista l)
{
	int id;
	double x, x2, y, y2, w, h, r;
	char corb[100], corp[100], cor[100], a[10], tipo[2], texto[100];
	char caminho[100];
	
	Paths *p = pPath;
	strcpy(caminho, p->fullpath);


	FILE *arq = fopen(p->GenSvg, "w");
	
	FILE *fp = fopen(p->fullpath, "r");
	fprintf(arq, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
	while (!feof(fp))
	{
		fscanf(fp, "%s", tipo);
		if (!strcmp(tipo, "c"))
		{
			fscanf(fp, "%d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp);
			Form circle = CreateCircle(id, r, x, y, corb, corp);
			insert(l, circle);
			fprintf(arq, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", x, y, r, corp, corb); 
		}

		if (!strcmp(tipo, "r"))
		{
			fscanf(fp, "%d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp);
			Form rectangle = CreateRect(id, x, y, w, h, corb, corp);
			insert(l, rectangle);
			fprintf(arq, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", x, y, w, h, corp, corb);
		}

		if (!strcmp(tipo, "l"))
		{
			fscanf(fp, "%d %lf %lf %lf %lf %s", &id, &x, &y, &x2, &y2, cor);
			Form line = CreateLine(id, x, y, x2, y2, cor);
			insert(l, line);
			fprintf(arq, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:%s;stroke-width:1\"/>\n", x, y, x2, y2, cor);
		}

		if (!strcmp(tipo, "t"))
		{
			fscanf(fp, "%d %lf %lf %s %s %s %s", &id, &x, &y, corb, corp, a, texto);
			Form text = CreateText(id, x, y, corb, corp, a, texto);
			insert(l, text);
			fprintf(arq, "<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"20\" text-anchor=\"%s\">%s</text>\n", x, y, corp, corb, a, texto);
		}
	}
	fprintf(arq, "</svg>");
	fclose(fp);
	fclose(arq);
}
