#include <stdio.h>
#include <stdbool.h>
#include "strfuncs.h"

size_t string_length(const char *str){
    size_t tam;
    tam = 0;
    while (str != NULL)
    {
        if (str[tam] == '\0')
        {
            break;
        }
        else
        {
            tam++;
        }
    }    
    return tam;
}

char *string_filter(const char *str, char c){
    size_t pro = string_length(str);
    char lol[pro];
    size_t j = 0;
    for (unsigned int i = 0; i < pro; i++)
    {
        if (str[i] != c)
        {
            lol[j] = str[i];
            j++;
        }
    }
    char *filtradou = malloc(sizeof(j+1));
    for (unsigned int l = 0; l < pro; l++)
    {
        filtradou[l] = lol[l];
    }
    return filtradou;   
}