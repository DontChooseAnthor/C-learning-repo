//
// Created by 钱亮 on 2024/04/23.
// Desc 通过二分法找到目标在由小到大顺序排列的数组的下标，没有则返回-1
//

#include <vector>

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

class BinarySearchSolution
{
public:
    int binarySearch(std::vector<int>& nums, int target);
};


#endif // BINARYSEARCH_H