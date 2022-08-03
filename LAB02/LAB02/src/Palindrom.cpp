#include "Palindrom.h"
#include <string>

namespace TaskOne
{

    auto Palindrome::containsPalindrome(const std::string &str) -> bool
    {
        const int limit = str.length();
        if(limit < 2)
        {
            return false;
        }
        else if(limit == 2)
        {
            return (str[0] == str[1]);
        }
        else
        {
            for(int i = 1; i < limit - 1; i++)
            {
                if((str[i - 1] == str[i] || str[i + 1] == str[i]) || str[i - 1] == str[i + 1])
                    return true;
            }
        }
        return false;
    }

} //namespace TaskOne
