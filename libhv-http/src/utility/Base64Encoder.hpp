#ifndef _BASE_64_ENCODER_HPP_
#define _BASE_64_ENCODER_HPP_

#include <cstdint>
#include <string>
#include <vector>

namespace utils
{
    std::string encode_base_64(std::string_view txt);

    std::string decode_base_64(std::string_view txt);

//    std::vector<std::string> split(const std::string &s, const char *delim);
    std::vector<std::string_view> split(std::string_view s, const char *delim);
}

#endif