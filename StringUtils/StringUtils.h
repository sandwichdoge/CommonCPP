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
    static bool betweenBrackets(std::vector<std::string> &out, std::string str, char c) {
        int isInsideBrackets = 0;
        size_t start = 0;
        size_t end = 0;

        std::string s = "";
        out.clear();

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == c) {
                isInsideBrackets ^= 1;

                if (isInsideBrackets) {
                    start = i;
                }
                else { // Closing bracket
                    end = i;
                    if (end > start + 1) { // ""
                        s = str.substr(start + 1, end - start - 1);
                    } else {
                        s = "";
                    }
                
                    out.push_back(s);
                }
            }
        
        }

        return true;
    }
    
    // Count number of chars c in string
    static int charCount(std::string str, char c) {
        int ret = 0;

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == c) {
                ret++;
            }
        }

        return ret;
    }

    static bool stringTrimLeft(std::string &s, size_t n) {
        if (s.length() == 0 || n < 0) return false;

        if (n >= s.length()) {
            s = "";
            return true;
        }

        s = s.substr(n, s.length() - 1);

        return true;
    }

    static bool stringTrimRight(std::string &s, size_t n) {
        #define ZERO_FLOOR(n) (n < 0 ? n == 0 : n)
        if (s.length() == 0 || n < 0) return false;

        if (n >= s.length()) {
            s = "";
            return true;
        }

        s = s.substr(0, ZERO_FLOOR(s.length() - n));

        return true;
    }

    static bool stringReplace(std::string &s, std::string sub_old, std::string sub_new) {
        if (sub_old == sub_new || sub_old.empty()) return false;

        size_t old_pos = 0;
    
        while (1) {
            old_pos = s.find(sub_old, old_pos);
            if (old_pos == std::string::npos) break;

            s.replace(old_pos, sub_old.length(), sub_new);
            old_pos += sub_new.length();
        }

        return true;
    }

    static std::string intToString(int n) {
        char s[16] = {0};

        int total = snprintf(s, sizeof(s), "%d", n);
        if (total <= 0) {
            return "";
        } else {
            return std::string(s);
        }
    }

    static std::string intToString(unsigned int n) {
        char s[16] = {0};

        int total = snprintf(s, sizeof(s), "%u", n);
        if (total <= 0) {
            return "";
        } else {
            return std::string(s);
        }
    }

    static std::string intToString(long long n) {
        char s[16] = {0};

        int total = snprintf(s, sizeof(s), "%lld", n);
        if (total <= 0) {
            return "";
        } else {
            return std::string(s);
        }
    }

    static std::string intToString(unsigned long long n) {
        char s[16] = {0};

        int total = snprintf(s, sizeof(s), "%llu", n);
        if (total <= 0) {
            return "";
        } else {
            return std::string(s);
        }
    }
};