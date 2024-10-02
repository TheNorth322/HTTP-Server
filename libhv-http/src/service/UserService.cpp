#include "UserService.hpp"
#include <utility>
#include "../utility/Base64Encoder.hpp"


UserService::UserService(std::unique_ptr<UUIDGenerator> uuidGenerator, std::unique_ptr<UserRepository> userRepository)
        : uuidGenerator(std::move(uuidGenerator)), userRepository(std::move(userRepository)) {
//    userRepository->addUser(User(uuidGenerator->generate(), UserRole::Admin, "admin", "admin"));
}

User UserService::addUser(const std::string &role, std::string username, std::string password) {
    std::string uuid = uuidGenerator->generate();
    std::optional<UserRole> roleOptional = convertStringToUserRole(role);

    if (roleOptional) {
        User user(uuid, roleOptional.value(), std::move(username), std::move(password));
        userRepository->addUser(user);
        return user;
    }

    throw std::invalid_argument("invalid role");
}

User UserService::getUser(const std::string &uuid) {
    return userRepository->getUserByUUID(uuid);
}

User UserService::getUserByUsername(const std::string &username) {
    return userRepository->getUserByUsername(username);
}

User UserService::deleteUser(const std::string &uuid, const std::string &usernameWriter) {
    auto deleted = userRepository->getUserByUUID(uuid);
    auto writer = userRepository->getUserByUsername(usernameWriter);

    if (deleted.getUUID() == writer.getUUID() || writer.getRole() == UserRole::Admin) {
        return userRepository->deleteUser(uuid);
    }

    throw std::invalid_argument("Access denied");
}

std::vector<User> UserService::getUsers() {
    return userRepository->getUsers();
}

bool UserService::checkAuthorization(std::string_view username, std::string_view password) {
    std::vector users = getUsers();

    for (const auto &user: users) {
        if (user.getUsername() == username) {
            return user.getPassword() == password;
        }
    }

    return false;
}

std::string UserService::login(const std::string &username, const std::string &password) {
    std::vector users = getUsers();

//    auto encodeUsername = utils::encode_base_64(username);
//    auto encodePassword = utils::encode_base_64(password);
//    auto username = utils::decode_base_64(encodedPassword);
//    auto password = utils::decode_base_64(encodedPassword);

    for (const auto &user: users) {
        if (user.getPassword() == password && user.getUsername() == username) {
            return utils::encode_base_64(username) + "." + utils::encode_base_64(password);
        }
    }

    throw std::invalid_argument("invalid username or password");
}

User UserService::updateUser(const std::string &usernameWriter, const std::string &uuid, std::string updateUserUsername,
                             std::string updateUserPassword, const std::string &updateUserRole) {
    auto userWriter = userRepository->getUserByUsername(usernameWriter);
    auto changingUser = userRepository->getUserByUUID(uuid);

    if (userWriter.getUUID() == changingUser.getUUID() || userWriter.getRole() == UserRole::Admin) {
        changingUser.setUsername(std::move(updateUserUsername));
        changingUser.setPassword(std::move(updateUserPassword));

        if (userWriter.getRole() == UserRole::Admin) {
            auto role = (updateUserRole == "Admin") ? UserRole::Admin : UserRole::User;

            changingUser.setRole(role);
        }

        userRepository->updateUser(changingUser);
        return changingUser;
    }

    throw std::invalid_argument("invalid role");
}