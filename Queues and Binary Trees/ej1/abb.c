#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool invrep(abb tree) {
    return tree == NULL ||
        ((tree->left == NULL || (tree->elem > abb_max(tree->left) && invrep(tree->left))) &&
        (tree->right == NULL || (tree->elem < abb_min(tree->right) && invrep(tree->right))));
}

static struct _s_abb *node_destroy(struct _s_abb *node){
      if(node != NULL) {
        free(node);
        node = NULL;
      }
      return node;
}

abb abb_empty(void) {
    return NULL;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree == NULL)
    {
        tree = malloc(sizeof(struct _s_abb));
        tree->elem=e;
        tree->left=NULL;
        tree->right=NULL;
    }
    else if (tree->elem > e)
    {
        tree->left = abb_add(tree->left,e);
    }
    else if (e > tree->elem)
    {
        tree->right = abb_add(tree->right,e);
    }
    assert(invrep(tree));
    assert(abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return tree == NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    struct _s_abb *aux = tree;
    while (!exists && aux != NULL ){ 
        if (aux->elem > e)
        {
            aux = aux->left; 
        }
        else if (aux->elem > e)
        {
            aux = aux->right;
        }
        else
        {
            exists = true;
        }
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree != NULL)
    {
        length = 1 + abb_length(tree->left) + abb_length(tree->right);
    }
    
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    struct _s_abb **aBorrar = NULL;
    struct _s_abb **candidato;
    struct _s_abb *aux;
    bool Verif = true;
    if(tree != NULL) {
      aux = tree;
      while(Verif) {
        if(e < aux->elem) {
          aBorrar = &aux->left;
          aux = aux->left; 
        }
        else if(e > aux->elem) {
          aBorrar = &aux->right;
          aux = aux->right; 
        } else {
          Verif = false;
        }
      }
      if(aBorrar == NULL) {
        aBorrar = &tree;
      }
      candidato = &aux->right;
      aux = aux->right;
      if(aux != NULL) {

        while(aux->left != NULL) {
          candidato = &aux->left;
          aux = aux->left;
        }
        *candidato = aux->right;
      }
      if(aux != NULL) {
        aux->left = (*aBorrar)->left;
        aux->right = (*aBorrar)->right;
      } 
      else {
        aux = (*aBorrar)->left;
      }
      node_destroy(*aBorrar);
      *aBorrar = aux;
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    while (tree->right != NULL)
    { 
        tree = tree->right;  
    }
    max_e = tree->elem;
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    min_e = tree->elem;
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}
// c)
void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree != NULL)
    {
        abb_destroy(tree->right);
        abb_destroy(tree->left);
        free(tree);
        tree = NULL;
    }
    assert(tree == NULL);
    return tree;
}

