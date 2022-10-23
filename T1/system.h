#ifndef SYSTEM_H
#define SYSTEM_H

typedef void* path;

void* readParamter(int argc, char **argv);
void geo_read(void* fp, void* l);
void KillPath(void* p);

#endif