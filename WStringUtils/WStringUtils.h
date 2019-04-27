#include <string>
#include <locale>
#include <codecvt>

class WStringUtils
{
    public:
        static std::string WstringToBytes(std::wstring ws);
        static std::wstring BytesToWstring(const char *s);
};

std::string WStringUtils::WstringToBytes(std::wstring ws)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    std::string s = utf8_conv.to_bytes(ws);

    return s;
}


std::wstring WStringUtils::BytesToWstring(const char *s)
{
    if (!s)
    {
        return L"";
    }

    std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    std::wstring ws = utf8_conv.from_bytes(s);

    return ws;
}