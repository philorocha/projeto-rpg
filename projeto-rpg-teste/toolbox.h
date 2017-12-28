#ifndef TOOLBOX_H_INCLUDED
#define TOOLBOX_H_INCLUDED
#include "personagens.h"

int dado() {
    return rand() % 6 + 1;
}

int testarSorte(Personagem *p) {
    if (dado() + dado() <= (*p).sorte) {
        (*p).sorte -= 1;
        return 1;
    }
    (*p).sorte -= 1;
    return 0;
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

#endif // TOOLBOX_H_INCLUDED
