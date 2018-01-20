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

    /*Personagem personagem;
    Criatura criatura;

    personagem.habilidade = dado() + 6;
    personagem.energia = dado() + dado() + 12;
    personagem.sorte = dado() + 6;

    criatura.energia = 10;
    criatura.habilidade = 6;

    batalha(&personagem, &criatura);

    printf("FIM DO TESTE!\n");
    system("pause");*/

    novo_jogo();
    /*FILE *fb = fopen("desafios\\desafios.bin", "ab");
    //FILE *fb2 = fopen("desafios\\d1.txt", "rb");
    //char texto[1000];
    //fread(texto, sizeof(texto), 1, fb2);
    int i = fread(texto, sizeof(texto), 1, fb);

   printf("%d", i);
    /*d.concluido = 0;
    d.criatura.energia = 9;
    d.criatura.habilidade = 5;
    strcpy(d.criatura.nome, "Cão Raivoso");
    fread(d.texto, sizeof(d.texto), 1, fb2);

    fwrite(&d, sizeof(Desafio), 1, fb);
    //int i = fread(&d1, sizeof(Desafio), 1, fb);
    //printf("%d\n", i);
    fclose(fb2);
    fclose(fb);
    //fclose(fb2);*/
    return 0;
}

