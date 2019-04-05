#include "StringUtils.h"

int StringUtils::charCount(std::string str, char c)
{
    int ret = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            ret++;
        }
    }

    return ret;
}

bool StringUtils::betweenBrackets(std::vector<std::string> &out, std::string str, char c)
{
    int isInsideBrackets = 0;
    size_t start = 0;
    size_t end = 0;

    std::string s = "";
    out.clear();

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            isInsideBrackets ^= 1;

            if (isInsideBrackets)
            {
                start = i;
            }
            else // Closing bracket
            {
                end = i;
                if (end > start + 1) // ""
                {
                    s = str.substr(start + 1, end - start - 1);
                }
                else
                {
                    s = "";
                }
                
                out.push_back(s);
            }
        }
        
    }

    return true;
}

bool StringUtils::stringTrimLeft(std::string &s, size_t n)
{
    if (s.length() == 0 || n < 0) return false;

    if (n >= s.length()) {
        s = "";
        return true;
    }

    s = s.substr(n, s.length() - 1);

    return true;
}

#define ZERO_FLOOR(n) (n < 0 ? n == 0 : n)
bool StringUtils::stringTrimRight(std::string &s, size_t n)
{
    if (s.length() == 0 || n < 0) return false;

    if (n >= s.length()) {
        s = "";
        return true;
    }

    s = s.substr(0, ZERO_FLOOR(s.length() - n));

    return true;
}


bool StringUtils::stringReplace(std::string &s, std::string sub_old, std::string sub_new)
{
    size_t old_len = sub_old.length();
    size_t old_pos = s.find(sub_old);

    s.replace(old_pos, old_len, sub_new);

    return true;
}

/*
int main()
{
    std::vector<std::string> v = StringUtils::betweenBrackets("\"toong\",\"guest\",\"guest2\",\"G uest3\"", 'a');

    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << std::string((*it)) << std::endl;
    }

    return 0;
}*/