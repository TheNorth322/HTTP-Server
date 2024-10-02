#include <stdexcept>
#include <utility>
#include "User.hpp"

std::string ConvertUserRoleToString(const UserRole role) {
    switch (role) {
        case UserRole::Admin: return "Admin";
        case UserRole::User: return "User";
    }

    return "";
}

std::optional<UserRole> convertStringToUserRole(const std::string &role) {
    if (role == "User")
        return UserRole::User;
    if (role == "Admin")
        return UserRole::Admin;

    return {};
}

User::User(std::string _uuid, UserRole _role, std::string _username, std::string _password) : role(_role),
                                                                                              uuid(std::move(_uuid)),
                                                                                              username(std::move(
                                                                                                      _username)),
                                                                                              password(std::move(
                                                                                                      _password)) {
    if (uuid.empty())
        throw std::invalid_argument("uuid is empty");
    if (username.empty())
        throw std::invalid_argument("username is empty");
    if (password.empty())
        throw std::invalid_argument("password is empty");
}

const std::string &User::getUUID() const {
    return this->uuid;
}

const UserRole User::getRole() const {
    return this->role;
}

const std::string &User::getUsername() const {
    return this->username;
}

const std::string &User::getPassword() const {
    return this->password;
}

void User::setPassword(std::string _password) {
    this->password = std::move(_password);
}

void User::setRole(UserRole _role) {
    this->role = _role;
}

void User::setUsername(std::string _username) {
    this->username = std::move(_username);
}

nlohmann::json User::toJson() const {
    return {
            {"uuid",     uuid},
            {"username", username},
            {"role", ConvertUserRoleToString(role), }
    };
}
