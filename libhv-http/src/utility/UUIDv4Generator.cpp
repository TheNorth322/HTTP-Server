#include "UUIDv4Generator.hpp"
#include "../../contrib/uuid_v4/uuid_v4.h"

const std::string UUIDv4Generator::generate() {
    UUIDv4::UUIDGenerator <std::mt19937> uuid_generator;
    auto uuid = uuid_generator.getUUID();

    return uuid.str();
}