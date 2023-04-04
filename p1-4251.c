#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

int loop(int contador, int maior, int menor, int numero)
{
    if(contador<=0)
    {
        int perfeito = maior - menor;

        if(primo(perfeito, perfeito-1))
        {
            printf("As idades %d %d sao perfeitas", menor, maior);
        }
        else
        {
            printf("As idades %d %d nao sao perfeitas", menor, maior);
        }
        
        return 0;
    }
    else
    {
        scanf("%d", &numero);

        if(numero>maior)
        {
            maior = numero;
        }
        if(numero<menor)
        {
            menor = numero;
        }

        return loop(contador-1, maior, menor, numero);
    }
}

int main()
{
    int contador, maior, menor, numero;
    scanf("%d", &contador);

    loop(contador, 0, 1000, numero);

    return 0;
}