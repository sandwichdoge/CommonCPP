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

#endif