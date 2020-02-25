#ifndef INCLUDE_REGEXP_H_
#define INCLUDE_REGEXP_H_
#include <string>
#include <vector>
#include <regex>


class Regexp
{
public:
    static bool search(const std::string &str, std::string pattern, std::vector<std::string> &out) {
        std::regex e(pattern);
        std::smatch m;
        std::string tmp = str;

        while (std::regex_search(tmp, m, e)) {
            for (int i = 1; i < m.size(); i++) {
                out.push_back(m.str(i));
            }
            tmp = m.suffix().str();
        }

        return out.size() > 0 ? true : false;
    }

    static bool replace(std::string &str, std::string pattern, std::string replace) {
        std::regex e(pattern);
        str = std::regex_replace(str, e, replace);

        return true;
    }
};

#endif
