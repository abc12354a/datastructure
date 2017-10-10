//
// Created by angus on 17-10-9.
//
#include "bstree.h"
#include <iostream>
using namespace std;
BsNode *CreateNode(Node *parent, Node *left, Node *right, Data value) {
    Node* node;
    node = new Node;
    node->value = value;
    node->parent = parent;
    node->right = right;
    node->left = left;
    return node;
}
BsTree Insert_Node(BsTree Tree, Node *node) {
    Node* X = Tree;
    Node* Y = nullptr;
    while(X!= nullptr){
        Y = X;
        if(X->value>node->value)
            X = X->left;
        else
            X = X->right;
    }
    node->parent = Y;
    if(Y->value>node->value)
        Y->left = node;
    else
        Y->right = node;
    return Tree;
}
BsTree Insert_Value(BsTree Tree, Data value) {
    auto node = CreateNode(nullptr, nullptr, nullptr,value);
    return Insert_Node(Tree,node);
}
void Pre_Order_Travel(BsTree Tree) {
    if(Tree != nullptr){
        cout<<Tree->value;
        Pre_Order_Travel(Tree->left);
        Pre_Order_Travel(Tree->right);
    }
}
