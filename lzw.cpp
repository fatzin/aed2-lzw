#include "lzw.h"
#include "binarytree.h"

#include <unordered_map>
#include <sstream>

std::string comprimirLZW(const std::string& entrada) {
    std::unordered_map<std::string, int> dicionario;
    int proximoIndice = 256; // Começa com os valores ASCII 0-255

    // Inicializa a árvore binária
    Node* raiz = createNode(-1);
    for (int i = 0; i < 256; i++) {
        std::string ch(1, static_cast<char>(i));
        dicionario[ch] = i;
        insert(raiz, i, ch);
    }

    std::string prefixo;
    std::stringstream comprimido;

    for (char ch : entrada) {
        std::string atual = prefixo + ch;
        if (dicionario.find(atual) != dicionario.end()) {
            prefixo = atual;
        } else {
            comprimido << dicionario[prefixo] << ' ';
            dicionario[atual] = proximoIndice++;
            insert(raiz, dicionario[atual], atual);
            prefixo = ch;
        }
    }

    if (!prefixo.empty()) {
        comprimido << dicionario[prefixo] << ' ';
    }

    return comprimido.str();
}
