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

/*
int main()
{
    std::vector<std::string> v = StringUtils::betweenBrackets("\"toong\",\"guest\",\"guest2\",\"G uest3\"", 'a');

    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << std::string((*it)) << std::endl;
    }

    return 0;
}*/