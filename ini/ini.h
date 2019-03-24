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
    static bool IniWrite(std::string &out, std::string section, std::string key, std::string value);


    /* Read value from ini data.
     * Parameters:
     *   - content[In]  : Ini content to read from.
     *   - section[In]  : Section to read from.
     *   - key[In]      : Key to read from.
     *   - value[Out]   : Output value.
     * Success: Return true.
     * Failure: Return false.
     * */
    static bool IniRead(std::string content, std::string section, std::string key, std::string &value);

};

