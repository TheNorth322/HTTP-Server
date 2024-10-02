#pragma once

#include "UserRepository.hpp"
#include <mutex>

class MapUserRepository : public UserRepository {
public:
    MapUserRepository();

    void addUser(User user) override;

    User getUserByUUID(const std::string &uuid) override;

    User getUserByUsername(const std::string &uuid) override;

    User deleteUser(const std::string &uuid) override;

    std::vector<User> getUsers() override;

    void updateUser(User user) override;

private:
    void unsafeAddUser(User user);

    User unsafeGetUserByUUID(const std::string &uuid);

    User unsafeGetUserByUsername(const std::string &uuid);

    User unsafeDeleteUser(const std::string &uuid);

    std::vector<User> unsafeGetUsers();

    bool unsafeCheckForExistingOnes(const User &user);

    std::map<std::string, User> users;
    std::mutex userRepositoryMutex;
};