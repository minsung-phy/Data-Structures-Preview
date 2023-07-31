//
//  main.c
//  LinkedList3
//
//  Created by 이민성 on 2023/07/31.
//

#include <stdio.h>
#include <stdlib.h>

struct listNode {
    char data;
    struct listNode *link;
};

struct listNode *head;

int find(int key);
int length(void);
void printList(void);

int main(void) {
    struct listNode *node, *prevNode = NULL;
    int i;
    
    for (i = 0; i <= 100; i += 10)
    {
        node = malloc(sizeof(*node));
        node->data = i;
        node->link = NULL;
        if (prevNode == NULL)
            head = node;
        else
            prevNode->link = node;
        prevNode = node;
    }
    
    printList();
    printf("result of finding %d: %d\n", 30, find(30));
    printf("number of integers in the list: %d\n", length());
    
    return 0;
}


int find(int key)
{
    struct listNode * curr = head;
    int i = 0;
    while (curr)
    {
        if (curr->data == key)
            return i;
        i++;
        curr = curr->link;
    }
    return -1;
}

int length(void)
{
    struct listNode * curr = head;
    int i = 0;
    while (curr)
    {
        i++;
        curr = curr->link;
    }
    return i;
}

void printList(void)
{
    struct listNode * curr = head;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}
