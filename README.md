## Cryptographer

### a versão inicial foi realizada utilizando CMake, e agora é utilizado o Meson pois a lib Crypto++ não era suportada pelo CMake, dando alguns conflitos.


deps: [ cryptopp, gtkmm4.0-dev(que inclui a Glib e Sigc++) ] <br>

Versões do GTK+ acima da 3.0 irão funcionar corretamente. (Não testado em versões inferiores a 4.0).

