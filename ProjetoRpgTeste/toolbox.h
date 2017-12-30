    #ifndef TOOLBOX_H_INCLUDED
    #define TOOLBOX_H_INCLUDED
    #include "personagens.h"

    void ajuda() {
        FILE *f = fopen("ajuda.txt", "r");

        if (f == NULL) {
            printf("Erro ao tentar abrir o arquivo.\n");
            exit(1);
        }

        char mensagem[1000];

        while(fgets(mensagem, 1000, f) != NULL){
            printf("%s", mensagem);
        }

        fclose(f);
    }

    void interface(Personagem *p, Criatura *c) {
        printf("#################################################\n");
        printf("# PERSONAGEM\t\t     CRIATURA (INIMIGO) #\n");
        printf("# ENERGIA: %d\t\t     ENERGIA: %2d        #\n", (*p).energia, (*c).energia);
        printf("# HABILIDADE: %2d\t     HABILIDADE: %2d\t#\n", (*p).habilidade, (*c).habilidade);
        printf("# SORTE: %d\t\t\t\t\t#\n", (*p).sorte);
        printf("#################################################\n");
        printf("#                  CONTROLES                    #\n");
        printf("# 1 - ATACAR                   3 - AJUDA (DICAS)#\n");
        printf("# 2 - FUGIR                                     #\n");
        printf("#################################################\n");
        printf("OPÇÃO: ");
    }

    void interface_sorte_ataque() {
        printf("#################################################\n");
        printf("# DESEJA TESTAR A SORTE PARA CAUSAR MAIS DANO?	#\n");
        printf("# SE FOR SORTUDO CAUSA O DOBRO DE DANO (4 PTS)  #\n");
        printf("# SE FOR AZARADO CAUSA 1 PONTO A MENOS (1 PT)	#\n");
        printf("# DANO ATUAL CAUSADO: 2                         #\n");
        printf("#################################################\n");
        printf("# 1 - QUERO TESTAR A SORTE                      #\n");
        printf("# 2 - NÃO QUERO TESTAR A SORTE                  #\n");
        printf("#################################################\n");
        printf("OPÇÃO: ");
    }

    void interface_sorte_energia() {
        printf("#################################################\n");
        printf("# DESEJA TESTAR A SORTE PARA DIMINUIR O DANO	#\n");
        printf("# RECEBIDO?                                     #\n");
        printf("# SE FOR SORTUDO DIMINUI EM 1PT O DANO RECEBIDO #\n");
        printf("# SE FOR AZARADO RECEBE 1PT DE DANO EXTRA       #\n");
        printf("# DANO ATUAL RECEBIDO: 2                        #\n");
        printf("#################################################\n");
        printf("# 1 - QUERO TESTAR A SORTE                      #\n");
        printf("# 2 - NÃO QUERO TESTAR A SORTE                  #\n");
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
        while ((*p).energia > 0 && (*c).energia > 0) { //A batalha continua equanto a energia do personagem e da criatura for > 0
            int ataque_personagem = (*p).habilidade + dado() + dado(); //Definindo a força de ataque do personagem
            int ataque_criatura = (*c).habilidade + dado() + dado(); //Definindo a força de ataque da criatura
            int opcao = 1;
            do {
                interface(p, c); //Chamada à função interface que imprime o status do personagem e criatura na tela
                scanf("%d", &opcao); //Lê a opção do jogador (ataque, fugir...)
                switch (opcao) {
                    case 1:
                        if (ataque_personagem > ataque_criatura) {
                                interface_sorte_ataque();
                                int opcao_sorte;
                                scanf("%d", &opcao_sorte);
                                switch (opcao_sorte) {
                                    case 1:
                                        if (testarSorte(p)) {
                                            (*c).energia -= 4;
                                            if ((*c).energia <= 0) {
                                                printf("VOCÊ TEVE SORTE E FERIU A CRIATURA EM 4.\nPARABÉNS VOCÊ VENCEU A BATALHA!\n");
                                            } else {
                                                printf("VOCÊ TEVE SORTE E FERIU A CRIATURA EM 4.\n");
                                            }
                                        } else {
                                            (*c).energia -= 1;
                                            if ((*c).energia <= 0) {
                                                printf("VOCÊ FOI AZARADO E FERIU A CRIATURA EM 1.\nPARABÉNS VOCÊ VENCEU A BATALHA!\n");
                                            } else {
                                                printf("VOCÊ FOI AZARADO E FERIU A CRIATURA EM 1.\n");
                                            }
                                        }
                                        break;
                                    case 2:
                                        (*c).energia -= 2;
                                        if ((*c).energia <= 0) {
                                            printf("VOCÊ FERIU A CRIATURA EM 2.\nPARABÉNS VOCÊ VENCEU A BATALHA!\n");
                                        } else {
                                            printf("VOCÊ FERIU A CRIATURA EM 2.\n");
                                        }
                                        break;
                                    default:
                                        printf("OPÇÃO INVÁLIDA!\n");
                                }
                                system("pause");
                        } else if (ataque_personagem < ataque_criatura) {
                            interface_sorte_energia();
                            int opcao_sorte;
                            scanf("%d", &opcao_sorte);
                            switch (opcao_sorte) {
                                case 1:
                                    if (testarSorte(p)) {
                                        (*p).energia -= 1;
                                        if ((*p).energia <= 0) {
                                            printf("VOCÊ TEVE SORTE E A CRIATURA ESQUIVOU E FERIU VOCÊ EM 1.\nVOCÊ MORREU!\n");
                                        } else {
                                            printf("VOCÊ TEVE SORTE E A CRIATURA ESQUIVOU E FERIU VOCÊ EM 1.\n");
                                        }
                                    } else {
                                        (*p).energia -= 3;
                                        if ((*p).energia <= 0) {
                                            printf("VOCÊ FOI AZARADO E A CRIATURA ESQUIVOU E FERIU VOCÊ EM 3.\nVOCÊ MORREU!\n");
                                        } else {
                                            printf("VOCÊ FOI AZARADO E A CRIATURA ESQUIVOU E FERIU VOCÊ EM 3.\n");
                                        }
                                    }
                                    break;
                                case 2:
                                    (*p).energia -= 2;
                                    if ((*p).energia <= 0) {
                                        printf("A CRIATURA ESQUIVOU E FERIU VOCÊ EM 2.\nVOCÊ MORREU!\n");
                                    } else {
                                        printf("A CRIATURA ESQUIVOU E FERIU VOCÊ EM 2.\n");
                                    }
                                    break;
                                default:
                                    printf("OPÇÃO INVÁLIDA!\n");
                            }
                            system("pause");
                        } else {
                            printf("AMBOS DEFENDERAM O ATAQUE.\n");
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
                        ajuda();
                        system("pause");
                        break;
                    default:
                        printf("Opção inválida.\n");
                }
                system("cls");
            } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);
        }
    }

    #endif // TOOLBOX_H_INCLUDED
