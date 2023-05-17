#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

struct Node {
    int chave;
    std::string valor;
    Node* esquerda;
    Node* direita;
};

// Cria um novo nó com a chave e valor.
Node* createNode(int chave, std::string valor);

// Retorna a altura do nó especificado na árvore.
int height(Node* node);

// Realiza uma rotação para a esquerda e retorna o novo nó raiz.
Node* rotateLeft(Node* x);

// Realiza uma rotação para a direita e retorna o novo nó raiz.
Node* rotateRight(Node* y);

// Insere um novo nó com a chave e valor nó raiz e retorna o novo nó raiz.
Node* insert(Node* raiz, int chave, std::string valor);

// Libera a memória ocupada pela árvore.
void destroyTree(Node* node);

// Procura na árvore o nó com a chave e retorna o nó encontrado.
Node* search(Node* raiz, int chave);

#endif
