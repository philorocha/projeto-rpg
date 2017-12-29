#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "toolbox.h"
#include "personagens.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    //printf("O jogo começou!\n");
    Personagem personagem;
    Criatura criatura;

    personagem.habilidade = dado() + 6;
    personagem.energia = dado() + dado() + 12;
    personagem.sorte = dado() + 6;

    criatura.energia = 7;
    criatura.habilidade = 5;

    Personagem *p = &personagem;
    Criatura *c = &criatura;

    batalha(p, c);

    printf("FIM DO TESTE!\n");
    system("pause");
    return 0;
}

