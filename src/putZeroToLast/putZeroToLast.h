#ifndef PUTZEROTOLAST_H
#define PUTZEROTOLAST_H

class putZeroToLast {
public:
    void solution(std::vector<int> &nums) {
        for (int i = 0, k = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) {
                if (i != k) {
                    swap(nums[k], nums[i]);
                }
                k++;
            }
        }
    }
};

#endif