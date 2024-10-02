#include <stdexcept>
#include <vector>
#include "MapUserRepository.hpp"

MapUserRepository::MapUserRepository() : users(std::map<std::string, User>()) {
    // TODO: Creation of base admin
}

bool MapUserRepository::unsafeCheckForExistingOnes(const User &user) {
    for (const auto &_user: users) {
        if (_user.second.getUsername() == user.getUsername())
            return true;
    }

    return this->users.find(user.getUUID()) != users.end();
}


void MapUserRepository::unsafeAddUser(User user) {
    if (unsafeCheckForExistingOnes(user))
        throw std::invalid_argument("user already exists");

    users.insert({user.getUUID(), std::move(user)});
}

void MapUserRepository::addUser(User user) {
    const std::lock_guard<std::mutex> lock(userRepositoryMutex);
    unsafeAddUser(user);
}

User MapUserRepository::getUserByUUID(const std::string &uuid) {
    const std::lock_guard<std::mutex> lock(userRepositoryMutex);
    return unsafeGetUserByUUID(uuid);
}

User MapUserRepository::unsafeGetUserByUUID(const std::string &uuid) {
    auto it = users.find(uuid);
    if (it == users.end())
        throw std::invalid_argument("user not found");

    return it->second;
}

User MapUserRepository::getUserByUsername(const std::string &username) {
    const std::lock_guard<std::mutex> lock(userRepositoryMutex);
    return unsafeGetUserByUsername(username);

}

User MapUserRepository::unsafeGetUserByUsername(const std::string &username) {
    for (auto & [_, user]: users) {
        if (user.getUsername() == username)
            return user;
    }
    throw std::invalid_argument("user not found");
}

User MapUserRepository::deleteUser(const std::string &uuid) {
    const std::lock_guard<std::mutex> lock(userRepositoryMutex);
    return unsafeDeleteUser(uuid);
}

User MapUserRepository::unsafeDeleteUser(const std::string &uuid) {
    auto it = users.find(uuid);
    if (it == users.end())
        throw std::invalid_argument("user not found");

    auto user = std::move(it->second);
    users.erase(it);

    return user;
}

std::vector<User> MapUserRepository::getUsers() {
    const std::lock_guard<std::mutex> lock(userRepositoryMutex);
    return unsafeGetUsers();
}

std::vector<User> MapUserRepository::unsafeGetUsers() {
    auto users_vec = std::vector<User>();
    for (const auto &pair: users) {
        users_vec.push_back(pair.second);
    }

    return users_vec;
}

void MapUserRepository::updateUser(User newValue) {
    const std::lock_guard<std::mutex> lock(userRepositoryMutex);
    users.at(newValue.getUUID()) = newValue;
}
