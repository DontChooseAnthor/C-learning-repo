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

std::string getRegexMatchStr(std::string str, std::string arr[]) {
    for (int i = 0; i < arr->length(); ++i) {
        std::regex e(arr[i]);
        if (std::regex_search(str, e)) {
            return arr[i];
        }
    }
    return "";
}

int DeleteFixSubStringSolution::deleteFixSubString(std::string str, std::string arr[]) {
    for (;;) {
        std::string resStr = getRegexMatchStr(str, arr);
        if (resStr.length() == 0) {
            break;
        } else {
            str = strRemoveFn(str, resStr);
        }
    }
    return str.length();
}

// int main()
// {
//     DeleteFixSubStringSolution s;
//     std::string str = "ABABCDCABDB";
//     std::string arr[] = {"AB", "CD"};
//     std::string res = s.deleteFixSubString(str, arr);
//     std::cout<<res<<std::endl;
// }