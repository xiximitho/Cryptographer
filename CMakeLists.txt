cmake_minimum_required(VERSION 3.21)
project(Cryptographer)
set(CMAKE_CXX_STANDARD 17)
set(CryptoPP_DIR cryptopp-build)
find_package(CryptoPP REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

set(SOURCE_FILES src/main.cpp src/mainwindow.cpp src/mainwindow.h)

file(GLOB SOURCES "src/*.cpp")

add_library(Cryptolib SHARED ${SOURCES})
install(TARGETS Cryptolib DESTINATION /usr/lib)


add_executable(Cryptographer ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})
target_link_libraries(${CMAKE_PROJECT_NAME} cryptopp-shared)
target_link_libraries(${CMAKE_PROJECT_NAME} Cryptolib)

