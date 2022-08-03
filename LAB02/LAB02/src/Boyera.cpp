#include "Boyera.h"
#include <iostream>

namespace TaskTwo
{
    auto Boyer::boyermoore(std::string haystack, std::string needle) -> int
    {
        int N = haystack.length();
        int M = needle.length();

        char badchar[NO_OF_CHARS];

        for(int i = 0; i < NO_OF_CHARS; i++)
        {
            badchar[i] = -1;
        }
        for(int i = 0; i < M; i++)
        {
            badchar[needle[i]] = i;
        }

        int i = 0;

        while (i <= N - M)
        {
            int j = M - 1;
            while (j >= 0 && needle[j] == haystack[i + j])
            {
                j -= 1;
            }
            if(i + M < N)
            {
                i += M - badchar[haystack[i + M]];
            }
            else
            {
                i += 1;
                std::cout << " else Pattern found at index " << i << std::endl;
            }
            if(j < 0)
            {
                std::cout << "Pattern found at index " << i << std::endl; //help cout
            }
            else
            {
                i += std::max(1, j - badchar[haystack[i + j]]);
                std::cout << "else ifa found at index " << i << std::endl;
            }
            return i;
        }
        return i;
    }
} // namespace TaskTwo