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
    char form;
    void* node;
    Lista l = lista;
    // void* aux = getFirstLst(l);
    for (node = getFirstLst(l); node; node = getNextLst(l, node)){
        Form f = getLst(l, node);

        Xf = SetX(f, GetX(f) + dx);
        Yf = SetY(f, GetY(f) + dy);
        fprintf(txt, "moved id: %d, Xi: %lf, Yi: %lf, Xf: %lf, Yf: %lf\n", id, GetX(f), GetY(f), Xf, Yf);
        form = GetType(f);
        if (form == 'c'){
            fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", Xf, Yf, GetR(f), GetCorp(f), GetCorb(f));
        }
        if (form == 'r'){
            fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", Xf, Yf, GetW(f), GetH(f), GetCorp(f), GetCorb(f));
        }
        if (form == 'l'){
            fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1\"/>\n", Xf, Yf, GetX2(f), GetY2(f), GetCorb(f));
        }
        if (form == 't'){
            fprintf(svg, "<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"20\" text-anchor=\"%s\">%s</text>\n", Xf, Yf, GetCorp(f), GetCorb(f), GetAnchor(f), GetText(f));
    }
    }
            
    }


void g(int id, double grs, FILE* txt, FILE* svg, void* lista){//função rotate
    int type;
    Lista l = lista;
    void* aux = getFirstLst(l);
    while(aux != NULL){
        aux = getNextLst(l, aux);
        if(GetId(aux) == id){
            type = GetType(aux);
            if(type == 1){
                fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" transform=\"rotate(%lf)\"/>\n", GetX(aux), GetY(aux), GetR(aux), GetCorp(aux), GetCorb(aux), grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
            if(type == 2){
                fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" transform=\"rotate(%lf)\"/>\n", GetX(aux), GetY(aux), GetW(aux), GetH(aux), GetCorp(aux), GetCorb(aux), grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
            if(type == 3){
                fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1\" transform=\"rotate(%lf)\"/>\n", GetX(aux), GetY(aux), GetX2(aux), GetY2(aux), GetCorb(aux), grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
            if(type == 4){
                fprintf(svg, "<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" transform=\"rotate(%lf)\"/>\n", GetX(aux), GetY(aux), GetCorp(aux), GetCorb(aux), grs );
                fprintf(txt, "rotated id: %d, grs: %lf\n", id, grs);
            }
        }
    }
}

void ff(int id , double r, double p, double h, FILE* txt, FILE* svg, void* lista){
    double Rd, Rl, Yf;
    Lista l = lista;
    void* aux = getFirstLst(l);

printf("\n\nid: %d\n", id);

    while(aux != NULL){
        aux = getNextLst(l, aux);
        if (id == GetId(aux)){
            Rd = GetX(aux) + r;
            Rl = GetY(aux) - r;
            Yf = GetY(aux) + p;
            //teste area do quadrado
            fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\">\n", Rl, Yf, 2*r, h);
            //lembrar de apagar esse teste
        }
    }
}

// void tf(){

// }