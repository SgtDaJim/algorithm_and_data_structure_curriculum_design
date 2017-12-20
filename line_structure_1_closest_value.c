//
// Created by Jim on 2017/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATUS int;
#define TRUE 0;
#define FALSE -1;

typedef struct DoublyLinkedListNode
{
    int data;
    struct DoublyLinkedListNode *pre;
    struct DoublyLinkedListNode *next;
} Node;

typedef struct DoublyLinkedList
{
    int size;
    struct DoublyLinkedListNode *head;
    struct DoublyLinkedListNode *tail;
}List;

List *init_list();
STATUS insert_pre_node(int data, List *list, Node *node);
STATUS insert_next_node(int data, List *list, Node *node);
STATUS remove_node(List *list, Node *node);
STATUS destory_list(List *list);
STATUS sort_list(List *list);
STATUS create_node(Node *node);


int main(void)
{
    printf("Hello!");
}

List * init_list()
{
    List *list = NULL;
    list = (List *)malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int destory_list(List *list)
{
    if(list == NULL)
    {
        return FALSE;
    }
    if(list->size == 0)
    {
        free(list);
        return TRUE;
    }
    Node *tmp = NULL;
    for(int i = 0; i >= 0; i--)
    {
        tmp = list->tail;
        list->tail = list->tail->pre;
        free(tmp);
        tmp = NULL;
        list->size--;
    }
    free(list);
    return TRUE;
}

STATUS insert_pre_node(int data, List *list, Node *node)
{
    if(list == NULL)
    {
        return FALSE;
    }
    Node *new_node = NULL;
    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = 

    if(list->size == 0)
    {
        list->head = node;
        list->tail = node;
        list->size++;
        return TRUE;
    }
    if()
}
