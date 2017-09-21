//
// Created by angus on 17-9-9.
//
#define MAXWEIGHT 1000
#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H
typedef struct Treenode{
    int weight;
    int parent;
    int left,right;
}*HTree;
typedef struct dict{
    char value;
    char* code;
}*Hdict;
typedef char** HC;
void Huffcode(HTree &Tree,HC& Code,int n, int* w);
void Select(HTree Tree,int n,int &s1,int &s2);
HC TestTree(int &length,char* data,Hdict &Dict);
void Decode(int* code);
int Count(char* X, int* w,char* ChList);
#endif //HUFFMAN_HUFFMAN_H
