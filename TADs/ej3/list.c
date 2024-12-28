#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "./list.h"

struct s_node_t
{
    elem value;
    struct s_node_t *next;
};

list empty(){
    list l = NULL;
    return l;
}

void addl(elem e, list L){
    struct s_node_t *p = malloc(sizeof(struct s_node_t));
    p->value = e;
    p->next = L;
    L = p;
}

list destroy(list L){
    if (L != NULL)
    {
        list p,q;
        p = L;
        q = p->next;
        while (p != NULL)
        {
            free(p);
            p = q;
            if (p!=NULL)
            {
                q = p->next;
            }
        }
        L = p;
    }
    return L;
}

bool is_empty(list L){
    return L == NULL;
}

elem head(list L){
    assert(!is_empty(L));
    return  L->value;
}

list tail(list L){
    assert(!is_empty(L));
    return L->next;
}

list addr(list L, elem e){
    list q = malloc(sizeof(struct s_node_t));
    q->value = e;
    q->next = NULL;
    if (!is_empty(L))
    {
        list p = L;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
    else
    {
        L = q;
    }
    return L;
}

unsigned int length(list L){
    list p = malloc(sizeof(struct s_node_t));
    unsigned int n = 0;
    p = L;
    while (p != NULL)
    {
        n = n + 1;
        p = p->next;
    }
    return n;
}

void concat(list L, list L1){
    list p,q;
    q = L1;
    if (!is_empty(L))
    {
        p = L;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
    else
    {
        L = q;            
    }
}

elem index(list L,unsigned int n){
    assert(n < length(L));
    list p = L;
    elem e;
    unsigned int i = 0;
    while (n > i)
    {
        p = p->next;
        i++;
    }
    e = p->value;
    return e;
}

void take(list L,unsigned int n){
    list p, q;
    unsigned int i = 0;
    p = L;
    while (n > i)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = NULL;
    free(q);
}

void drop(list L,unsigned int n){
    list p;
    unsigned int i = 0;
    while (n > i && L != NULL)
    {
        p = L;
        L = p->next;
        free(p);
        i++;
    }
}

list copy_list(list L){
    list p, L0;
    L0 = empty();
    p = L;
    while (p!= NULL)
    {
        addr(L0, p->value);
    }
    return L0;
}
