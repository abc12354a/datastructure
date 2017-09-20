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
struct my{
    int weight;
};
typedef char** HC;
void Huffcode(HTree &Tree,HC& Code,int n, int* w);
void Select(HTree Tree,int n,int &s1,int &s2);
HC TestTree(int &length);
void Test(my* Tree, int n, int &s1, int &s2);
void Decode(int* code);
int Count(char* X, int* w);
#endif //HUFFMAN_HUFFMAN_H
