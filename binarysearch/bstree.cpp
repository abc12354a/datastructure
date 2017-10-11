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
        cout<<" "<<Tree->value;
        Pre_Order_Travel(Tree->left);
        Pre_Order_Travel(Tree->right);
    }
}

void In_Order_Travel(BsTree Tree) {
    if(Tree != nullptr){
        In_Order_Travel(Tree->left);
        cout<<" "<<Tree->value;
        In_Order_Travel(Tree->right);
    }
}

void Post_Order_Travel(BsTree Tree) {
    if(Tree != nullptr){
        In_Order_Travel(Tree->left);
        In_Order_Travel(Tree->right);
        cout<<" "<<Tree->value;
    }
}

Node *BsTree_Max(BsTree Tree) {
    auto X = Tree;
    while(X->right != nullptr){
        X = X->right;
    }
    return X;
}
void print_bstree(BsTree tree, Data key, int direction)
{
    if(tree != nullptr)
    {
        if(direction==0)    // tree是根节点
            printf("%2d is root\n", tree->value);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->value, key, direction==1?"right" : "left");

        print_bstree(tree->left, tree->value, -1);
        print_bstree(tree->right,tree->value,  1);
    }
}

Node *BsTree_Mini(BsTree Tree) {
    auto X = Tree;
    while(X->left != nullptr){
        X = X->left;
    }
    return X;
}

Node *BsTree_Search(BsTree Tree, Data value) {
    auto X = Tree;
    while (X != nullptr&&X->value!=value){
        if(X->value>value)
            X=X->left;
        else
            X=X->right;
    }
    if(X== nullptr)
        return CreateNode(nullptr, nullptr, nullptr,-1);
    else
        return X;
}

BsTree Del_Node(BsTree Tree, Node *node) {
    
}
Node *Predecer_BsTree(Node *node) {
    if(node->left!= nullptr)
        return BsTree_Max(node->left);
    Node* Pnode = node->parent;
    while((Pnode!= nullptr) && (node == Pnode->left)){
        node = Pnode;
        Pnode = Pnode->parent;
    }
    return Pnode;
}
Node *Postdecer_BsTree(Node *node) {
    if(node->right!= nullptr)
        return  BsTree_Mini(node->right);
    Node* Pnode = node->parent;
    while((Pnode!= nullptr)&&(node==Pnode->right)){
        node = Pnode;
        Pnode = Pnode->parent;
    }
    return Pnode;
}
