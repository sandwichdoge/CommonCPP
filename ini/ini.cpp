#include "ini.h"


bool ini::IniWrite(std::string &out, std::string section, std::string key, std::string value)
{
    if (section.empty() || key.empty()) return false;

	size_t sect = out.find("[" + section + "]", 0); 
	size_t pos = out.find("\n" + key + "=", sect) + 1;


    if (sect == -1) // New section
    {
        out = "[" + section + "]\n\n" + out;
        sect = 0;
    }


    bool isNewKey = false;
	if (pos == 0) // New key
	{
        isNewKey = true;
		pos = sect + ("[" + section + "]").length(); // More readable
	}


	size_t lineLen = out.find("\n", pos) - pos;

    if (isNewKey)
    {
        out.replace(pos, lineLen, "\n" + key + "=" + value);
    }
    else
    {
        out.replace(pos, lineLen, key + "=" + value);
    }

    return true;
}


bool ini::IniRead(std::string content, std::string section, std::string key, std::string &value)
{
    value = "";

    if (content.empty() || key.empty() || section.empty()) return false;

    size_t sect = content.find("[" + section + "]", 0); 
    if (sect == -1) return false;

	size_t pos = content.find("\n" + key + "=", sect) + 1;
    if (pos == -1) return false;

    size_t val = content.find("=", pos) + 1;
    if (val == -1) return false;

    size_t lf = content.find("\n", val);
    if (lf == -1) // EOF with no spare linebreak;
    {
        lf = content.length();
    }


    value = content.substr(val, lf - val);

    return true;
}
