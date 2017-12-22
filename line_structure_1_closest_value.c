//
// Created by Jim on 2017/12/20.
//
#include <stdio.h>
#include <stdlib.h>

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
} List;

List *init_list();
int insert_pre_node(int data, List *list, Node *node);
int insert_next_node(int data, List *list, Node *node);
int remove_node(List *list, Node *node);
int destory_list(List *list);
int sort_list(List *list);


int main(void)
{
    List *list_a = init_list();
    int data;
    do
    {
        printf("Insert your number. Enter '@' to finish.\n");
        scanf("%d", &data);
        getchar(); // Eat the Enter
    }while(data != '@');
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

int insert_pre_node(int data, List *list, Node *node)
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

        if(node->pre == NULL)
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

int insert_next_node(int data, List *list, Node *node)
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

//int sort_list(List *list)
//{
//
//}


