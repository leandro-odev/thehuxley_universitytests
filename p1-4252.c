#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fatorial(int x)
{
    if(x<=1)
    {
        return 1;
    }
    else
    {
        return x *fatorial(x-1);
    }
}

int coprimo(int a, int b){
    if(b==0)
    {
        return a;
    }
    else
    {
        return coprimo(b, a%b);
    }
}

int primo(int n, int x)
{
    if(x==1)
    {
        return 1;
    }
    else {
        if(n%x == 0 || n == 1)
        {
            return 0;
        }
        else
        {
            return primo(n, x-1);
        }
    }
}

int loop(int rounds, double total_Nosredna, double total_Ordep, int contagem)
{
    //Verifica se a contagem chegou ao numero de rounds, se sim, verifica quem foi o campeão.
    if(contagem > rounds)
    {
        printf("Total Nosredna = %.2lf\n", total_Nosredna);
        printf("Total Ordep = %.2lf\n", total_Ordep);

        if(total_Nosredna>total_Ordep)
        {
            printf("Nosredna foi o campeao!");
        }
        else if(total_Ordep> total_Nosredna)
        {
            printf("Ordep foi o campeao!");
        }

        return 0;
    }
    else
    {
        //Recebe os valores das bolas de Nosredna e Ordep.
        double nosredna1, nosredna2, nosredna3, nosredna4, nosredna5, ordep1, ordep2, ordep3, ordep4, ordep5;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &nosredna1, &nosredna2, &nosredna3, &nosredna4, &nosredna5, &ordep1, &ordep2, &ordep3, &ordep4, &ordep5);

        //Caso a jogada seja um numero primo, Ordep tem sua vez anulada(valor da bola = 0).
        ordep2 = 0;
        ordep3 = 0;
        ordep5 = 0;
        
        //Caso a jogada seja um numero coprimo ao numero rodada, Nosredna tem sua vez anulada(valor da bola = 0).
        if(coprimo(contagem, 1)==1) nosredna1 = 0;
        if(coprimo(contagem, 2)==1) nosredna2 = 0;
        if(coprimo(contagem, 3)==1) nosredna3 = 0;
        if(coprimo(contagem, 4)==1) nosredna4 = 0;
        if(coprimo(contagem, 5)==1) nosredna5 = 0;

        /*
        Caso Ordep derrube uma bola em que o fatorial do valor dela seja um numero divisível por 3
        Ordep vai receber um aumento adicional de 10% em relação ao valor da bola.
        */
        if(fatorial(ordep1)%3 == 0) ordep1 += ordep1*0.1;
        if(fatorial(ordep4)%3 == 0) ordep4 += ordep4*0.1;
        
        /*
        Caso Nosredna derrube uma bola em que o a soma dos dígitos seja um numero divisível por 2,
        Nosredna vai receber um aumento adicional de 15% em relação ao valor da bola.
        */
        if(nosredna1!=0 && nosredna1!=10 && (int)nosredna1%2 == 0) nosredna1 += nosredna1*0.15;
        if(nosredna2!=0 && nosredna2!=10 && (int)nosredna2%2 == 0) nosredna2 += nosredna2*0.15;
        if(nosredna3!=0 && nosredna3!=10 && (int)nosredna3%2 == 0) nosredna3 += nosredna3*0.15;
        if(nosredna4!=0 && nosredna4!=10 && (int)nosredna4%2 == 0) nosredna4 += nosredna4*0.15;
        if(nosredna5!=0 && nosredna5!=10 && (int)nosredna5%2 == 0) nosredna5 += nosredna5*0.15;

        total_Nosredna += nosredna1 + nosredna2 + nosredna3 + nosredna4 + nosredna5;
        total_Ordep += ordep1 + ordep2 + ordep3 + ordep4 + ordep5;

        return loop(rounds, total_Nosredna, total_Ordep, contagem+1);
    }
}

int main()
{
    int rounds;
    scanf("%d", &rounds);

    loop(rounds, 0, 0, 1);

    return 0;
}