#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "formas.h"
#include "lista.h"
#include "qry.h"

//falta rotacionar g com o tiro

void mv(int id, int dx, int dy, FILE* txt, FILE* svg, void* lista){
    double Xf, Yf;
    Lista l = (lista)lista;
    void* aux = getFirst(l);
    while(aux != NULL){
        aux = getNext(l);
        if(getId(aux) == id){
            Xf = SetX(aux, getX(aux) + dx);
            Yf = SetY(aux, getY(aux) + dy);
            fprintf(txt, "moved id: %d, Xi: %d, Yi: %d, Xf: %d, Yf: %d\n", id, getX(aux), GetY(aux), &Xf, &Yf);
        }
    }
}

void g(int id, double grs, FILE* txt, FILE* svg, void* lista){//função rotate
    int type;
    Lista l = (lista)lista;
    void* aux = getFirst(l);
    while(aux != NULL){
        aux = getNext(l);
        if(getId(aux) == id){
            type = getType(aux);
            if(type == 1){
                fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%lf\" transform=\"rotate(%lf)\"/>\n", getX(aux), getY(aux), getR(aux), getFill(aux), getStroke(aux), getStrokeWidth(aux), &grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
            if(type == 2){
                fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%lf\" transform=\"rotate(%lf)\"/>\n", getX(aux), getY(aux), getW(aux), getH(aux), getFill(aux), getStroke(aux), getStrokeWidth(aux), &grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
            if(type == 3){
                fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" transform=\"rotate(%lf)\"/>\n", getX(aux), getY(aux), getX2(aux), getY2(aux), getStroke(aux), getStrokeWidth(aux), &grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
            if(type == 4){
                fprintf(svg, "<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%lf\" transform=\"rotate(%lf)\"/>\n", getX(aux), getY(aux), getFill(aux), getStroke(aux), getStrokeWidth(aux), &grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
        }
    }
}

void ff(int id , double r, double p, double h, void* lista){
    double Rd, Rl, Yf;
    Lista l = (lista)lista;
    void* aux = getFirst(l);
    while(aux != NULL){
        aux = getNext(l);
        if (id == GetId(aux)){
            Rd = getX(aux) + r;
            Rl = getY(aux) - r;
            Yf = getY(aux) + p;
            //teste area do quadrado
            fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\">\n", Rl, Yf, 2*r, h);
            //lembrar de apagar esse teste
        }
    }
}

// void tf(){

// }