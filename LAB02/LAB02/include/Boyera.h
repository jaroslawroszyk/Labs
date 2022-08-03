#pragma once
#include <string>
# define NO_OF_CHARS 256

namespace TaskTwo
{
    struct Boyer
    {
        auto boyermoore(std::string haystack, std::string needle) -> int;
    };
} // namespace TaskTwo
