#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"
#include "path.h"
#include "system.h"
#include "formas.h"
#include "qry.h"
// #include "svg.h"

typedef struct Path
{
	char *fullpath;
	char *path;
	char *name;
	char *nomeArq;
	char *normpath;
	char extension[5];
	char *BED;
	char *normpathBED;
	char *BSD;
	char *normpathBSD;
	char *GenGeo;
	char *GeoSVG;
	char *PathQry;
	char *GenTxt;
	char *QrySVG;
	char *nameQry;
	char *GenQry;
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
	free(path->normpathBED);
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

// path readParamter(int argc, char **argv)
// {
// 	printf("TESTE!!!!!\n");

// 	Paths *p = calloc(1, sizeof(Paths));
// 	char *aux;
// 	for (int i = 0; i < argc; i++)
// 	{
// 		if (!strcmp(argv[i], "-e"))
// 		{
// 			i++;
// 			p->BED = calloc(strlen(argv[i]) + 1, sizeof(char));
// 			strcpy(p->BED, argv[i]);
// 		}
// 		else if (!strcmp(argv[i], "-f"))
// 		{
// 			i++;
// 			p->GEO = calloc(strlen(argv[i]) + 1, sizeof(char));
// 			strcpy(p->GEO, argv[i]);
// 		}
// 		else if (!strcmp(argv[i], "-o"))
// 		{
// 			i++;
// 			p->BSD = calloc(strlen(argv[i]) + 1, sizeof(char));
// 			strcpy(p->BSD, argv[i]);
// 		}
// 		else if (!strcmp(argv[i], "-q"))
// 		{
// 			i++;
// 			p->QRY = calloc(strlen(argv[i]) + 1, sizeof(char));
// 			strcpy(p->QRY, argv[i]);
// 		}
// 	}
	
// 	p->path = calloc(strlen(p->BED) + 2, sizeof(char));
// 	normalizePath(p->BED, p->path, 50);
// 	p->fullpath = calloc(strlen(p->path) + strlen(p->GEO) + 2, sizeof(char));
// 	joinFilePath(p->path, p->GEO, p->fullpath, strlen(p->path) + strlen(p->GEO) + 5);
// 	p->name = calloc(strlen(p->GEO) + 1, sizeof(char));
// 	p->extension = calloc(4, sizeof(char));
// 	splitPath(p->fullpath, p->path, strlen(p->fullpath), p->name, strlen(p->name), p->extension, strlen(p->extension));
// 	p->GeoSVG = calloc(strlen(p->fullpath) + 5, sizeof(char));
	
// 	p->SVG = calloc(5, sizeof(char));
// 	p->TXT = calloc(5, sizeof(char));
// 	// p->PathQry = calloc(strlen(p->fullpath) + strlen(p->QRY), sizeof(char));
// 	// p->GenTxt = calloc(strlen(p->fullpath) + 5, sizeof(char));
// 	// p->QrySVG = calloc(strlen(p->fullpath) + 8, sizeof(char));
// 	// p->nameQry = calloc(strlen(p->QRY) + 6, sizeof(char));
// 	// strcpy(p->nameQry, p->name);
// 	// strcat(p->nameQry, "-arqcons");
// 	// strcpy(p->TXT, ".txt");
// 	strcpy(p->SVG, ".svg");
// 	// printf("%s\n", p->QRY);
// 	//getPath(p->QRY, p->, strlen(p->fullpath) + 5);
// 	joinAll(p->BSD, p->name, p->SVG, p->GeoSVG, strlen(p->path) + strlen(p->name) + 4);
// 	// joinFilePath(p->path, p->QRY, p->PathQry, strlen(p->path) + strlen(p->QRY) + strlen(p->PathQry));
// 	// joinAll(p->BSD, p->name, p->TXT, p->GenTxt, strlen(p->path) + strlen(p->name) + 4);
// 	// joinAll(p->BSD, p->nameQry, p->SVG, p->QrySVG, strlen(p->path) + strlen(p->nameQry) + 4);
// 	// joinAll(p->BSD, p->name, p->TXT, p->GenTxt, strlen(p->path) + strlen(p->name) + 4);


// 	return p;
// }

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
	// printf("%s\n", p->fullpath);
	printf("%s\n", p->GEO);

	printf("!!!!!!!!!!!AQUI!!!!!!!!1\n\n");

	printf("%s\n", p->GeoSVG);

	FILE *arq = fopen(p->GeoSVG, "w");

	FILE *fp = fopen(p->GenGeo, "r");

	if (fp == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}

	if (arq == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
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
				printf("%s %s %lf" , fFamily, fWeight, fSize);
				fprintf(arq, "<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"%f\" font-family=\"%s\" font-weight=\"%s\" text-anchor=\"%s\">%s</text>\n", x, y, corp, corb, fSize, fFamily, fWeight, a, texto);
			} else {
				fscanf(fp, "%d %lf %lf %s %s %s %s", &id, &x, &y, corb, corp, a, texto);
				Form text = CreateText(id, x, y, corb, corp, a, texto);
				insertLst(l, text);
				printf("\n\nCADE O ISTUAILO?\n\n");
				fprintf(arq, "<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"20\" text-anchor=\"%s\">%s</text>\n", x, y, corp, corb, a, texto);
		}
		}

		if (!strcmp(tipo, "ts"))
		{
			printf("ENTROU NO TS\n");
			txtstl = true;

			fscanf(fp, "%s %s %lf", fFamily, fWeight, &fSize);
		}
	}
	fprintf(arq, "</svg>");
	fclose(fp);
	fclose(arq);
}

void qry_read(path pPath, Lista l){
	char linha[100];
	char comando[3];
	char sufixo[100];
	char capac;
	double v, x, y, dx, dy, r, d, h, dist;
	int id, j, k, list;

	Paths *p = pPath;

	printf("QRY: %s\n\n", p->PathQry);

	printf("QrySVG: %s\n\n", p->QrySVG);

	FILE *read = fopen(p->PathQry, "r");

	if (read == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}

	printf("\n\nQrySVG: %s\n\n", p->QrySVG);
	FILE *writesvg = fopen(p->QrySVG, "w");
	FILE *writetxt = fopen(p->GenTxt, "w");
	fprintf(writesvg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
	// PrintSVG(l, writesvg);
	exit(1);
	while (!feof(read))
	{
		fscanf(read, "%s", comando);
		if (!strcmp(comando, "mv"))
		{
			fscanf(read, "%d %lf %lf", &id, &dx, &dy);
			mv(id, dx, dy, writetxt, writesvg, l);
		}

		if (!strcmp(comando, "g"))
		{
			fscanf(read, "%d %lf", &id, &v);
			// g(id, v, writetxt, writesvg, l);
			printf("funcao g nao implementada\n");
		}

		if (!strcmp(comando, "ff"))
		{
			fscanf(read, "%d %lf %lf %lf", &id, &r, &d, &h);
			// ff(id, r, d, h, writetxt, writesvg, l);
			printf("funcao ff nao implementada\n");
		}

		if (!strcmp(comando, "tf")){
			fscanf(read, "%d %d", &id, &list);
			printf("funcao tf nao implementada\n");
		}

		if (!strcmp(comando, "df")){
			fscanf(read, "%d %d %s", &id, &list, sufixo);
			printf("funcao df nao implementada\n");
		}

		if (!strcmp(comando, "d")){
			fscanf(read, "%d %c %lf %d %lf", &id, &capac, &dist, &j, &dx);
			// d(id, writetxt, writesvg, l);
			printf("funcao d nao implementada\n");
		}

		if (!strcmp(comando, "b?")){
			printf("funcao b? nao implementada\n");
		}

		if (!strcmp(comando, "c?")){
			printf("funcao c? nao implementada\n");
		}
		
	// PrintSVG(l, writesvg);
	fprintf(writesvg, "</svg>");
	fclose(read);
	fclose(writesvg);
	fclose(writetxt);
	}
}


path readParamter(int argc, char **argv){
	Paths *p = calloc(1, sizeof(Paths));
	char *aux;
	bool arg_e = false;
	bool arg_q = false;
	for (int i = 0; i < argc; i++)
	{
		if (!strcmp(argv[i], "-e"))
		{
			i++;
			p->BED = argv[i];
			// normalizePath(p->BED, p->normpathBED, strlen(p->BED));
			arg_e = true;

		} else if (!strcmp(argv[i], "-f")){
			i++;
			p->GEO = argv[i];


		} else if (!strcmp(argv[i], "-o")){
			i++;
			p->BSD = argv[i];
			p->normpathBSD = calloc(strlen(p->BSD) + 1, sizeof(char));
		} else if(!strcmp(argv[i], "-q")){
			i++;
			p->QRY = argv[i];
			arg_q = true;
		}
	}

	if (arg_e == false)
	{
		p->path = calloc(strlen(p->GEO) + 1, sizeof(char));
		p->nomeArq = calloc(strlen(p->GEO) + 1, sizeof(char));
		// p->extension = calloc(strlen(p->GEO) + 1, sizeof(char));
		splitPath(p->GEO, p->path, strlen(p->path), p->nomeArq, strlen(p->nomeArq), p->extension, strlen(p->extension));

		p->GenGeo = calloc(strlen(p->path) + strlen(p->nomeArq) + 5, sizeof(char));
		strcpy(p->GenGeo, p->GEO);
		if (arg_q == true)
		{
			
			printf("\n\n\nE AQUI TA LENDO???\n\n\n");

			// splitPath(p->QRY, p->path, strlen(p->path), p->nomeArq, strlen(p->nomeArq), p->extension, strlen(p->extension));

			// printf("path: %s\n", p->path);
			// printf("nomeArq: %s\n", p->nomeArq);
			// printf("extension: %s\n", p->extension);

			p->PathQry = calloc(strlen(p->QRY) + 1, sizeof(char));

			strcpy(p->PathQry, p->QRY);
		}
	} else {
		p->path = calloc(strlen(p->BED) * 2, sizeof(char));
		p->nomeArq = calloc(strlen(p->GEO) + 1, sizeof(char));
		p->normpathBED = calloc(strlen(p->BED) + 1, sizeof(char));
		normalizePath(p->BED, p->normpathBED, strlen(p->BED));

		printf("normpathBED: %s\n", p->normpathBED);

		p->fullpath = calloc(strlen(p->BED) + strlen(p->GEO) + 5, sizeof(char));
		joinFilePath(p->normpathBED, p->GEO, p->fullpath, strlen(p->normpathBED) + strlen(p->GEO) + 5);

		// printf("normpathBED: %s\n", p->normpathBED);
		// printf("GEO: %s\n", p->GEO);

		// printf("\n\n\nCADEO GEO???\n\n\n");
		// printf("fullpath: %s\n", p->fullpath);

		// printf("fullpath: %s\n", p->fullpath);
		// printf("fullpath address: %p\n", p->fullpath);
		// printf("fullpath size: %d\n", strlen(p->fullpath));

		// printf("path: %s\n", p->path);
		// printf("path address: %p\n", p->path);
		// printf("path size: %d\n", strlen(p->path));

		// printf("nomeArq: %s\n", p->nomeArq);
		// printf("nomeArq address: %p\n", p->nomeArq);
		// printf("nomeArq size: %d\n", strlen(p->nomeArq));

		// printf("extension: %s\n", p->extension);
		// printf("extension address: %p\n", p->extension);
		// printf("extension size: %d\n", strlen(p->extension));

		splitPath(p->fullpath, p->path, strlen(p->path), p->nomeArq, strlen(p->nomeArq), p->extension, strlen(p->extension));

		printf("\n\n\n COMEÇO DEBUG\n\n\n");
		printf("path: %s\n", p->path);
		printf("nomeArq: %s\n", p->nomeArq);
		printf("extension: %s\n", p->extension);


		printf("fullpath: %s\n", p->fullpath);
		p->GenGeo = calloc(strlen(p->fullpath) + 1, sizeof(char));
		strcpy(p->GenGeo, p->fullpath);

		if (arg_q == true)
		{
			printf("\n\n\nE AQUI TA LENDO???\n\n\n");

			// splitPath(p->QRY, p->path, strlen(p->path), p->nomeArq, strlen(p->nomeArq), p->extension, strlen(p->extension));

			// printf("path: %s\n", p->path);
			// printf("nomeArq: %s\n", p->nomeArq);
			// printf("extension: %s\n", p->extension);

			p->PathQry = calloc(strlen(p->QRY) + strlen(p->path) + 10, sizeof(char));

			strcpy(p->PathQry, p->path);
			strcat(p->PathQry, "/");
			strcat(p->PathQry, p->QRY);
		}
	}

	

	normalizePath(p->BSD, p->normpathBSD, strlen(p->BSD));
	printf("normpathBSD: %s\n", p->normpathBSD);
	p->GeoSVG = calloc(strlen(p->BSD) + strlen(p->nomeArq) + 20, sizeof(char));

	strcpy(p->GeoSVG, p->normpathBSD);

	strcat(p->GeoSVG, "/");//normalizar

	strcat(p->GeoSVG, p->nomeArq);

	printf("GeoSVG address: %p\n", p->GeoSVG);
	printf("GeoSVG: %s\n", p->GeoSVG);

	printf("nomeArq: %s\n", p->nomeArq);
	printf("nomeArq address: %p\n", p->nomeArq);

	strcat(p->GeoSVG, ".svg");

	//QRY
	p->QrySVG = calloc(strlen(p->BSD) + strlen(p->nomeArq) + 20, sizeof(char));
	printf("\n\nAQUI!!!!!!\n\n");
	strcpy(p->QrySVG, p->normpathBSD);
	strcat(p->QrySVG, "/");
	strcat(p->QrySVG, p->nomeArq);
	strcat(p->QrySVG, "-qry.svg");

	p->GenTxt = calloc(strlen(p->BSD) + strlen(p->nomeArq) + 20, sizeof(char));
	strcpy(p->GenTxt, p->normpathBSD);
	strcat(p->GenTxt, "/");
	strcat(p->GenTxt, p->nomeArq);
	strcat(p->GenTxt, "-qry.txt");

	
	printf("BED: %s\n", p->BED);
	printf("GEO: %s\n", p->GEO);
	printf("BSD: %s\n", p->BSD);
	printf("GeoSVG: %s\n", p->GeoSVG);
	// printf("Qry: %s\n", p->QRY);



	// paths

	return p;

}