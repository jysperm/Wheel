#include <stdlib.h>
#include "linklist.h"



LIST *list_create()
{
    LIST *new_list;
    if(!(new_list = malloc(sizeof(LIST))))
        return NULL;
    
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->length = 0;
    
    return new_list;
}

NODE *node_create(void *data)
{
    NODE *node;
    if(!(node = (NODE *)malloc(sizeof(NODE))))
        return NULL;
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

int list_index(LIST *list, NODE *node)
{
    int i = 0;
    NODE *iter = list->head;
    for( ; iter; iter = iter->next, i++)
        if(iter == node) return i;
    
    return -1;
}

int list_index_by_data(LIST *list, void *data)
{
    int i = 0;
    NODE *iter = list->head;
    for( ; iter; iter = iter->next, i++)
        if(iter->data == data) return i;
    
    return -1;
}

NODE *list_get_node_by_index(LIST *list, int index)
{
    int i=0;
    NODE *iter = list->head;
    for( ; iter ; iter = iter->next, i++)
        if(i == index) return iter;
    return NULL;
      
}

void list_append(LIST *list, void *data)
{
    NODE *head = list->head, *tail = list->tail;
    NODE *node = node_create(data);
    
    if(head)
    {
        if(!tail) return NULL;
        tail->next = node;
        tail = node;
    }else{
        head = node;
        tail = node;
    }
    list->length ++;
}


void list_insert_by_index(LIST *list, void *data, int index)
{
    NODE *pos = list_get_node_by_index(list,index);
    list_insert_by_node(list,data,pos);
}

void list_insert_by_node(LIST *list, void *data, NODE *node)
{
    NODE *new_node = node_create(data);
    NODE *iter = list->head;

    for( ; iter; iter = iter->next)
    {
        if(iter == node)
        {
            new_node->next = iter->next;
            iter->next = new_node;
            list->length++;
            return;
        }
    }
}