#include <iostream>
#include "tree.h"
int main(int argc,char* argv[]) {
    bitnode* newtree;
    createtree(newtree);
    BFStravel(newtree);
//    TestQueue(newtree);
//    preorderprint(newtree,print);
//    cout<<endl;
//    postorderprint(newtree,print);
//    cout<<endl;
//    inorderprint(newtree,print);
//    cout<<endl;
//    pre_post(newtree,print);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}