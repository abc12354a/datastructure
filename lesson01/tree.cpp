#include "tree.h"
#include <iostream>
using namespace std;
//
// Created by angus on 17-8-30.
//
struct treenode{
    datatype data;
    searchtree left;
    searchtree right;
    int Lflag;
    int Rflag;
};
searchtree prenode;
position Find(datatype x, searchtree T) {
    if (T == nullptr)
        return nullptr;
    if (x < T->data)
        return Find(x, T->left);
    else if (x > T->data)
        return Find(x, T->right);
    else
        return T;
}
position FindMax(searchtree T) {
    if(T == nullptr)
        return nullptr;
    else if(T->left == nullptr)
        return T;
    else
        return FindMax(T->left);
}
position FindMin(searchtree T) {
    if(T != nullptr)
        while (T->right != nullptr)
            T = T->right;
    return T;
}
searchtree MakeEmpty(searchtree T) {
    if(T != nullptr){
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        delete T;
    }
    return nullptr;
}
searchtree Insert(datatype x, searchtree T) {
    if(T == nullptr){
        T = new treenode;
        T->data = x;
        T->right = T->left = nullptr;
    }
    else if(x<T->data)
        T->left = Insert(x,T->left);
    else if(x>T->data)
        T->right = Insert(x,T->right);
    return T;
}
searchtree Delete(datatype x, searchtree T) {

}
searchtree Create() {
    //angus edition;
    datatype data;
    cout<<"plz input data"<<endl;
    cin>>data;
    if(data == '@')
        return nullptr;
    if(data != '@')
    {
        auto node = new treenode;
        node->data= data;
        node->left = Create();
        node->right = Create();
        return node;
    }
    //plus=>query binary tree;
//        searchtree bt = nullptr;
//        datatype ch;
//        cin>>ch;
//        if (ch != '@')
//        {
//            bt = new treenode;
//            bt->data = ch;
//            bt->left = Create();
//            bt->right = Create();
//        }
//        return bt;
}
void Travel_Pre(searchtree T) {
    if(T != nullptr){
        auto print = [T]()->void{std::cout<<" "<<T->data<<" ";};
        print();
        Travel_Pre(T->left);
        Travel_Pre(T->right);
    }
}
void Thread_Travel_Inoder(searchtree T){
    auto temp = T->left;
    while(temp != T) {
        while (temp->Lflag == 0) {
            temp = temp->left;
        }
        while (temp->right != T && temp->Rflag == 1) {
            cout << "  " << temp->data << "  ";
            temp = temp->right;
        }
    }
}
//线索二叉树
void InTreading(searchtree T){
    if(T != nullptr){
        InTreading(T->left);
        if(T->left != nullptr){
            T->Lflag = 1;
            T->left = prenode;
        }
        if(prenode->right != nullptr){
            prenode->Rflag = 1;
            prenode->right = T;
        }
        prenode = T;
        InTreading(T->right);
    }
}