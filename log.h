/* Struct que define cada log */
typedef struct log
{
  char* nome;
  time_t data;

  /* Ponteiros para a arvore de datas */
  struct log *pai_data, *dir_data, *esq_data;

} t_log;

t_log *insereLogData(t_log **no, time_t data);

void destroiArvoreLog(t_log *no);

void imprimeLogData(t_log *no);
