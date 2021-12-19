cmake_minimum_required(VERSION 3.21)
project(GTKMM_Cryptographer)
set(CMAKE_CXX_STANDARD 17)
set(CryptoPP_DIR cryptopp-build)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
find_package(PkgConfig REQUIRED)
find_package(CryptoPP REQUIRED)
find_package(Git REQUIRED)
if (NOT EXISTS "${CMAKE_SOURCE_DIR}/cryptopp")
    execute_process(
            COMMAND "${GIT_EXECUTABLE}" clone https://github.com/weidai11/cryptopp.git
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
    execute_process(
            COMMAND "wget" -O CMakeLists.txt https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/CMakeLists.txt
            COMMAND "wget" -O cryptopp-config.cmake https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/cryptopp-config.cmake
    )
endif()
#set(CMAKE_SKIP_INSTALL_RULES TRUE)
endif()

pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

add_subdirectory(src)

#install
#headers = /usr/local/include/<PACOTE>
#targets = /usr/local/lib/<PACOTE>
