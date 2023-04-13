#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

void normalizePath(char *path, char *normPath, int lenNormPath)
{
	if (path[lenNormPath-1] == '/')
	{
		strcpy(normPath, path);
		normPath[lenNormPath-1] = '\0';
		
	}
	else
	{
		strcpy(normPath, path);
	}
}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath)
{
	char *bar = strrchr(path, '/');
	if (bar)
	{
		strcpy(fullPath, path);
		strcat(fullPath, "/");
		strcat(fullPath, fileName);
		strcat(fullPath, ext);
	}
	else
	{
		strcpy(fullPath, path);
		strcat(fullPath, fileName);
		strcat(fullPath, ext);
	}
}

void getFileName(char *fullPath, char *fileName, char *lenFileName)
{
	char *bar = strrchr(fullPath, '/');
	if (bar)
	{
		strcpy(fileName, bar + 1);
	}
	else
	{
		strcpy(fileName, fullPath);
	}
}

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath)
{

	strcpy(fullPath, path);

	// printf("fullPath: %s", fullPath);

	if (path[strlen(path) - 1] != '/')
	{
		strcat(fullPath, "/");
	}

		strcat(fullPath, fileName);

	// strcat(fullPath, "/");
}

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{
	char *bar = strrchr(fullPath, '/');

	printf("fullPath: %s", fullPath);
	printf("\nfullPath address: %p", fullPath);

	printf("\npath: %s", path);
	printf("\npath address: %p", path);

	if (bar)
	{
		printf("\n\n%s\n\n", path);
		strcpy(path, fullPath);
		path[bar - fullPath] = '\0';
		strcpy(nomeArq, bar + 1);
	}
	else
	{
		strcpy(path, "");
		strcpy(nomeArq, fullPath);
	}

	char *dot = strrchr(nomeArq, '.');
	if (dot)
	{
		strcpy(extArq, dot + 1);
		nomeArq[dot - nomeArq] = '\0';
	}
	else
	{
		strcpy(extArq, "");
	}
}

void getPath(char *fullPath, char *path, int lenPath)
{
	char *bar = strrchr(fullPath, '/');
	if (bar)
	{
		strcpy(path, fullPath);
		path[bar - fullPath] = '\0';
	}
	else
	{
		strcpy(path, "");
	}
}