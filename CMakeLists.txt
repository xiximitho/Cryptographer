cmake_minimum_required(VERSION 3.21)
project(Ftk)

set(CMAKE_CXX_STANDARD 17)
set(SRC_DIR src/)
set(CryptoPP_DIR cryptopp)
find_package(CryptoPP REQUIRED)
find_package(PkgConfig)
find_package(OpenSSL REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp
        ${SRC_DIR}FormBase.cpp
        ${SRC_DIR}FormBase.h
        ${SRC_DIR}aes.cpp
        ${SRC_DIR}aes.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} cryptopp-static OpenSSL::Crypto)