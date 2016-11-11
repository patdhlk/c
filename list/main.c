#include <stdio.h>
#include "list.h"

int main() {
    Node head, node;

    Node n1 = CreateNode(1, "A"),
         n2 = CreateNode(2, "B"),
         n3 = CreateNode(3, "C"),
         n4 = CreateNode(4, "D");

    head = NULL;
    Prepend(&head, n1);
    printf("List with one element: \n");
    PrintList(head);
    Prepend(&head, n2);
    printf("List with two elements: \n");
    PrintList(head);
    Append(&head, n3);
    printf("List with three elements: \n");
    PrintList(head);
    Insert(&head, n4, 2);
    printf("List with four elements: \n");
    PrintList(head);

    node = Find(head, 1, "A");
    Remove(&head, node);
    printf("List without A\n");
    PrintList(head);
    Clear(head);

    return 0;
}