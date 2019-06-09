#ifndef _FILE_UTILS_H
#define _FILE_UTILS_H

#include <fstream>
#include <sstream>
#include <string>


class FileUtils
{
public:
    template <typename T>
    static int readFile(const T &path, std::string &out);

    template <typename T>
    static int readFile(const T &path, char *out, size_t size);

    template <typename T>
    static int writeFile(const T &path, const std::string &data);

    template <typename T>
    static int writeFile(const T &path, const char *data, size_t size);
};



template <typename T>
int FileUtils::readFile(const T &path, std::string &out)
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
int FileUtils::readFile(const T &path, char *out, size_t size)
{
    std::ifstream f;
    f.open(path);

    if (!f.is_open()) return -1;

    memset(out, 0, size);

    f.read(out, size);

    f.close();

    return 0;
}


template <typename T>
int FileUtils::writeFile(const T &path, const std::string &data)
{
    std::ofstream f;
    f.open(path);

    if (!f.is_open()) return -1;

    f << data;

    f.close();

    return 0;
}


template <typename T>
int FileUtils::writeFile(const T &path, const char *data, size_t size)
{
    std::ofstream f;
    f.open(path);

    if (!f.is_open()) return -1;

    f.write(data, size);

    f.close();

    return 0;
}

#endif
