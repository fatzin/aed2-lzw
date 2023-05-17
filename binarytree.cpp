#include "binarytree.h"
#include <string>

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Insere um nó na árvore binária com base na sequência de caracteres
// '0' representa a ramificação à esquerda, '1' representa a ramificação à direita
void insert(Node* raiz, int chave, std::string valor) {
    Node* noAtual = raiz;
    for (char ch : valor) {
        if (ch == '0') {
            // Verifica se a ramificação à esquerda não existe e cria um novo nó se necessário
            if (!noAtual->left)
                noAtual->left = createNode(-1);
            noAtual = noAtual->left;
        } else {
            // Verifica se a ramificação à direita não existe e cria um novo nó se necessário
            if (!noAtual->right)
                noAtual->right = createNode(-1);
            noAtual = noAtual->right;
        }
    }
    noAtual->key = chave;
}

// Pesquisa um valor na árvore binária com base na sequência de caracteres
// '0' representa a ramificação à esquerda, '1' representa a ramificação à direita
int search(Node* raiz, std::string valor) {
    Node* noAtual = raiz;
    for (char ch : valor) {
        if (ch == '0') {
            // Retorna a chave do nó atual se a ramificação à esquerda não existir
            if (!noAtual->left)
                return noAtual->key;
            noAtual = noAtual->left;
        } else {
            // Retorna a chave do nó atual se a ramificação à direita não existir
            if (!noAtual->right)
                return noAtual->key;
            noAtual = noAtual->right;
        }
    }
    return noAtual->key;
}
