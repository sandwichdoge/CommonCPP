#ifndef REGEXP_H_
#define REGEXP_H_
#include <string>
#include <vector>
#include <regex>


class Regexp
{
public:
    Regexp();
    virtual ~Regexp();


    static bool search(std::string str, std::string pattern, std::vector<std::string> &out);

    static bool replace(std::string &str, std::string pattern, std::string replace);
};

bool Regexp::search(std::string str, std::string pattern, std::vector<std::string> &out)
{
    std::regex e(pattern);
    std::smatch m;

    while (std::regex_search(str, m, e))
    {
        for (int i = 1; i < m.size(); i++)
        {
            out.push_back(m.str(i));
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



#endif
