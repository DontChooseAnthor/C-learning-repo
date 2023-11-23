#include "string"
#include <iostream>
#include "vector"
#include "longestCommonPrefix.h"

/**
 * 0-1比较最长相似字符串
 * 提取出的字符串和从2开始对比，并返回相似字符串
 * 直到相似字符串为0时中断寻找
*/

std::string LongestCommonPrefixSolution::longestCommonPrefix(const std::string str1, const std::string str2) {
    int length = std::min(str1.size(), str2.size());
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if (str1[i] == str2[i]) {
            index += 1;
            continue;
        } else {
            break;
        }
    }
    return str1.substr(0, index);
}

std::string LongestCommonPrefixSolution::longestCommonPrefix(std::vector<std::string>& strs) {
    if (!strs.size()) {
        return "";
    }
    std::string preStr = strs[0];
    std::string dealStr = "";
    for (int i = 1; i < strs.size(); i++)
    {
        dealStr = longestCommonPrefix(preStr, strs[i]);
        if (dealStr.size() > 0) {
            preStr = dealStr;
            continue;
        } else {
            break;
        }
    }
    return dealStr;
};

// int main()
// {
//     LongestCommonPrefixSolution s;
//     string strArr[4] = {"srr", "srxxx", "srrxc", "sxrr"};
//     vector<string> strList;
//     strList.insert(strList.begin(), strArr, strArr+4);
//     string preFix = s.longestCommonPrefix(strList);
//     cout<<"preFix:"<<preFix<<endl;
//     return 0;
// }