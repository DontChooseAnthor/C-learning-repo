#ifndef LC445_H
#define LC445_H
#include <iostream>
#include <vector>

class Solution {
public:
int getSatisfiedChildNum(std::vector<int>& g, std::vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.begin());
    int satisfied_num = 0;
    int cur_cookie = s.size() - 1;
    // 倒叙遍历
    for (int i = g.size() - 1; i >= 0; i--)
    {
        if (s[cur_cookie] >= g[i] && cur_cookie >= 0) {
            satisfied_num += 1;
            cur_cookie -= 1;
        } else {
            continue;
        }
    }
    return satisfied_num;
}
};

#endif