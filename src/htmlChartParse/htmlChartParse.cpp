#include "string"
#include <map>
#include "htmlChartParse.h"

std::string HtmlChartParseSolution::htmlChartParse(std::string htmlStr) {
    using EntityChar = std::pair <std::string, char>;
    auto entityList = std::vector({
        (EntityChar){"&quot;", '"'},
        (EntityChar){"&apos;", '\''},
        (EntityChar){"&amp;", '&'},
        (EntityChar){"&gt;", '>'},
        (EntityChar){"&lt;", '<'},
        (EntityChar){"&frasl;", '/'}
    });
    std::string r = "";
    for (int pos = 0; pos < htmlStr.size(); )
    {
        bool isEntity = false;
        if (htmlStr[pos] == '&') {
            for (const auto &[e, c]: entityList)
            {
                if (htmlStr.substr(pos, e.size()) == e) {
                    r.push_back(c);
                    pos += e.size();
                    isEntity = true;
                    break;
                }
            }
        }
        if (!isEntity) {
            r.push_back(htmlStr[pos++]);
            continue;
        }
    }
    return r;
}

// int main()
// {
//     HtmlChartParseSolution s;
//     string htmlTemp = "ren&quot;dd&lt;name&gt;";
//     auto res = s.htmlChartParse(htmlTemp);
//     cout<<res<<endl;
//     return 0;
// }