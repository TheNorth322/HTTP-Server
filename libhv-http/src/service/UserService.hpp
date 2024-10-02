#pragma once

#include "../repository/UserRepository.hpp"
#include "../utility/UUIDGenerator.hpp"

class UserService {
public:
    UserService() = delete;

    UserService(UserService &&) = default;

    UserService(std::unique_ptr<UUIDGenerator> uuidGenerator, std::unique_ptr<UserRepository> rep);

    User addUser(const std::string &role, std::string username, std::string password);

    User getUser(const std::string &uuid);

    User getUserByUsername(const std::string &username);

    User deleteUser(const std::string &uuid, const std::string &usernameWriter);

    bool checkAuthorization(std::string_view username, std::string_view password);

    std::string login(const std::string &username, const std::string &password);
//    std::string login(std::string username, std::string password);

    std::vector<User> getUsers();

//    User updateUser(std::string usernameWriter, std::string uuid, std::string updateUserUsername, std::string updateUserPassword, std::string updateUserRole);
    User updateUser(const std::string &usernameWriter, const std::string &uuid, std::string updateUserUsername, std::string updateUserPassword, const std::string &updateUserRole);

private:
    std::unique_ptr<UUIDGenerator> uuidGenerator;
    std::unique_ptr<UserRepository> userRepository;
};
