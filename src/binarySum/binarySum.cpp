//
// Created by 钱亮 on 2024/3/4.
//

#include <string>
#include <algorithm>
#include "binarySum.h"

int power_of_two(int n) {
    return 1<<n;
}

int btod(std::string b) {
    int d = 0;
    std::reverse(b.begin(), b.end());
    for (int i = 0; i < b.length(); ++i) {
        d += (b[i] - '0') * power_of_two(i);
    }
    return d;
}

std::string dtob(int d) {
    std::string b = "";
    int d_cache = d;
    justdoit:
        b += std::to_string(d_cache % 2);
        d_cache = d_cache / 2;
    if (d_cache > 1) {
        goto justdoit;
    } else {
        b += "1";
    }
    std::reverse(b.begin(), b.end());
    return b;
}

std::string BinarySumSolution::binarySum(std::string a, std::string b) {
    int int_a = btod(a);
    int int_b = btod(b);
    int int_c = int_a + int_b;
    std::string string_c = dtob(int_c);
    return string_c;
}

// int main()
// {
//     BinarySumSolution s;
//     string res = s.binarySum("11", "10");
//     cout<<res<<endl;
// }