#include <iostream>
#include "huffman.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    auto code = TestTree();
    for(int n = 1;n<=10;n++)
    {
        std::cout<<code[n]<<std::endl;
    }
    return 0;
}