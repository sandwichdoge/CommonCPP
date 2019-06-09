#ifndef _FILE_UTILS_H
#define _FILE_UTILS_H

#include <fstream>
#include <sstream>
#include <string>


class FileUtils
{
public:
    template <typename T>
    static int readFile(T &path, std::string &out);

    template <typename T>
    static int writeFile(T &path, const std::string &data);
};



template <typename T>
int FileUtils::readFile(T &path, std::string &out)
{
    std::ifstream f;
    f.open(path);

    if (!f.is_open()) return -1;

    std::stringstream ss;
    ss << f.rdbuf();

    out = ss.str();

    f.close();

    return 0;
}


template <typename T>
int FileUtils::writeFile(T &path, const std::string &data)
{
    
    return 0;
}

#endif
