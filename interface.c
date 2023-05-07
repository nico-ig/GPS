#include <stdio.h>

#include "interface.h"

void imprimeMenu()
{
  printf("0: Encerra\n");
  printf("1: Bicicletas encontradas\n");
  printf("2: Listas de atividades de uma bicicleta\n");
  printf("3: Lista de atividades por data\n");
  printf("4: Lista de atividades por distancia\n");
  printf("5: Lista de atividades por subida acumulada\n");
  printf("6: Histograma\n");
  printf("7: Histograma em grafico\n\n");
}

int opcaoMenu()
{
  int opcao;

  printf("\nDigite a opcao desejada: ");
  scanf("%d", &opcao);
  printf("\n");

  return opcao;
}
