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

    printf("O jogo come�ou!\n");
    Personagem personagem;
    Criatura criatura;

    personagem.habilidade = dado() + 6;
    personagem.energia = dado() + dado() + 12;
    personagem.sorte = dado() + 6;

    criatura.energia = 8;
    criatura.habilidade = 12;

    Personagem *p = &personagem;

    batalha(p, personagem, criatura);
    return 0;
}

