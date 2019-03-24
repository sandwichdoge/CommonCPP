/* Non-std string manipulation.
 * Author       : Thuan Ho (sandwichdoge@gmail.com)
 * Created on   : 24/03/2019
 */

#pragma once
#include <vector>
#include <string>

class StringUtils
{
    public:
        StringUtils();
        virtual ~StringUtils();

        // Get a list of strings between brackets c
        static bool betweenBrackets(std::vector<std::string> &out, std::string str, char c);
        
        // Count number of chars c in string
        static int charCount(std::string str, char c);
};