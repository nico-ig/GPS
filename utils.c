#include <string.h>

char *selecionaDado(char *linha, int pos)
{
    char *tmp = strtok(linha, " ");
    
    switch (pos)
    {
        case 1:
            return tmp;

        case 2:
            return strtok(NULL, "\0");
        
        default:
            return "Posicao invalida";
    }

}
