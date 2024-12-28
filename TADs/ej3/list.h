#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
typedef int elem;
typedef struct s_node_t * list;
//constructores
list empty();

void addl(elem e, list L);

//desturctor
list destroy(list L);

//operaciones
bool is_empty(list L);

elem head(list L);

list tail(list L);

list addr(list L, elem e);

unsigned int length(list L);

void concat(list L, list L1);

elem index(list L, unsigned int n);

void take(list L, unsigned int n);

void drop(list L, unsigned int n);

list copy_list(list L);
#endif