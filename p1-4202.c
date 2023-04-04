#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int n1, n2, n3, n4;
    double chance=0;
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if(n1==1){
        chance = chance + 27.4;
    } else if(n1==2){
        chance = chance - 10.5;
    } else if(n1==3){
        chance = chance + 19.7;
    }

    if(n2==1){
        chance = chance - 41.3;
    } else if(n2==2){
        chance = chance + 40.4;
    }

    if(n3==1){
        chance = chance - 22.8;
    } else if(n3==2){
        chance = chance + 11.4;
    } else if(n3==3){
        chance = chance + 38.6;
    }
    if(n4!=0){
        chance = chance + (2.3 * n4);
    }
    
    if(chance<=40){
        printf("Melhor nao tentar.");
    } else if(chance<=80){
        printf("Chances boas, pode convidar.");
    } else{
        printf("Provavelmente vao aceitar.");
    }

    return 0;
}