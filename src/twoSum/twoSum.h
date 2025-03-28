#ifndef TWO_SUM

#include <map>
#include <vector>
#include <unordered_map>

class TwoSumSolution
{
public:
    std::vector<int>twoSum(std::vector<int> &nums, int target);
};

// hash表写法
class HashTableSolution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没有找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i));
        }
        
    }
};

#endif/*include twoSum.h*/
