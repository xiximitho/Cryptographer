cmake_minimum_required(VERSION 3.21)
project(cryptographer)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_executable(cryptographer main.cpp)
