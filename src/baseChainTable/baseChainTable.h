//
// Created by 钱亮 on 2024/10/28
//

#include <vector>

#ifndef BASECHAINTABLE_H
#define BASECHAINTABLE_H

class node
{
    public:
        int data;
        node *next;
};

class list
{
    public:
        node *head;
        int size;
};

list* list_init();

void list_insert(list *L, int pos, int data);

void list_remove_pos(list *L, int pos);

void list_print(list *L);

#endif // BASECHAINTABLE_H