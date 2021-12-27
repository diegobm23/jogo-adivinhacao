#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("\n\n");
  printf("          P  /_\\  P                              \n");
  printf("         /_\\_|_|_/_\\                            \n");
  printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
  printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
  printf("    |' '  |  |_|  |  ' '|                         \n");
  printf("    |_____| ' _ ' |_____|                         \n");
  printf("          \\__|_|__/                              \n");
  printf("\n\n");

  int segundos = time(0);
  srand(segundos);

  int numeroGrande = rand();

  int numeroSecreto = numeroGrande % 100;
  int chute;
  int acertou = 0;
  int tentativa = 1;
  int maxTentativas;
  double pontos = 1000.0;

  int nivel;
  printf("Escolha o nível de dificuldade?\n");
  printf("(1) Fácil (2) Médio (3) Difícil\n\n");
  scanf("%d", &nivel);

  switch (nivel) {
    case 1:
      maxTentativas = 20;
      break;
    case 2:
      maxTentativas = 15;
      break;
    default:
      maxTentativas = 6;
      break;
  }

  printf("Máximo de tentativas: %d\n", maxTentativas);

  for (int i = 1; i <= maxTentativas; i++) {
    printf("Tentativa %d.\n", tentativa);
    printf("Qual é o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi: %d\n", chute);

    if (chute < 0) {
      printf("Informe um número positivo.\n");
      continue;
    }

    acertou = (chute == numeroSecreto);
    int maior = (chute > numeroSecreto);

    if (acertou) {
      break;
    }

    else if (maior) {
      printf("Seu chute foi maior que o número secreto.\n");
    }

    else {
      printf("Seu chute foi menor que o número secreto.\n");
    }

    tentativa++;

    double pontosPerdidos = abs(chute - numeroSecreto) / (double) 2;
    pontos = pontos - pontosPerdidos;
  }

  if (acertou) {

    printf("\n             OOOOOOOOOOO               \n");
    printf("         OOOOOOOOOOOOOOOOOOO           \n");
    printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
    printf("    OOOOOO      OOOOO      OOOOOO      \n");
    printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
    printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
    printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
    printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
    printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
    printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
    printf("         OOOOOO         OOOOOO         \n");
    printf("             OOOOOOOOOOOO              \n");
    printf("\n\n");

    printf("Fim do jogo.\n");
    printf("Você acertou em %d tentativas!\n", tentativa);
    printf("Total de pontos: %.2f", pontos);
  } else {
    printf("       \\|/ ____ \\|/    \n");
    printf("        @~/ ,. \\~@      \n");
    printf("       /_( \\__/ )_\\    \n");
    printf("          \\__U_/        \n");


    printf("Você perdeu. Tente de novo.");
  }

}
