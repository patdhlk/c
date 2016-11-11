#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

Node CreateNode(int id, const char *name){
    Node node;
    node = (Node) malloc(sizeof(struct ListNode));
    if(node == NULL){
        fprintf(stderr, "Error: not enough memory.\n");
        return NULL;
    }
    node->id = id;
    node->name = strdup(name);
    node->next = NULL;
    return node;
}

void FreeNode(Node node){
    if(node){
        if(node->name){
            free(node->name);
        }
        free(node);
    }
}

void Prepend(Node *head, Node node){
    node->next = *head;
    *head = node;
}

void Append(Node *head, Node node){
    Node tmp = *head;
    if(*head == NULL) { /*no node (empty)*/
        *head = node;
    }else{
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

int Insert(Node *head, Node node, int pos){
    int i = 0;
    /*tmp is the head*/
    Node tmp = *head;

    /*insert at the beginning of the list*/
    if(pos == 1){
        *head = node;
        (*head)->next = tmp;
        return 0;
    }
    /*get position*/
    while(tmp){
        /*invalid or matching position*/
        if(++i >= pos-1){
            break;
        }
        tmp = tmp->next;
    }
    if(i != pos-1){
        fprintf(stderr, "Error: can not insert at pos %d", pos);
        return -1;
    }
    /*update all links*/
    node->next = tmp->next;
    tmp->next = node;
    return 0;
}

Node Find(Node head, int id, const char *name){
    while(head != NULL && /*reached last element*/
            !(head->id == id &&
                    !strcmp(head->name, name))){
        head = head->next;
    }
    /*found it: return it*/
    return head;
}

void Remove(Node *head, Node node){
    Node tmp = *head;

    /*handle empty list*/
    if(*head == NULL){
        return;
    } else if (*head == node) {
        *head = (*head)->next;
        /*give memory back to its owner (free)*/
        FreeNode(node);
    } else {
        while(tmp->next){
            /*we found the node*/
            if(tmp->next == node){
                /*unlink it*/
                tmp->next = tmp->next->next;
                /*give memory back*/
                FreeNode(node);
                return;
            }
            tmp = tmp->next;
        }
    }
}

void Clear(Node head){
    Node node;

    while(head){
        node = head;
        head = head->next;
        FreeNode(node);
    }
}

void Print(Node node){
    if(node){
        printf("id = %d, name = %s\n", node->id, node->name);
    }
}

void PrintList(Node head){
    while(head){
        Print(head);
        head = head->next;
    }
}

