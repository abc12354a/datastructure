#include <cstring>
#include <iostream>
#include "huffman.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout<<"input data you want to encode"<<std::endl;
    auto data = new char;
    std::cin>>data;
    auto length = 0;
    auto code = TestTree(length,data);
    for(int i = 0;i<length;i++){
        std::cout<<code[i];
    }
    return 0;
}