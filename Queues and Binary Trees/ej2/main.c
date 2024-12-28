#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

int main(int argc,char *argv[])
{   
    if(argc < 3) {
    fprintf(stderr, "Missing parameters\n");
    exit(EXIT_FAILURE);
  } 
    char *palabra = argv[1];
    char *OtraPalabra = argv[2];
    string strnng = string_create(palabra);
    string strnng2 = string_create(OtraPalabra);
    if (string_less(strnng,strnng2))
    {
        printf("La primera palabra es mas grande\n");
    }
    else 
    {
        printf("La segunda palabra es mas grande\n");
    }
    if (string_eq(strnng,strnng2))
    {
        printf("Las palabras son iguales\n");
    }
    string_destroy(strnng);
    string_destroy(strnng2);
    return 0;
}
