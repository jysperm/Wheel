/* 
 * File:   linklist.h
 * Author: YuDong
 *
 * Created on 2013年10月11日, 下午12:31
 */

#ifndef LINKLIST_H
#define	LINKLIST_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct node{
    void *data;
    struct node *next;
}NODE;

typedef struct list{
    NODE *head;
    NODE *tail;  
    unsigned int length;
}LIST;

LIST *list_create();

NODE *node_create(void *data);
NODE *list_get_node_by_index(LIST *list, int index);

int list_index(LIST *list, NODE *node);
int list_index_by_data(LIST *list, void *data);

void list_append(LIST *list, void *data);
void list_insert_by_index(LIST *list, void *data, int index);
void list_insert_by_node(LIST *list, void *data, NODE *node);


#ifdef	__cplusplus
}
#endif

#endif	/* LINKLIST_H */

