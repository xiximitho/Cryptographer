//
// Created by felipe on 05/12/2021.
//

#include "aes.h"
#define TAMANHO_BLOCO_AES 16
#define TAMANHO_CHAVE 32

aes::aes() = default;

std::string aes::crypt(std::string key, std::string iv, std::string txt) {
    uint8_t UKey[TAMANHO_CHAVE];
    uint8_t UIv[TAMANHO_BLOCO_AES];

    std::copy(key.begin(), key.end(), std::begin(UKey));
    std::copy(iv.begin(), iv.end(), std::begin(UIv));

    auto* AesKey = new AES_KEY();
    AES_set_encrypt_key(UKey, 256, AesKey);


    /** preenche a string de entrada e coloca para caber em 16bytes (tamanho do bloco)**/
    unsigned int preenchimento = (TAMANHO_BLOCO_AES - (txt.length() % TAMANHO_BLOCO_AES));   // Calcula o preenchimento requirido
    std::vector<unsigned char> txtPreenchido(txt.begin(), txt.end());   // Preenchimento por vetor
    for(int i=0; i < preenchimento; i++){
        txtPreenchido.push_back(0); //  incrementa o tamanho da string
    }

    unsigned char * Data = &txtPreenchido[0];
    const int DataSize = (const int)txtPreenchido.size();// devido a api ser em C

    unsigned char EncryptedData[512] = {0}; // Hard-coded Array para o OpenSSL
    AES_cbc_encrypt(Data, EncryptedData, DataSize, (const AES_KEY*)AesKey, UIv, AES_ENCRYPT);

    //conversao para string;
    return reinterpret_cast<char*>(EncryptedData);
}

std::string aes::decrypt(std::string key, std::string iv, std::string txt) {
    uint8_t UKey[TAMANHO_CHAVE];
    uint8_t UIv[TAMANHO_BLOCO_AES];

    std::copy(key.begin(), key.end(), std::begin(UKey));
    std::copy(iv.begin(), iv.end(), std::begin(UIv));


    const int Tamanho = (const int)txt.size();

    AES_KEY* AesDecryptKey = new AES_KEY();
    AES_set_decrypt_key(UKey, 256, AesDecryptKey);


    unsigned char DecryptedData[512] = {0};
    AES_cbc_encrypt(reinterpret_cast<const unsigned char *> (txt.c_str()), DecryptedData, Tamanho, (const AES_KEY*)AesDecryptKey, UIv, AES_DECRYPT);

    return reinterpret_cast<char*>(DecryptedData);
}
