#include <iostream>
#include "huffman.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    auto code = TestTree();
    for(int n = 1;n<=10;n++)
    {
        std::cout<<code[n]<<std::endl;
    }
//    my* mynode = new my[10];
//    for(int i = 0;i<10;++i){
//        mynode[i].weight = 100-2*i;
//    }
//    int s1 = 0,s2 = 0;
//    Test(mynode,10,s1,s2);
//    std::cout<<s1<<" "<<s2<<std::endl;
    return 0;
}