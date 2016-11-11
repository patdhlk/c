//
// Created by patrick on 09.11.2016.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

struct ListNode{
    int id;
    char *name;
    struct ListNode *next;
};

typedef struct ListNode *Node;

extern Node CreateNode(int id, const char *name);
extern void FreeNode(Node node);
extern void Prepend(Node *head, Node node);
extern void Append(Node *head, Node node);
extern int Insert(Node *head, Node node, int pos);
extern Node Find(Node head, int id, const char *name);
extern void Remove(Node *head, Node node);
extern void Print(Node node);
extern void PrintList(Node head);
extern void Clear(Node head);

#ifdef _CH_
#pragma importf <list.c>
#endif

#endif //LIST_LIST_H
