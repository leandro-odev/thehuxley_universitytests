#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double eliminatorias(double x){
    double y = x*2.5;
    return y;
}

double torneios(double x){
    double y = x*3;
    return y;
}

double copa(double x){
    double y = x*4;
    return y;
}

int main(){

    double braa, brae, brat, bracopa, braf, brar;
    double arga, arge, argt, argcopa, argf, argr;
    double p1, p2, f1, f2;

    scanf("%lf %lf %lf %lf %lf %lf", &braa, &brae, &brat, &bracopa, &braf, &brar);
    scanf("%lf %lf %lf %lf %lf %lf", &arga, &arge, &argt, &argcopa, &argf, &argr);

    if(brar==1){
        f1=1;
    } else if(brar==2){
        f1=1;
    } else if(brar==3){
        f1=0.86;
    } else if(brar==4){
        f1=0.86;
    } else if(brar==5){
        f1=0.85;
    }

    if(argr==1){
        f2=1;
    } else if(argr==2){
        f2=1;
    } else if(argr==3){
        f2=0.86;
    } else if(argr==4){
        f2=0.86;
    } else if(argr==5){
        f2=0.85;
    }


    p1 = braa + eliminatorias(brae) + torneios(brat) + copa(bracopa) + braf + f1;
    p2 = arga + eliminatorias(arge) + torneios(argt) + copa(argcopa) + argf + f2;
    
  
    if(p1>p2){
        printf("Selecao 1");
    } else if(p2>p1){
        printf("Selecao 2");
    }else{
        printf("As duas selecoes estao no mesmo nivel");
    }

    return 0;
}