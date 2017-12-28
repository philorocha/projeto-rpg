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
  * #### void batalha(Personagem *p, Personagem personagem, Criatura criatura); INCOMPLETO!!!!
    Descrição: O procedimento para batalha recebe três argumentos. Um ponteiro *p do tipo Personagem (struct), um struct Personagem e um struct Criatura.
    ```c
    void batalha(Personagem *p, Personagem personagem, Criatura criatura) {
      criatura.habilidade += dado() + dado(); //Ataque criatura = habilidade + dado + dado
      personagem.habilidade += dado() + dado(); //Ataque personagem = habilidade + dado + dado

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
    ```
