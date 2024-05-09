//
// Created by 钱亮 on 2024/3/22.
//

#include "reduceBinaryTree.h"
#include <vector>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr){}
};

class TreeBuildSolution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* dfs(std::vector<int>& preorder, int preLeft, int preRight, std::vector<int>& inorder, int inLeft, int inRight) {
        if (preLeft > preRight) {
            return nullptr;
        }
        // 每次遍历都以该节点为root节点
        TreeNode* root = new TreeNode(preorder[preLeft]);

        int leftChildCnt = 0;
        // 第一次执行，通过先序的第一个节点确定根节点，然后找到中序的根节点位置
        while (preorder[preLeft] != inorder[inLeft + leftChildCnt]) {
            ++leftChildCnt;
        }
        root->left = dfs(preorder, preLeft+1, preLeft+leftChildCnt, inorder, inLeft, inLeft+leftChildCnt - 1);
        root->right = dfs(preorder, preLeft + leftChildCnt + 1, preRight, inorder, inLeft + leftChildCnt+1, inRight);
        return root;
    }
};

// int main() {
//     vector<int> preorder_traversal = {5,4,11,7,2,8,13,4,5,1};
//     vector<int> inorder_traversal = {7,11,2,4,5,13,8,5,4,1};
//     Solution s;
//     TreeNode* t;
//     t = s.buildTree(preorder_traversal, inorder_traversal);
// }