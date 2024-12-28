#include <assert.h>
#include <stdlib.h>    
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static key_t direccion_minima(dict_t d){
    key_t xd;
    xd = d->key;
    if (d->left != NULL)
    {
        xd = (!key_less(xd, direccion_minima(d->left)) || key_eq(xd, direccion_minima(d->left))) ? xd : direccion_minima(d->left); 
    }
    if (d->right != NULL)
    {
        xd = (!key_less(xd, direccion_minima(d->right)) || key_eq(xd, direccion_minima(d->right))) ? xd : direccion_minima(d->right); 
    }
    return xd;
}

static key_t direccion_maxima(dict_t d){
    key_t lol;
    lol = d->key;
    if (d->left != NULL)
    {
        lol = (!key_less(lol, direccion_maxima(d->left)) || key_eq(lol, direccion_maxima(d->left))) ? lol : direccion_maxima(d->left);
    }
    if (d->right != NULL)
    {
       lol = (!key_less(lol, direccion_maxima(d->right)) || key_eq(lol, direccion_maxima(d->right))) ? lol : direccion_maxima(d->right); 
    }
    return lol;
}

static bool invrep(dict_t d) {
    return d == NULL || ((d->left == NULL || (!(key_less(d->key, direccion_minima(d->left))) && invrep(d->left))) && ((d->right == NULL) || (!(key_less(d->key, direccion_maxima(d->right))) && invrep(d->right))));
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict));
    if (dict == NULL)
    {
        dict->key = key_clone(word);
        dict->left = NULL;
        dict->right = NULL;
        dict->value = value_clone(def);    
    }
    else if (key_less(word, dict->key))
    {
        dict->left = dict_add(dict->left, word, def);
    }
    else if (key_less(dict->key,word))
    {
        dict->right = dict_add(dict->right, word, def);   
    }
    else
    {
        value_t temporal;
        temporal = dict->value;
        dict->value = value_clone(def);
        key_destroy(temporal);
    }
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    assert(invrep(dict));
    key_t def=NULL;
    while (dict != NULL && !key_eq(word,dict->key))
    {
        if (key_less(word, dict->key))
        {
            dict = dict->left;
        }
        else
        {
            dict = dict->right;
        }
    }
    if (dict != NULL)
    {
        def = value_clone(dict->key);
    }
   return def;
}

bool dict_exists(dict_t dict, key_t word) {
    assert(invrep(dict));
    bool existe = false;
    while (!existe && dict != NULL)
    {
        if (key_less(word, dict->key))
        {
            dict = dict->left;
        }else if (!key_eq(word, dict->key))
        {
            dict = dict->right;
        }
        else
        {
            existe = true;
        }
    }
    return existe;
}

unsigned int dict_length(dict_t dict) {
    assert(invrep(dict));
    unsigned int length = 0;
    while (dict != NULL)
    {
        length = 1 + dict_length(dict->left) + dict_length(dict->right);
    }
    return length;
}

static struct _node_t *node_destroy(struct _node_t *node){
      if(node != NULL) {
        key_destroy(node->key);
        key_destroy(node->value);
        free(node);
        node = NULL;
      }
      return node;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert(invrep(dict));
    struct _node_t *aux;
    if (dict != NULL)
    {
        if (key_less(word, dict->key))
        {
            dict->left = dict_remove(dict, word);
        }
        else if (!(key_less(word, dict->key) || key_eq(word, dict->key))){
            dict->right = dict_remove(dict, word);
        }
        else if (dict->right == NULL)
        {
            aux = dict;
            dict = dict->left;
            node_destroy(aux);
        }
        else if (dict->left == NULL)
        {
            aux = dict;
            dict = dict->right;
            node_destroy(aux);
        }
        else
        {
          struct _node_t **candidato;
          candidato = &dict->right;
          while ((*candidato)->left != NULL)
          {
              candidato = &((*candidato)->left);
          }
            aux = (*candidato)->right;
            (*candidato)->left = (dict)->left;
            (*candidato)->right = (dict)->right;
            node_destroy(dict);
            dict = *candidato;
            *candidato=aux; 
        }
    }
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    assert(invrep(dict));
    if (dict != NULL)
    {   
        dict_remove_all(dict->right);
        dict_remove_all(dict->left);
        key_destroy(dict->key);
        key_destroy(dict->value);
        free(dict);
        dict = NULL;
    }
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    if (dict != NULL)
    {
        dict_dump(dict->left, file);
        key_dump(dict->key, file);
        fprintf(file, ":");
        key_dump(dict->value, file);
        fprintf(file,"\n");
        dict_dump(dict->right, file);
    }
}

dict_t dict_destroy(dict_t dict) {
    assert(invrep(dict));
    return  dict = dict_remove_all(dict);
}

