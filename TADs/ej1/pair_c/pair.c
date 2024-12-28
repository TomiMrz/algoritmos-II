#include <stdlib.h>  
#include <stdio.h>     
#include "pair.h"  

struct s_pair_t{
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
   pair_t par = malloc(sizeof(pair_t));
   par->fst = x;
   par->snd = y;
   return par;
}

int pair_first(pair_t p){
    return p->fst;
}

int pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    pair_t l = malloc(sizeof(pair_t));
    l->fst = p->snd;
    l->snd = p->fst;
    return l;
}

pair_t pair_destroy(pair_t p){
    return p;
}