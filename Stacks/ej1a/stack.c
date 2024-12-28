#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack
{
    stack_elem elem;
    struct _s_stack *next;
};

stack stack_empty(){
    stack s;
    s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack p = malloc(sizeof(struct _s_stack));
    p->elem = e;
    p->next = s;
    s = p;
    return s; 
}

stack stack_pop(stack s){
    assert(s != NULL);
    struct _s_stack *lol = s;
    s = s->next;
    free(lol);
    return s;
}

unsigned int stack_size(stack s){
    unsigned int l = 0;
    stack p;
    p = s;
    while (p != NULL)
    {
        p = p->next;
        l++;
    }
    return l;
}

stack_elem stack_top(stack s){
    return s->elem;
}

bool stack_is_empty(stack s){
    return s == NULL;
}

stack_elem *stack_to_array(stack s){
    unsigned int len = stack_size(s);
    stack_elem *a = malloc(len*sizeof(struct _s_stack));
    for (unsigned int i = 0; s!=NULL; i++)
    {
        a[i] = stack_top(s);
        s = stack_pop(s);
    }
    return a;
}

stack stack_destroy(stack s){
    if (s != NULL)
    {
        stack q, p;
        p = s;
        q = p->next;
        while (p != NULL)
        {
            free(p);
            p = q;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        s = p;
    }
    return s;
}
