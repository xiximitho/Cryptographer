//
// Created by felipe on 05/12/2021.
//

#ifndef FTK_AES_H
#define FTK_AES_H

#include <cinttypes>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <glibmm.h>
using namespace Glib;

class aes {
public:
    static std::string crypt(std::string key, std::string iv, std::string txt);
    static std::string decrypt(std::string key, std::string iv, std::string txt);
    static void cryptFile(std::string key, std::string iv, std::string path);
};


#endif //FTK_AES_H
