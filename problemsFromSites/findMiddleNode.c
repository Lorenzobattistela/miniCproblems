//find middle node of the linked list and return the rest of the list starting by middle node
//leetcode

#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *middleNode(struct ListNode *head)
{
    int counter = 0;
    struct ListNode *current = head;
    while (current != NULL)
    {
        current = current->next;
        counter++;
    }

    int desired = 0;
    if (counter % 2 == 0)
    {
        desired = counter / 2;
    }

    desired = (counter / 2) + 1;

    int contador = 1;
    current = head;
    while (contador < desired)
    {
        current = current->next;
        contador++;
    }

    struct ListNode *list = malloc(sizeof(list));
    list = current;

    return list;
}