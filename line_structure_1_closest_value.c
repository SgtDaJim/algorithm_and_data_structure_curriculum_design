//
// Created by Jim on 2017/12/20.
//
#include <stdio.h>
#include <stdlib.h>

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

STATUS destory_list(List *list)
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
    new_node->data = data;
    new_node->pre = NULL;
    new_node->next = NULL;

    if(list->size == 0)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        new_node->next = node;
        new_node->pre = node->pre;

        if(list->pre == NULL)
        {
            list->head = new_node;
        }
        else
        {
            node->pre->next = new_node;
        }

        node->pre = node;
    }
    list->size++;
    return TRUE;
}

STATUS insert_next_node(int data, List *list, Node *node)
{
    if(list == NULL)
    {
        return FALSE;
    }

    Node *new_node = NULL;
    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->pre = NULL;
    new_node->next = NULL;

    if(list->size == 0)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        if(node->next == NULL)
        {
            list->tail = new_node;
        }
        else
        {
            node->next->pre = new_node;
        }
        new_node->next = node->next;
        new_node->pre = node;

        node->next = new_node;
    }

    list->size++;
    return TRUE;

}

STATUS sort_list(List *list)
{

}


