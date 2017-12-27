# Projeto RPG - RU
Projeto da disciplina de Introdução à Programação
## Grupo:
  * Felipe Vieira
  * Pedro Sales
  * Washington Almeida

## 1. Personagem
  Os atributos do personagem são **HABILIDADE**, **ENERGIA**, e **SORTE**. E serão representados em uma estrutura ([struct](https://www.ime.usp.br/~pf/algoritmos/aulas/stru.html)).
  ```c
  /* Definição da estrutura Personagem */
  typedef struct {
    int habilidade;
    int energia;
    int sorte;
  } Personagem;
  
  Personagem p; //Variável p do tipo Personagem
  p.habilidade = dado() + 6; // atribuindo valor à habilidade do personagem
  ```
## 1.1. Definição dos atributos do personagem
  ```c
  p.habilidade = dado() + 6;
  p.energia = dado() + dado() + 12;
  p.sorte = dado() + 6;
  ```
## 2. Funções necessárias para o jogo
  * #### int dado()
    Descrição: Quando chamada deve retornar um valor aleatório que varia de 1 a 6.
    ```c
    int dado() {
        return rand() % 6 + 1;
    }
    ```
