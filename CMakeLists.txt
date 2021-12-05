cmake_minimum_required(VERSION 3.21)
project(Ftk)

set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
set(SOURCE_FILES main.cpp FormBase.cpp FormBase.h aes.cpp aes.h)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})