#pragma once
#include <string_view>
namespace Task1
{
    struct Caesar
    {
        static auto ceaser(std::string &str, const std::string_view &key) -> std::string;

        static auto decodeChiper(std::string &str, const std::string_view &key) -> std::string;
    };
} // namespace Task1
