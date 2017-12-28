#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int dado() {
    return rand() % 6 + 1;
}

typedef struct {
    int habilidade;
    int energia;
    int sorte;
} Personagem;

typedef struct {
    int habilidade;
    int energia;
} Criatura;

void testarSorte(Personagem *p) {
    if (dado() + dado() <= (*p).sorte) {
        printf("Você teve sorte!\n");
    } else {
        printf("Você não teve sorte!\n");
    }
    (*p).sorte -= 1;
}

void batalha(Personagem *p, Personagem personagem, Criatura criatura) {
    criatura.habilidade += dado() + dado();
    personagem.habilidade += dado() + dado();

    if (personagem.habilidade > criatura.habilidade) {
        criatura.energia -= 2;
        if (criatura.energia <= 0) {
            printf("Você feriu a criatura em 2.\nParabéns você venceu a batalha!\n");
        } else {
            printf("Você feriu a criatura em 2.\nAgora ela tem %d de energia\n", criatura.energia);
        }
    } else if (personagem.habilidade < criatura.habilidade) {
        (*p).energia -= 2;
        if ((*p).energia <= 0) {
            printf("A criatura feriu você em 2.\nVocê morreu!\n");
        } else {
            printf("A criatura feriu você em 2.\nAgora você tem %d de energia\n", (*p).energia);
        }
    }
    if (personagem.habilidade == criatura.habilidade || ((*p).energia != 0 && criatura.energia !=0)) {
        batalha(p, personagem, criatura);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    printf("O jogo começou!\n");
    Personagem personagem;
    Criatura criatura;

    personagem.habilidade = dado() + 6;
    personagem.energia = dado() + dado() + 12;
    personagem.sorte = dado() + 6;

    criatura.energia = 8;
    criatura.habilidade = 8;

    Personagem *p = &personagem;

    printf("Sua sorte antes do teste: %d\n", personagem.sorte);
    testarSorte(p);
    printf("Sua sorte após o teste: %d\n", personagem.sorte);
    return 0;
}
