#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bike.h"
#include "utils.h"

void destroiNoBike(t_bike *no)
{
  free(no->nome);
  free(no);
}

t_bike *criaNoBike(t_bike **pai, char *chave)
{
    t_bike *no;

    if ( ! (no = malloc(sizeof(t_bike))) )
      return NULL;

    /* Inicia os ponteiros */
    no->nome = strdup(chave);
    no->esq = NULL;
    no->dir = NULL;
    no->pai = *pai;
    *pai = no;
    
    return no;
}

t_bike *insereBike(t_bike **no, char *nome)
{
  /* Se nao estiver na arvore cria o no */
  if ( ! *no )
    return criaNoBike(no, nome);
  
  /* Se o nome for maior insere na direita */
  else if ( strcmp((*no)->nome, nome) < 0 )
    return insereBike(&(*no)->dir, nome);

  /* Se o nome for menor insere na esquerda */
  else if ( strcmp((*no)->nome, nome) > 0 )
    return insereBike(&(*no)->esq, nome);

  /* Se for igual nao faz nada */
  return NULL;
}

void destroiArvoreBike(t_bike *no)
{
  /* Chegou na folha */
  if ( ! no )
    return;

  /* Libera as sub arvores */
  destroiArvoreBike(no->esq);
  destroiArvoreBike(no->dir);

  destroiNoBike(no);
 }

void imprimeBike(t_bike *no)
{
  /* Chegou na folha */
  if ( ! no )
    return;

  imprimeBike(no->esq);

  printf("%s\n", no->nome);

  imprimeBike(no->dir);
}

