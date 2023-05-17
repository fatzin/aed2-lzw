#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key);
void insert(Node* raiz, int chave, std::string valor);
int search(Node* raiz, std::string valor);

#endif // BINARYTREE_H
