#include "Caesar.h"
#include <string_view>
#include <vector>
#include <string>

namespace Task1
{
    auto Caesar::ceaser(std::string &str, const std::string_view &key) -> std::string
    {
        int i {0};
        auto shift = [&i, &key]()
        {
            i %= key.size();
            return key[i++] - 'A';
        };

        for(auto &c: str)
        {
            bool isLower = c >= 'a' and c <= 'z';
            c = std::toupper(c);
            if(c >= 'A' and c <= 'Z')
            {
                c += shift();
                if(c > 'Z')
                {
                    c -= 'Z' - 'A' + 1;
                }
            }
            if(isLower)
                c = std::tolower(c);
        }
        return str;
    }

    auto Caesar::decodeChiper(std::string &str, const std::string_view &key) -> std::string
    {
        int i {0};
        auto shift = [&i, &key]()
        {
            i %= key.size();
            return key[i++] - 'A';
        };

        for(auto &c: str)
        {
            bool isLower = c >= 'a' and c <= 'z';
            c = std::toupper(c);
            if(c >= 'A' and c <= 'Z')
            {
                c -= shift();
                if(c < 'A')
                {
                    c += 'Z' - 'A' + 1;
                }
            }
            if(isLower)
                c = std::tolower(c);
        }
        return str;
    }
} // namespace Task1