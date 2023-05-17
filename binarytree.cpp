#include "binarytree.h"

// Cria um novo nó com a chave e valor.
Node* createNode(int chave, std::string valor) {
    Node* node = new Node();
    node->chave = chave;
    node->valor = valor;
    node->esquerda = nullptr;
    node->direita = nullptr;
    return node;
}

// Retorna a altura do nó especificado na árvore.
int height(Node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int lheight = height(node->esquerda);
        int rheight = height(node->direita);
        if (lheight > rheight) {
            return lheight + 1;
        } else {
            return rheight + 1;
        }
    }
}

// Realiza uma rotação para a esquerda e retorna o novo nó raiz.
Node* rotateLeft(Node* x) {
    Node* y = x->direita;
    Node* T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    return y;
}

// Realiza uma rotação para a direita e retorna o novo nó raiz.
Node* rotateRight(Node* y) {
    Node* x = y->esquerda;
    Node* T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    return x;
}

// Insere um novo nó com a chave e valor nó raiz e retorna o novo nó raiz.
Node* insert(Node* raiz, int chave, std::string valor) {
    if (raiz == nullptr) {
        return createNode(chave, valor);
    }
    if (chave < raiz->chave) {
        raiz->esquerda = insert(raiz->esquerda, chave, valor);
    } else if (chave > raiz->chave) {
        raiz->direita = insert(raiz->direita, chave, valor);
    }
    int balanceamento = height(raiz->esquerda) - height(raiz->direita);
    if (balanceamento > 1 && chave < raiz->esquerda->chave) {
        return rotateRight(raiz);
    }
    if (balanceamento < -1 && chave > raiz->direita->chave) {
        return rotateLeft(raiz);
    }
    if (balanceamento > 1 && chave > raiz->esquerda->chave) {
        raiz->esquerda = rotateLeft(raiz->esquerda);
        return rotateRight(raiz);
    }
    if (balanceamento < -1 && chave < raiz->direita->chave) {
        raiz->direita = rotateRight(raiz->direita);
        return rotateLeft(raiz);
    }
    return raiz;
}

// Libera a memória ocupada pela árvore.
void destroyTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroyTree(node->esquerda);
    destroyTree(node->direita);

    delete node;
}

// Procura na árvore o nó com a chave e retorna o nó encontrado.
Node* search(Node* raiz, int chave) {
    if (raiz == nullptr || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return search(raiz->esquerda, chave);
    } else {
        return search(raiz->direita, chave);
    }
}
