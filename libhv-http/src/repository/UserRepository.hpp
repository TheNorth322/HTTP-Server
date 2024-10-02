#pragma once

#include <map>
#include <vector>
#include "../entity/User.hpp"

class UserRepository {
public:
    virtual void addUser(User user) = 0;

    virtual void updateUser(User user) = 0;

    virtual User getUserByUUID(const std::string &uuid) = 0;

    virtual User getUserByUsername(const std::string &username) = 0;

    virtual std::vector<User> getUsers() = 0;

    virtual User deleteUser(const std::string &uuid) = 0;

    virtual ~UserRepository() = default;
};