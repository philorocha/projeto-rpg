#ifndef TOOLBOX_H_INCLUDED
#define TOOLBOX_H_INCLUDED
#include "personagens.h"

void interface(Personagem *p, Criatura *c) {
    printf("#################################################\n");
    printf("# PERSONAGEM\t\tCRIATURA (INIMIGO)\t#\n");
    printf("# ENERGIA: %d\t\tENERGIA: %d\t\t#\n", (*p).energia, (*c).energia);
    printf("# HABILIDADE:  %d\tHABILIDADE: %d\t\t#\n", (*p).habilidade, (*c).habilidade);
    printf("#################################################\n");
    printf("#\t\tCONTROLES\t\t\t#\n");
    printf("# 1 - ATACAR\t\t2 - TENTAR A SORTE\t#\n");
    printf("# 3 - FUGIR\t\t4 - AJUDA (DICAS)\t#\n");
    printf("#################################################\n");
    printf("OPÇÃO: ");
}

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

void batalha(Personagem *p, Criatura *c) {
    int atqp = (*p).habilidade + dado() + dado();
    int atqc = (*c).habilidade + dado() + dado();
    int opcao = 1;

    do {
        interface(p, c);
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                if (atqp > atqc) {
                    (*c).energia -= 2;
                    if ((*c).energia <= 0) {
                        printf("Você feriu a criatura em 2.\nParabéns você venceu a batalha!\n");
                        system("pause");
                    } else {
                        printf("Você feriu a criatura em 2.\n");
                        system("pause");
                    }
                } else if (atqp < atqc) {
                    (*p).energia -= 2;
                    if ((*p).energia <= 0) {
                        printf("A criatura esquivou e feriu você em 2.\nVocê morreu!\n");
                        system("pause");
                    } else {
                        printf("A criatura esquivou e feriu você em 2.\n");
                        system("pause");
                    }
                } else {
                    printf("Ambos defenderam o ataque.\n");
                    system("pause");
                }
                break;
            case 2:
                printf("Não implementado ainda.\n");
                system("pause");
                break;
            case 3:
                printf("Não implementado ainda.\n");
                system("pause");
                break;
            case 4:
                printf("Não implementado ainda.\n");
                system("pause");
                break;
            default:
                printf("Opção inválida.\n");
                system("pause");
        }
        system("cls");
    } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);

    if ((*p).energia > 0 && (*c).energia > 0) {
        batalha(p, c);
    }
}

#endif // TOOLBOX_H_INCLUDED
