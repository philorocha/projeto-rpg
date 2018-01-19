#ifndef PERSONAGENS_H_INCLUDED
#define PERSONAGENS_H_INCLUDED

typedef struct {
    char nome[20];
    int habilidade;
    int energia;
    int sorte;
} Personagem;

typedef struct {
    char nome[20];
    int habilidade;
    int energia;
} Criatura;

typedef struct {
    char texto[1000];
    int concluido;
    Criatura criatura;
} Desafio;

#endif // PERSONAGENS_H_INCLUDED
