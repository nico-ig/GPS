#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>
#include <getopt.h>
#include <string.h>

#include "interface.h"
#include "dir.h"
#include "bike.h"
#include "utils.h"

/* Main recebe como parametro o dir com os logs */
int main(int argc, char **argv)
{
  int opcao, opcao_menu;
  char *nome_arq_log;      
  t_bike *T_bike;

  /* N sei se ta bom o tamanho */
  char linha[TAM_LINHA + 1];

  DIR *d_log;                        /* Diretorio de logs */
  FILE *f_log;                       /* Arquivo de log */
  struct dirent *s_log;              /* Stream de logs */    

  /* Unica opcao de chamada é com -d */
  switch ( opcao = getopt(argc, argv, "d:") ) 
  {
    case 'd':
      printf("\nPrograma em execução...\n");
      break;
    
    default:
      perror("Chame o programa com gps -d <caminho_do_arq_log>.");
      return 1;
  }

  T_bike = NULL;
  d_log = opendir(argv[2]);

  while ( (s_log = readdir(d_log)) )
  {
    /* Lê apenas arquivos regulares */
    if ( s_log->d_type == DT_REG )
    {  
      nome_arq_log = nomeArq(argv[2], s_log->d_name);

      /* Abre o arquivo de log para leitura */
      if ( ! (f_log = fopen(nome_arq_log, "r")) )
      { 
        perror("Falha ao abrir o log");
        return 1;
      }

      fgets(linha, TAM_LINHA, f_log);
      linha [ strcmp(linha, "\n") ] = '\0';
     
      char *tmp = selecionaDado(linha, 1);
      /* Ve se tem a linha para o nome da bike */
      if ( ! (strcmp(tmp, "Gear:")) )
        insereBike(&T_bike, selecionaDado(linha, 2));
      else
        fprintf(stderr, "Faltando nome da bicicleta no log %s\n", s_log->d_name);

      fclose(f_log);
      free(nome_arq_log);
    }
  }

  imprimeBike(T_bike);

  destroiArvoreBike(T_bike);
  closedir(d_log);
  free(s_log);

  /* imprimeMenu(); */

  /*  while ( 1 )
  {
    switch (opcao_menu = opcaoMenu())
    {
      case 0:
        closedir(d_log);
	free(arq_log);
        printf("Programa encerrado\n");
        return 0;

      default:
        printf("Opcao invalida\n");
        break;  
    }
  }
  */
  return 0;
}

/* 
 */
