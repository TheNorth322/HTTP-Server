#ifndef LIBHV_HTTP_BASE64ENCODER_H
#define LIBHV_HTTP_BASE64ENCODER_H

#include <string>
#include <vector>

namespace utils {
    std::string encode_base_64(const std::string &txt);

    std::string decode_base_64(const std::string &txt);

    std::vector<std::string> split(const std::string &s, const char *delim);
}

#endif //LIBHV_HTTP_BASE64ENCODER_H