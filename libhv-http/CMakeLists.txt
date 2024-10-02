cmake_minimum_required(VERSION 3.5)
project(libhv-http)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TARGET_NAME "libhv-http")
set(CLIENT_TARGET_NAME "libhv-http-client")

set(LIBHV_INCLUDE ${PROJECT_BINARY_DIR}/contrib/libhv/include/hv)

#if(WIN64)
#    set(OPENSSL_ROOT_DIR "C:/Program Files/OpenSSL-Win64")
#endif()

set(OPENSSL_SSL_LIBRARY ssl)
set(OPENSSL_CRYPTO_LIBRARY crypto)
set(OPENSSL_INCLUDE_DIR "${openssl_BINARY_DIR}/include" "${openssl_BINARY_DIR}")
set(OPENSSL_FOUND ON)
message(STATUS "Build OpenSSL: ${OPENSSL_INCLUDE_DIR}")


add_subdirectory(${PROJECT_SOURCE_DIR}/contrib)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wempty-body -Wredundant-move -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -mavx -march=native -Werror -Wempty-body -Wredundant-move -O2")

file(GLOB_RECURSE SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

file(GLOB_RECURSE CLIENT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/client_src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/client_src/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/client_src/*.h)

set(SOURCE_DIR_HEADER "")
execute_process(
        COMMAND find src -type d
        OUTPUT_VARIABLE SOURCE_DIR_HEADER
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
        WORKING_DIRECTORY .)
string(REPLACE "\n" ";" SOURCE_DIR_HEADER "${SOURCE_DIR_HEADER}" SOURCE_DIR_HEADER)

include_directories(${SOURCE_DIR_HEADER})
include_directories(${LIBHV_INCLUDE})


add_executable(${CLIENT_TARGET_NAME} ${CLIENT_SOURCES})
add_executable(${TARGET_NAME} ${SOURCES})

target_link_libraries(${CLIENT_TARGET_NAME} ${OPENSSL_LIBRARIES})
target_link_libraries(${CLIENT_TARGET_NAME} hv_static)

target_link_libraries(${TARGET_NAME} ${OPENSSL_LIBRARIES})
target_link_libraries(${TARGET_NAME} hv_static)
target_link_libraries(${TARGET_NAME} uuid_v4)
target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/contrib/uuid_v4/)

set(UUID_V4_ROOT_DIR "${PROJECT_SOURCE_DIR}/contrib/uuid_v4")
if (NOT EXISTS "${UUID_V4_ROOT_DIR}/CMakeLists.txt")
    message(FATAL_ERROR " submodule uuid_v4 is missing. To fix try run: \n git submodule update --init --recursive")
endif ()

set(BUILD_SHARED_LIBS "FALSE")
add_subdirectory("${UUID_V4_ROOT_DIR}" "${PROJECT_BINARY_DIR}/contrib/uuid_v4")