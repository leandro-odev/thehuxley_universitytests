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
    //Verifica se o contador chegou a 0, se sim, verifica se as idades são perfeitas.
    if(contador<=0)
    {
        //As idades são perfetas se a diferença entre elas for um número primo.
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
        /*
        Se o contador não chegou a 0, o usuário irá digitar um número.
        Caso o número seja maior que o maior número digitado, o maior número será atualizado.
        */
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
    /*
    Entrará no looping com o valor de contador, e irá decrementar até chegar a 0.
    Contador é o número de vezes que o usuário irá digitar um número.
    */
    loop(contador, 0, 1000, numero);

    return 0;
}