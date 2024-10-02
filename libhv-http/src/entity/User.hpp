#pragma once

#include <string>
#include <optional>
#include "json.hpp"

enum class UserRole {
    User,
    Admin
};

std::optional<UserRole> convertStringToUserRole(const std::string &role);

class User {
public:
    User() = delete;

    User(std::string _uuid, UserRole _role, std::string _username, std::string _password);

    [[nodiscard]] const std::string &getUUID() const;

    [[nodiscard]] const UserRole getRole() const;

    [[nodiscard]] const std::string &getUsername() const;

    [[nodiscard]] const std::string &getPassword() const;

    void setRole(UserRole _role);

    void setUsername(std::string _username);

    void setPassword(std::string _password);


    [[nodiscard]] nlohmann::json toJson() const;

private:
    UserRole role;
    std::string uuid;
    std::string username;
    std::string password;
};