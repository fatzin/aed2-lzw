#include "lzw.h"
#include "binarytree.h"

#include <unordered_map>
#include <sstream>

std::string comprimirLZW(const std::string& entrada) {
    std::unordered_map<std::string, int> dicionario;
    int proximoIndice = 256; // Começa com os valores ASCII 0-255

    // Inicializa a árvore binária
    Node* raiz = createNode(-1, "");
    for (int i = 0; i < 256; i++) {
        //converte o valor inteiro i para o seu equivalente em caractere ASCII.
        //atribui a string criada ao dicionário, associando ao índice i. Isso significa que o valor ASCII i será mapeado para a string correspondente.
        std::string ch(1, static_cast<char>(i));
        dicionario[ch] = i;
        insert(raiz, i, ch);
    }

    std::string prefixo;
    std::stringstream comprimido;

    // a árvore é usada para armazenar o dicionário de sequências encontradas durante a compressão.
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

    // Liberar a memória da árvore após a compressão
    destroyTree(raiz);

    return comprimido.str();
}
