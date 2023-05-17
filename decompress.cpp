#include "decompress.h"
#include "binarytree.h"

#include <unordered_map>
#include <sstream>

std::string descomprimirLZW(const std::string& comprimido) {
    std::unordered_map<int, std::string> dicionario;
    int proximoIndice = 256;  // Começar com os valores ASCII de 0 a 255

    // Inicializar a árvore binária
    Node* raiz = createNode(-1);
    for (int i = 0; i < 256; i++) {
        std::string ch(1, static_cast<char>(i));
        dicionario[i] = ch;
        insert(raiz, i, ch);
    }

    std::stringstream entrada(comprimido);
    std::string token;
    std::string anterior;
    std::stringstream descomprimido;

    while (entrada >> token) {
        //stoi transforma string em int
        int atual = std::stoi(token);

        std::string entrada;
        if (dicionario.find(atual) != dicionario.end()) {
            entrada = dicionario[atual];
        } else if (atual == proximoIndice) {
            entrada = anterior + anterior[0];
        }

        descomprimido << entrada;
        if (!anterior.empty()) {
            dicionario[proximoIndice++] = anterior + entrada[0];
            insert(raiz, proximoIndice - 1, dicionario[proximoIndice - 1]);
        }
        anterior = entrada;
    }

    return descomprimido.str();
}
