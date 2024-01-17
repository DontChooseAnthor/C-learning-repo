#include "string"
#include "deleteFixSubString.h"
#include <regex>
#include "iostream"

/**
 * 处理固定字符串
*/

std::string strRemoveFn(std::string str, std::string curStr) {
    if (curStr.length() <= 0) {
        return str;
    }
    std::regex pattern(curStr);
    return regex_replace(str, pattern, "");
}

std::string DeleteFixSubStringSolution::deleteFixSubString(std::string str, std::string arr[]) {
    for (int i = 0; i < arr->length(); ++i) {
        str = strRemoveFn(str, arr[i]);
    }
    return str;
}

// int main()
// {
//     DeleteFixSubStringSolution s;
//     std::string str = "ABABCDCABDB";
//     std::string arr[] = {"AB", "CD"};
//     std::string res = s.deleteFixSubString(str, arr);
//     std::cout<<res<<std::endl;
// }

