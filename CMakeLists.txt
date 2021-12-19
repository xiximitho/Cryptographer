cmake_minimum_required(VERSION 3.21)
project(GTKMM_Cryptographer)
set(CMAKE_CXX_STANDARD 17)
#set(CryptoPP_DIR cryptopp-build)

find_package(PkgConfig REQUIRED)
find_package(CryptoPP REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

add_subdirectory(src)

#install
#headers = /usr/local/include/<PACOTE>
#targets = /usr/local/lib/<PACOTE>
