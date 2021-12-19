# Cryptographer

Projeto utilizando a biblioteca Crypto++ para a realização de criptografia de arquivos selecionados, informando chave de 16 bytes para encriptar e descriptar.

### 📋 Pré-requisitos
É necessário o uso da ferramenta CMake e Make utilizando o CLang ou GCC para a instalação.

O projeto foi construido utilizando a api gtkmm-4.0, instale de acordo com sua distro. <br>
```
Ubuntu: apt-get install libgtkmm-4.0-dev cmake make clang
```
```
Manjaro: pamac install gtkmm-4.0 cmake make clang 
```
```
Fedora: dnf install gtkmm4.0-devel cmake make clang 
```

### 🔧 Instalação

1. Clone o repostório
   ```sh
   git clone https://github.com/xiximitho/Cryptographer.git
   ```
2. Crie a pasta em que será realizado a compilação.
   ```sh
   cd Cryptographer && mkdir build && cd build
   ```
3. Gere os arquivos para realização do Make e Make install (CMake sempre pega o diretório atual para geração)
   ```sh
   CMake ..
   ```   
4. Compilação dos arquivos
   ```sh
   make && make install
   ```
