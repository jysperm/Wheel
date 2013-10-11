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
}LIST;

LIST *list_create();

NODE *list_add(LIST *list, void *data, unsigned int where);
NODE *list_add_from_head(LIST *list,void *data);
NODE *list_add_from_tail(LIST *list,void *data);
NODE *list_find(LIST *list, void *data);
NODE *list_at(LIST *list, int index);

void list_node_delete(LIST *list, NODE *node);
void list_delete(LIST *list);
#ifdef	__cplusplus
}
#endif

#endif	/* LINKLIST_H */

