#include "array_helpers4.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int array_from_file(int array[],unsigned int max_size,const char *filepath)
{
    FILE *a;
    unsigned int tam;
    a = fopen(filepath,"r");
    assert(max_size >= tam);
    fscanf(a,"%u",&tam);
    for (unsigned int i = 0; i < tam; i++) {
      fscanf(a,"%d",&array[i]);
    }
    fclose(a);
    return tam;
}
void array_dump(int a[], unsigned int length)
{
    printf("[");
    for (unsigned int i = 0; i < length; i++) {
      printf("%d,", a[i]);
    }
    printf("\b]\n");
}

bool array_is_sorted(int a[], unsigned int length)
{
  bool arreglado = true;
  unsigned int i = 0;
  while ((i != length-1) && arreglado) {
      if (a[i] <= a[i + 1]) {
        arreglado = true;
      }else{
        arreglado = false;
      }
      i++;
  }
  return arreglado;
}
