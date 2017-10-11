#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    auto root = CreateNode(nullptr, nullptr, nullptr,10);
    auto root_changed = new Node;
    root_changed = Insert_Value(root,1);
    for (int i = 0; i < 6; ++i) {
        root_changed = Insert_Value(root_changed,i*2+5);
    }
    Pre_Order_Travel(root_changed);
    cout<<endl;
    In_Order_Travel(root_changed);
    cout<<endl;
    Post_Order_Travel(root_changed);
    cout<<endl;
    cout<<BsTree_Max(root_changed)->value<<"   ";
    cout<<BsTree_Search(root_changed,99)->value<<"  value:";
    cout<<root_changed->right->right->value<<"  ";
    cout<<Predecer_BsTree(root_changed->right->right)->value<<" ";
    cout<<Postdecer_BsTree(root_changed->right->right)->value<<endl;
    print_bstree(root_changed,0,0);
    return 0;
}