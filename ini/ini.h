/* Ini-format data manipulation.
 * Support string data only, no file I/O operations.
 * Author       : Thuan Ho (sandwichdoge@gmail.com)
 * Created on   : 24/03/2019
 */
#pragma once
#include <string>

class ini
{
public:
    ini();
    virtual ~ini();


    /* Modify existing key, or create new section/key.
     * Parameters:
     *   - out[Ref]     : Ini content to be modified.
     *   - section[In]  : Section to modify/create.
     *   - key[In]      : Key to modify/create.
     *   - value[In]    : New value.
     * Success: Return true.
     * Failure: Return false.
     * */
    static bool IniWrite(std::string &out, std::string section, std::string key, std::string value) {
        if (section.empty() || key.empty()) return false;

        size_t sect = out.find("[" + section + "]", 0); 
        size_t pos = out.find("\n" + key + "=", sect) + 1;

        if (sect == std::string::npos) { // New section
            out = "[" + section + "]\n\n" + out;
            sect = 0;
        }

        bool isNewKey = false;
        if (pos == 0) { // New key
            isNewKey = true;
            pos = sect + ("[" + section + "]").length(); // More readable
        }

        size_t lineLen = out.find("\n", pos) - pos;

        if (isNewKey) {
            out.replace(pos, lineLen, "\n" + key + "=" + value);
        } else {
            out.replace(pos, lineLen, key + "=" + value);
        }

        return true;
    }


    /* Read value from ini data.
     * Parameters:
     *   - content[In]  : Ini content to read from.
     *   - section[In]  : Section to read from.
     *   - key[In]      : Key to read from.
     *   - value[Out]   : Output value.
     * Success: Return true.
     * Failure: Return false.
     * */
    static bool IniRead(std::string content, std::string section, std::string key, std::string &value) {
        value = "";

        if (content.empty() || key.empty() || section.empty()) return false;

        size_t sect = content.find("[" + section + "]", 0); 
        if (sect == std::string::npos) return false;

        size_t pos = content.find("\n" + key + "=", sect) + 1;
        if (pos == std::string::npos) return false;

        size_t val = content.find("=", pos) + 1;
        if (val == std::string::npos) return false;

        size_t lf = content.find("\n", val);
        if (lf == std::string::npos) { // EOF with no spare linebreak;
            lf = content.length();
        }

        value = content.substr(val, lf - val);

        return true;
    }

};

