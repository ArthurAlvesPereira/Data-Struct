#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"
#include "formas.h"
#include "qry.h"

int insideCirc(void* currentnode, double x, double y)
{
    double cx = GetX(currentnode);
    double cy = GetY(currentnode);
    double r = GetR(currentnode);

    
     return (pow(x - cx, 2) + pow(y - cy, 2) <= pow(r, 2)) ? 1 : 0;
}

int insideRect(void* currentnode, double x, double y)
{
    double rx = GetX(currentnode);
    double ry = GetY(currentnode);
    double rw = GetW(currentnode);
    double rh = GetH(currentnode);
    
    return (x >= rx && x <= rx + rw && y >= ry && y <= ry + rh) ? 1 : 0;
}

int insideLine(void* currentnode, double x, double y)
{
    double lx1 = GetX(currentnode);
    double ly1 = GetY(currentnode);
    double lx2 = GetX2(currentnode);
    double ly2 = GetY2(currentnode);
    
    double mainline = GetLength(lx1, ly1, lx2, ly2);
    double line1 = GetLength(lx1, ly1, x, y);
    double line2 = GetLength(x, y, lx2, ly2);

    return line1 + line2 == mainline ? 1 : 0;
}

int insideText(void* currentnode, double x, double y)
{
    double tx = GetX(currentnode);
    double ty = GetY(currentnode);

    return (x == tx && y == ty) ? 1 : 0;
}


double na(FILE* qry,FILE* txt, double v){

    fprintf(txt,"Nivel de agressividade = %.2lf\n",v);

    return v;
}

void tp(FILE* svg, FILE* txt, void* l, double x, double y){

    double x1,y1;
    int count = 0;
    fprintf(txt,"Coordenadas torpedo (%.2lf,%.2lf)\n",x,y);
    // fprintf(svg, "<text x=\"%.2lf\" y=\"%.2lf\" fill=\"red\">x</text>\n",x,y);
    count = tpcounter(l,count,x,y,svg,txt);
    fprintf(svg,"<text x=\"%.2lf\" y=\"%.2lf\" fill=\"red\">*%d</text>\n",x,y,count);
    printf("Torpedos acertados: %d\n",count);
    
    

}

int tpcounter(void* l, int count, double x, double y, FILE* svg, FILE* txt){

    int id, shots;
    double protec, x1, x2, y1, y2, r, w, h;
    char corb[20], corp[20], cor[20], txto[100], anchor[2];

    void* node;
    void* nodeaux;

    for (node = getFirst(l);node ; node = getNext(l, node)){
        Form f = get(l, node);
        // printf("\n\n\nTeste tipo: %c\n\n\n",GetType(f));
        switch (GetTypeInt(f))
        {
        case 1:
            if (insideCirc(f, x, y)){

                printf("x: %lf y: %lf\n",x,y);
                printf("Id: %d\nx: %lf\ny: %lf\n",GetId(f),GetX(f),GetY(f));

                id = GetId(f);
                x1 = GetX(f);
                y1 = GetY(f);
                r = GetR(f);
                shots = GetShots(f);
                protec = GetProtec(f);
                strcpy(corb, GetCorb(f));
                strcpy(corp, GetCorp(f));
                fprintf(txt,"Torpedo atingiu o circulo de id: %d, x: %.2lf, y: %.2lf, r: %.2lf, shots: %d, protec: %.2lf, corb: %s, corp: %s\n",id,x1,y1,r,shots,protec,corb,corp);
                // fprintf(svg,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"2\" fill=\"%s\" fill-opacity=\"0.5\"/>\n",x1,y1,r,corb,corp);
                count++;
                if (shots == 0){
                    fprintf(txt,"Circulo %d foi destruido\n",id);
                    nodeaux = node;
                    node = getPrevious(l, node);
                    remover(l, nodeaux);
                }
            }
            break;
        case 2:
            if (insideRect(f, x, y)){
                id = GetId(f);
                x1 = GetX(f);
                y1 = GetY(f);
                w = GetW(f);
                h = GetH(f);
                shots = GetShots(f);
                SetShots(f, shots+1);
                shots =GetShots(f);
                protec = GetProtec(f);
                strcpy(corb, GetCorb(f));
                strcpy(corp, GetCorp(f));
                fprintf(txt,"Torpedo atingiu retangulo %d, x: %.2lf, y: %.2lf, w: %.2lf, h: %.2lf, shots: %d, protec: %.2lf, corb: %s, corp: %s\n",id,x1,y1,w,h,shots,protec,corb,corp);
                //fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" stroke-width=\"2\" fill=\"%s\" fill-opacity=\"0.5\"/>\n",x1,y1,w,h,corb,corp);
                count++;
                if (shots == 3){

                    fprintf(txt,"Retangulo %d foi destruido\n",id);
                    nodeaux = node;
                    node = getPrevious(l, node);
                    remover(l, nodeaux);
                }
            }
            break;

        case 3:
        if (insideLine(f, x, y)){
                id = GetId(f);
                x1 = GetX(f);
                y1 = GetY(f);
                x2 = GetX2(f);
                y2 = GetY2(f);
                shots = GetShots(f);
                protec = GetProtec(f);
                strcpy(corb, GetCorb(f));
                strcpy(corp, GetCorp(f));
                fprintf(txt,"Torpedo atingiu linha %d, x1: %.2lf, y1: %.2lf, x2: %.2lf, y2: %.2lf, shots: %d, protec: %.2lf, corb: %s, corp: %s\n",id,x1,y1,x2,y2,shots,protec,corb,corp);
                fprintf(svg,"<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"2\"/>\n",x1,y1,x2,y2,corb);
                count++;
                if (shots == 0){
                    fprintf(txt,"Linha %d foi destruida\n",id);
                    remover(l, f);
                }
                else{
                    SetShots(f, shots-1);
                    //SetProtec(f, protec-10);
                }
            }
           break;
        case 4:
            if (insideText(f, x, y)){

                printf("\n\nTravou aqui?\n\n");

                id = GetId(f);
                x1 = GetX(f);
                y1 = GetY(f);
                strcpy(cor, GetCor(f));
                strcpy(txto, GetText(f));
                shots = GetShots(f);
                protec = GetProtec(f);
                fprintf(txt,"Torpedo atingiu texto de id: %d, x: %.2lf, y: %.2lf, cor: %s, text: %s, shots: %d, protec: %.2lf\n",id,x1,y1,cor,txto,shots,protec);
                fprintf(svg,"<text x=\"%lf\" y=\"%lf\" fill=\"%s\">%s</text>\n",x1,y1,cor,txto);
                count++;
                if (shots == 0){
                    fprintf(txt,"Retangulo %d foi destruido\n",id);
                    nodeaux = node;
                    node = getPrevious(l, node);
                    remover(l, nodeaux);
                }
            }
            break;
        
        default:
            break;
        }
   
            //fprintf(txt,"Torpedo acertou o alvo\n");
            //fprintf(svg,"<text x=\"%lf\" y=\"%lf\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" text-anchor=\"start\">*%d</text>\n", x, y, count);
        }
    return count;
    }

void tr(void* l, double x, double y, double x2, double y2,int id,FILE* svg, FILE* txt){

    // double x1,y1,dx,dy;
    // int id;
    // fscanf(qry,"%lf %lf %lf %lf %d",&x,&y,&dx,&dy,&id);
    fprintf(txt,"Coordenadas 1 (%.2lf,%.2lf)\n",x,y);
    trcounter(l, x, y, x2, y2, id, svg, txt);
}

int trcounter(void* l, double xpar, double ypar, double x2, double y2,int id, FILE* svg, FILE* txt){

    int idaux, shots;
    double protec, x, x1, y, y1, r, w, h;
    char corb[20], corp[20], cor[20], txto[100], anchor[2];

    void* node;
    void* nodeaux;
    void* newform;

    for (node = getFirst(l); node != NULL; node = getNext(l, node))
    {
        Form f = get(l, node);
        switch (GetTypeInt(f))
        {
        case 1:
            if (insideCirc(f, xpar, ypar)){
                idaux = GetId(f);
                x1 = GetX(f);
                y1 = GetY(f);
                r = GetR(f);
                shots = GetShots(f);
                protec = GetProtec(f);
                strcpy(corb, GetCorb(f));
                strcpy(corp, GetCorp(f));

                newform = CreateCircle(idaux, x1 + xpar, y1 + ypar, r, corb, corp);
                insert(l, newform);
                fprintf(txt,"Torpedo atingiu circulo %d\n",idaux);
                fprintf(svg,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"2\" fill=\"%s\" fill-opacity=\"0.5\"/>\n",x1,y1,r,corb,corp);
                fprintf(svg, "<text x=\"%lf\" y=\"%lf\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" text-anchor=\"start\">@</text>\n", x1, y1);
                // count++;
                if (shots == 0){
                    fprintf(txt,"Circulo %d foi destruido\n",id + idaux);
                    nodeaux = node;
                    node = getPrevious(l, node);
                    remover(l, nodeaux);
                }
            }
            break;
        case 2:
            if (insideRect(f, xpar, ypar)){
                idaux = GetId(f);
                x1 = GetX(f);
                y1 = GetY(f);
                w = GetW(f);
                h = GetH(f);
                shots = GetShots(f);
                SetShots(f, shots+1);
                shots =GetShots(f);
                protec = GetProtec(f);
                strcpy(corb, GetCorb(f));
                strcpy(corp, GetCorp(f));

                newform = CreateRect(idaux, x1 + xpar, y1 + ypar, w, h, corb, corp);
                insert(l, newform);

                printf("Torpedo atingiu retangulo %d\n",id);
                fprintf(txt,"Torpedo atingiu retangulo %d\n",idaux);//add direto dos gets
                fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" stroke-width=\"2\" fill=\"%s\" fill-opacity=\"0.5\"/>\n",x1,y1,w,h,corb,corp);
                fprintf(svg, "<text x=\"%lf\" y=\"%lf\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" text-anchor=\"start\">@</text>\n", x1, y1);

                // count++;
                if (shots == 3){
                    fprintf(txt,"Retangulo %d foi destruido\n",idaux);
                    nodeaux = node;
                    node = getPrevious(l, node);
                    remover(l, nodeaux);
                }
            }
            break;

        case 3:
            if (insideLine(f, xpar, ypar)){
                idaux = GetId(f);
                x1 = GetX(f);
                y1 = GetY(f);
                x2 = GetX2(f);
                y2 = GetY2(f);
                shots = GetShots(f);
                SetShots(f, shots+1);
                shots =GetShots(f);
                protec = GetProtec(f);
                strcpy(corb, GetCorb(f));

                newform = CreateLine(idaux, x1 + xpar, y1 + ypar, x2 + xpar, y2 + ypar, corb);
                insert(l, newform);

                printf("Torpedo atingiu linha %d\n",id);
                fprintf(txt,"Torpedo atingiu linha %d\n",idaux);
                fprintf(svg,"<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"2\"/>\n",x1,y1,x2,y2,corb);
                // count++;
                if (shots == 0){
                    fprintf(txt,"Linha %d foi destruida\n",idaux);
                    nodeaux = node;
                    node = getPrevious(l, node);
                    remover(l, nodeaux);
                }
            }

            case 4:
                if(insideText(f, xpar, ypar)){
                    idaux = GetId(f);
                    x1 = GetX(f);
                    y1 = GetY(f);

                    strcpy(anchor, GetAnchor(f));
                    strcpy(cor, GetCorb(f));
                    strcpy(txto, GetCorp(f));
                    strcpy(txto, GetText(f));

                    newform = CreateText(idaux, x1 + xpar, y1 + ypar, txto, anchor, corb, corp);
                    insert(l, newform);

                    printf("Torpedo atingiu texto %d\n",id);
                    fprintf(txt,"Torpedo atingiu texto %d\n",idaux);
                    fprintf(svg,"<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" text-anchor=\"start\">%s</text>\n",x1,y1,cor,cor,txto);
                    // count++;
                    if (shots == 0){
                        fprintf(txt,"Texto %d foi destruido\n",idaux);
                        nodeaux = node;
                        node = getPrevious(l, node);
                        remover(l, nodeaux);
                    }
                }


            default:
            break;
        }
    }
}

void be(FILE* qry, FILE* txt){

    double x,y,r;
    fscanf(qry,"%lf %lf %lf",&x,&y,&r);
    fprintf(txt,"Coordenadas 1 (%.2lf,%.2lf)\n",x,y);
}

void se(FILE* qry, FILE* txt){

    int id;
    fscanf(qry,"%d",&id);
    fprintf(txt,"Id = %d\n",id);
}

void sec(FILE* qry, FILE* txt){

    int id, j;
    fscanf(qry,"%d %d",&id, &j);
    fprintf(txt,"Id = %d j= %d\n",id, j);
}


void mvh(FILE* qry, FILE* txt){

    int id, j;
    double dx;
    fscanf(qry,"%d %d %lf",&id, &j, &dx);
    fprintf(txt,"Id = %d j= %d dx= %lf\n",id, j, dx);
}

void mvv(FILE* qry, FILE* txt){

    int id, j;
    double dy;
    fscanf(qry,"%d %d %lf",&id, &j, &dy);
    fprintf(txt,"Id = %d j= %d dy= %lf\n",id, j, dy);
}
// void scanqry(){
//     char linha[100];
//     char comando[3];

//     FILE *fp;
//     fp = fopen("qry.txt", "r");
//     if (fp == NULL){
//         exit(1);
//     }else{
//     while (!feof(fp)){
//         fgets(linha, 200, fp);
//         sscanf(linha, "%s", comando);
//         if (strcmp(comando, "na")){
            
//         }
//     }
    
// }