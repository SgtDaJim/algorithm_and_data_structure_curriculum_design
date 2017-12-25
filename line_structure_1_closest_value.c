//
// Created by Jim on 2017/12/20.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE (0)
#define FALSE (-1)
typedef int STATUS;

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

// 初始化链表
List *init_list();
// 结点前置插入
STATUS insert_pre_node(int data, List *list, Node *node);
// 结点后置插入
STATUS insert_next_node(int data, List *list, Node *node);
// 增加结点
STATUS add_node(int data, List *list);
// 删除结点
STATUS remove_node(List *list, Node *node);
// 删除链表
STATUS destory_list(List *list);
// 复制出一条从小到大排序的链表
STATUS sort_list(List *list_a, List *list_b);


int main(void)
{
    List *list_a = init_list(); // 链表a
    List *list_b = init_list(); // 从大到小排序链表a
    int data;
    Node *p_temp;

    // 输入链表
    printf("Insert your number. Enter 0 to finish.\n");
    scanf("%d", &data);
    getchar(); // Eat the Enter
    while(data != 0)
    {
        if(add_node(data, list_a) == FALSE)
        {
            printf("Add node failed. Exit.");
            return FALSE;
        }
        printf("Insert your number. Enter 0 to finish.\n");
        scanf("%d", &data);
        getchar(); // Eat the Enter
    }

    // 遍历输出一次链表
    printf("Walking the list.\n");
    p_temp = list_a->head;
    while(p_temp != NULL)
    {
        printf("%d ", p_temp->data);
        p_temp = p_temp->next;
    }

    // 从小到大排序list_a并获得副本
    if (sort_list(list_a, list_b) == FALSE)
    {
        printf("Sorting list failed. Exit.");
        return FALSE;
    }

    // 遍历输出一次已排序链表
    printf("Walking the sorted list.\n");
    p_temp = list_b->head;
    while(p_temp != NULL)
    {
        printf("%d ", p_temp->data);
        p_temp = p_temp->next;
    }

    // 主算法：计算最近值
    int closest_value[list_a->size+1];
    closest_value[0] = -1; //占位
    closest_value[1] = 0; // 规定C1为0
    p_temp = list_a->tail;
    Node *p_walk = list_b->head;
    int i = list_a->size;
    int pre_diff;
    int next_diff;
    while (p_temp->pre != NULL)
    {
        while (p_walk != NULL && p_walk->data != p_temp->data)
        {
            p_walk = p_walk->next;
        }

        if (p_walk->pre == NULL)
        {
            closest_value[i] = abs(p_walk->data - p_walk->next->data);
        }
        else if (p_walk->next == NULL)
        {
            closest_value[i] = abs(p_walk->data - p_walk->pre->data);
        }
        else
        {
            pre_diff = abs(p_walk->data - p_walk->pre->data);
            next_diff = abs(p_walk->data - p_walk->next->data);
            closest_value[i] = pre_diff > next_diff ? next_diff : pre_diff;
        }
        if (remove_node(list_b, p_walk) == FALSE)
        {
            printf("Removing node failed. Exit.");
            return FALSE;
        }
        p_temp = p_temp->pre;
        p_walk = list_b->head;
        i--;
    }

    printf("Closest value result:\n");
    for (int j = 0; j < list_a->size+1; ++j) {
        printf("%d ", closest_value[j]);
    }

    destory_list(list_a);
    destory_list(list_b);

    return TRUE;
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

        if(node->pre == NULL)
        {
            list->head = new_node;
        }
        else
        {
            node->pre->next = new_node;
        }

        node->pre = new_node;
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

STATUS add_node(int data, List *list)
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
        new_node->pre = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    return TRUE;
}

STATUS sort_list(List *list_a, List *list_b)
{
    Node *p_temp = list_a->head;
    Node *p_walk;
    if (list_a == NULL || list_b == NULL)
    {
        return FALSE;
    }

    if (add_node(p_temp->data, list_b) == FALSE)
    {
        return FALSE;
    }

    p_temp = p_temp->next;

    while (p_temp != NULL)
    {
        p_walk = list_b->head;
        while(1)
        {
            if (p_walk == NULL)
            {
                if (add_node(p_temp->data, list_b) == FALSE)
                {
                    return FALSE;
                }
                else
                {
                    break;
                }
            }
            else if(p_temp->data >= p_walk->data)
            {
                p_walk = p_walk->next;
            }
            else
            {
                if(insert_pre_node(p_temp->data, list_b, p_walk) == FALSE)
                {
                    return FALSE;
                }
                else
                {
                    break;
                }
            }
        }
        p_temp = p_temp->next;
    }

    return TRUE;

}

STATUS remove_node(List *list, Node *node)
{
    if (list == NULL)
    {
        return FALSE;
    }

    if (list->head == node)
    {
        list->head = list->head->next;
        node->next->pre = NULL;
    }
    else if (list->tail == node)
    {
        list->tail = list->tail->pre;
        node->pre->next = NULL;
    }
    else
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    list->size--;

    free(node);

    return TRUE;
}

