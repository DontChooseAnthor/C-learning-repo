//
// Created by RN on 2023/11/9.
//
#include "iostream"
#include <vector>
#include "string"
// #include "../src/twoSum/twoSum.h"
// #include "../src/longestCommonPrefix/longestCommonPrefix.h"
#include "../src/htmlChartParse/htmlChartParse.h"

using namespace std;

int main()
{
    HtmlChartParseSolution s;
    string htmlTemp = "ren&quot;dd&lt;name&gt;";
    auto res = s.htmlChartParse(htmlTemp);
    cout<<res<<endl;
    return 0;
}