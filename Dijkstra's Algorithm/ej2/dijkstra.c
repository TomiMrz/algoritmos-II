#include <assert.h>
#include <stdlib.h>

#include "cost.h"
#include "graph.h"
#include "mini_set.h"


cost_t *dijkstra(graph_t graph, vertex_t init) {
    cost_t *cost = calloc(graph_max_vertexs(graph),sizeof(cost_t));
    set No_Visitados = set_empty();
    vertex_t c;
    for (vertex_t i = 0; i < graph_max_vertexs(graph) ; i++)
    {
        No_Visitados =  set_add(No_Visitados,i);
        cost[i] =  graph_get_cost(graph,init,i);
    }
    //No_Visitados = set_elim(No_Visitados,init);
    while (!set_is_empty(No_Visitados))
    {
        cost_t min = cost[set_get(No_Visitados)];
        c = set_get(No_Visitados);
        for (vertex_t i = 0; i < graph_max_vertexs(graph); i++)
        {
            if (cost_lt(cost[i],min) && set_member(i,No_Visitados))
            {
                min = cost[i];
                c = i;
            }
        }
        No_Visitados = set_elim(No_Visitados,c);
        for (vertex_t j = 0; j < graph_max_vertexs(graph); j++)
        {
            if (cost_lt(cost_sum(cost[c], graph_get_cost(graph,c,j)),cost[j]) && set_member(j,No_Visitados))
            {
                cost[j] = cost_sum(cost[c], graph_get_cost(graph,c,j)); 
            }   
        }   
    }
    No_Visitados = set_destroy(No_Visitados);
    return cost;
}
