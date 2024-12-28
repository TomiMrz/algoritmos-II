#include <stdlib.h>
#include <stdio.h>   
#include "pair.h" 

pair_t pair_new(int x, int y){
    struct s_pair_t par ={x , y};
    return par;
}

int pair_first(pair_t p){
    return p.fst;
}

int pair_second(pair_t p){
    return p.snd; 
}

pair_t pair_swapped(pair_t p){
    int aux;
    aux = p.fst;
    p.fst = p.snd;
    p.snd = aux;
    return p;
}

pair_t pair_destroy(pair_t p){
    return p;
}