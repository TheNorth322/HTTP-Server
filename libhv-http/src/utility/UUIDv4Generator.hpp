#pragma once

#include "UUIDGenerator.hpp"

class UUIDv4Generator : public UUIDGenerator {
public:
    const std::string generate() override;

    UUIDv4Generator() = default;
};
