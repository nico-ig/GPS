/* Struct que define cada bicicleta */
typedef struct bike
{
    char *nome;
    struct bike *pai, *dir, *esq;  
} t_bike;

char *nomeBike(FILE *f_log);

/* Cria um no do tipo t_bike e o insere na arvore
 * Retorna o no em caso de sucesso e NULL em caso de falha */
t_bike *insereBike(t_bike **no, char *nome);

/* Libera a memoria alocada pela arvore */
void destroiArvoreBike(t_bike *no);

/* Imprime as bicicletas em ordem crescente */
void imprimeBike(t_bike *no);
