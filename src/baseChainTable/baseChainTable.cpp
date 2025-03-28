#include <cstddef>
#include <iostream>
using namespace std;

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


list* list_init()
{
    list *L=new list;
    L->size=0;
    L->head->data=NULL;
    L->head->next=NULL;
    return L;
}

void list_insert(list *L, int pos, int data)
{
    if (L==NULL)
    {
        pos=0;
    }
    node *new_node=new node;
    new_node->data=data;
    new_node->next=NULL;

    node *pos_node=L->head;

    for (int i = 0; i < pos; i++)
    {
        /* code */
        pos_node=pos_node->next;
    }
    // 将new_node插入到pos_node前面
    new_node->next=pos_node->next;
    pos_node->next=new_node;
    L->size++;
}

void list_remove_pos(list *L, int pos)
{
    if (L==NULL)
    {
        return;
    }
    node *pos_node=L->head;
    for (int i = 0; i < pos; i++)
    {
        pos_node=pos_node->next;
    }
    pos_node->next=pos_node->next->next;
    L->size--;
}

void list_print(list *L)
{
    if (L->size==0)
    {
        cout<<"链表中没有数据"<<endl;
        return;
    }

    node *pcurrent=L->head->next;
    while (pcurrent!=NULL)
    {
        cout<<pcurrent->data<<"\t";
        pcurrent=pcurrent->next;
    }
    cout<<endl;
    
}
