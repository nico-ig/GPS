#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>

#include "dir.h"

char *nomeArq(char *caminho, char *nome)
{
  int tam = strlen(caminho) + strlen(nome);
  char *nome_arq = malloc(sizeof(char) * tam + 2);
 
  strcpy(nome_arq, caminho);
  strcat(nome_arq, "/");
  strcat(nome_arq, nome);

  return nome_arq;
}
