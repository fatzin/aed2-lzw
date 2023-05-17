#include "decompressLZW.h"
#include "binarytree.h"

#include <unordered_map>
#include <sstream>

std::string descomprimirLZW(const std::string& comprimido) {
    std::unordered_map<int, std::string> dicionario;
    int proximoIndice = 256; // Começa com os valores ASCII 0-255

    // Inicializa o dicionário com os valores ASCII 0-255
    for (int i = 0; i < 256; i++) {
        //converte o valor inteiro i para o seu equivalente em caractere ASCII.
        //atribui a string criada ao dicionário, associando ao índice i. Isso significa que o valor ASCII i será mapeado para a string correspondente.
        dicionario[i] = std::string(1, static_cast<char>(i));
    }

    std::stringstream entrada(comprimido);
    std::string token;
    std::string descomprimido;
    std::string prefixo;
    std::string anterior;

    while (entrada >> token) {
        //stoi transforma string em int
        int indice = std::stoi(token);

        std::string atual;
        if (dicionario.find(indice) != dicionario.end()) {
            atual = dicionario[indice];
        } else if (indice == proximoIndice) {
            atual = prefixo + prefixo[0];
        }

        descomprimido += atual;

        if (!anterior.empty()) {
            dicionario[proximoIndice++] = anterior + atual[0];
        }

        anterior = atual;
        prefixo = atual;
    }

    return descomprimido;
}
