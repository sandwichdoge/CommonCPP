#include "Regexp.h"
#include <iostream>


bool Regexp::search(std::string str, std::string pattern, std::vector<std::string> &out)
{
    std::regex e(pattern, std::regex::nosubs);
    std::smatch m;

    while (std::regex_search(str, m, e))
    {
        for (auto x:m)
        {
            out.push_back(x);
        }
        str = m.suffix().str();
    }

    return out.size() > 0 ? true : false;
}


bool Regexp::replace(std::string &str, std::string pattern, std::string replace)
{
    std::regex e(pattern);

    str = std::regex_replace(str, e, replace);

    return true;
}

