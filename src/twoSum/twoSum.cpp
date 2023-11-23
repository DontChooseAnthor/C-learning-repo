#include <vector>
#include "twoSum.h"

std::vector<int> TwoSumSolution::twoSum(std::vector<int> &nums, int target) {
    int n = nums.size();
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }
    }
    return {};
}

// TwoSumSolution s;
// int arr[6] = {1,2,3,4,5,6};
// vector<int> a, b;
// a.insert(a.begin(), arr, arr+6);
// b = s.twoSum(a, 3);
// for (auto array: b) {
//     cout<<array<<" ";
// }
// cout<<endl;
// return 0;