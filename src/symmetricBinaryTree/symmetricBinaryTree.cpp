//
// Created by 钱亮 on 2024/2/4.
// 判断该数组结构是否可以还原为轴对称二叉树结构
//

#include "symmetricBinaryTree.h"
#include <vector>
#include "iostream"
#include "string"
#include "sstream"
#include <algorithm>

std::vector<std::string> stringSplit(const std::string& str, char delim) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

bool SymmetricBinaryTreeSolution::isSymmetricBinaryTree(std::vector<int> arr) {
    // 非偶数场景下一定不是平衡二叉树
    if (arr.size() % 2 != 0) {
        return false;
    }
    // 1. 按照 整个数组减去根节点 后 以2的倍数分割每层的节点
    // 2. 对比每层前半段和后半段的镜像是否相同
    int level = 1;
    int curLen = 1;
    // 初始化第一个节点
    std::string treeMap = std::to_string(arr[0]) + "|";
    while (curLen < arr.size()) {
        for (int i = curLen; i < curLen + (1<<level); ++i) {
            treeMap += std::to_string(arr[i]);
        }
        treeMap += "|";

        curLen += 1<<level;
        level += 1;
    }
    treeMap = treeMap.substr(0, treeMap.length() - 1);
    std::vector<std::string> treeVec;
    treeVec = stringSplit(treeMap, '|');
    bool equalFlag = true;
    for (int i = 1; i < treeVec.size() - 1; ++i) {
        // 每一组从中间裁剪，并翻转比对，不相同则break
        int len = treeVec[i].length();
        std::string preStr = treeVec[i].substr(0, len / 2);
        std::string nextStr = treeVec[i].substr(len / 2, len / 2);
        std::reverse(nextStr.begin(), nextStr.end());
        if (preStr != nextStr) {
            equalFlag = false;
            break;
        }
    }
    return equalFlag;
};
