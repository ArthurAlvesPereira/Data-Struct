#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

void normalizePath(char *path, char *normPath, int lenNormPath)
{

	if (path[lenNormPath-1] == '/')
	{
		normPath = path;
		normPath[lenNormPath-1] = '\0';

	}
	else
	{

		normPath = path;
						printf("!!!!!!!!\nTESTE BARRA!!!!!!!!\n");

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

	if (path[strlen(path) - 1] != '/')
	{
		strcat(fullPath, "/");
	}

		strcat(fullPath, fileName);

	// strcat(fullPath, "/");
}

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{
	int bar, dot;
	int fullPathLen = strlen(fullPath);

	for (int i = 0; i < fullPathLen; i++){
		if (fullPath[i] == '/'){
			bar = i;
		}
	}

	if (bar >= 0){
		strncpy(path, fullPath, bar);
		path[bar] = '\0';
	}

	for (int i = fullPathLen - 1; i >= 0; i--){
		if (fullPath[i] == '.'){
			dot = i;
			break;
		} else if (fullPath[i] == '/'){
			break;
		}
	}

	if(dot > bar) {
		strncpy(nomeArq, fullPath + bar + 1, dot - bar - 1);
		nomeArq[dot - bar - 1] = '\0';
	} else {
		strncpy(nomeArq, fullPath + bar + 1, fullPathLen - bar -1);
		nomeArq[fullPathLen - bar - 1];
	}

	if (dot >= 0) {
        strncpy(extArq, fullPath + dot, lenExtArq - 1);
        extArq[lenExtArq - 1] = '\0';
    } else {
        extArq[0] = '\0';
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