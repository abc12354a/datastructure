//
// Created by angus on 17-9-9.
//

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
void Huffcode(HTree &Tree,HC& Code,int n);
void Select(HTree Tree,int n,int &s1,int &s2);
HC TestTree();
void Test(my* Tree, int n, int &s1, int &s2);
#endif //HUFFMAN_HUFFMAN_H
