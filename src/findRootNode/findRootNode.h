#include <vector>
#ifndef FINDROOTNODE_H

typedef struct ListNode {
    int data;
    struct ListNode* left;
    struct ListNode* right;
}List;

class FindRootNodeSolution {
private:
    ListNode* list_node;
    int p;
    int q;
public:
    FindRootNodeSolution(ListNode* _list_node, int _p, int _q);
    ~FindRootNodeSolution();
};

#endif // FINDROOTNODE_H
