#pragma once

#include <string>

class UUIDGenerator {
public:
    virtual const std::string generate() = 0;

    virtual ~UUIDGenerator() = default;
};