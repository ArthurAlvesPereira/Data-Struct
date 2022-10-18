#ifndef LINHA_H
#define LINHA_H

typedef void* Line;

Line CreateLine(char* type, int id, double x, double y, double w, double h, char* cor);

#endif