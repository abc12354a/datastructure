#include <cstring>
#include <iostream>
#include "huffman.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout<<"input data you want to encode"<<std::endl;
    auto data = new char;
    std::cin>>data;
    auto Dlength = strlen(data)-1;
    auto length = 0;
    auto Dict = new dict;
    auto code = TestTree(length,data,Dict);
    for(int i = 0;i<Dlength;i++){
        std::cout<<code[i];
    }
    std::cout<<std::endl;
    for(int i = 0;i<length;i++){
        std::cout<<"data:"<<Dict[i].value<<" code:"<<Dict[i].code<<std::endl;
    }
    return 0;
}