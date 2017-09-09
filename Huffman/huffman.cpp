//
// Created by angus on 17-9-9.
//

#include "huffman.h"
#include <iostream>
#include <cstring>
void Select(HTree Tree, int n, int &s1, int &s2) {
    s1 = 0;
    for(int i = 0;i<n;++i){
        if(Tree[i].weight<Tree[s1].weight&&(Tree[i].parent==0))
            s1 = i;
    }
    s2 = 0;
    for(int i = 0;i<n;++i){
        if((Tree[i].weight<Tree[s2].weight)&&i!=s1&&(Tree[i].parent==0))
            s2 = i;
    }
}
//void Test(my* Tree, int n, int &s1, int &s2) {
//    s1 = 0;
//    for(int i = 1;i<=n;++i){
//        if(Tree[i].weight<Tree[s1].weight)
//            s1 = i;
//    }
//    s2 = 0;
//    for(int i = 1;i<=n;++i){
//        if((Tree[i].weight<Tree[s2].weight)&&i!=s1)
//            s2 = i;
//    }
//}
void Huffcode(HTree &Tree, HC &Code, int n) {
    if(n<1)
        return;
    auto m = 2*n-1;
    Tree = new Treenode[m+1];
//    auto p = Tree;
    for(int i = 1;i<=n;++i)
    {
        Tree[i-1].weight = 11-i;
        Tree[i-1].parent =0;
        Tree[i-1].left =0;
        Tree[i-1].right =0;
    }
    for(int j = n+1;j<=m;++j)
    {
        Tree[j-1].weight = 0;
        Tree[j-1].parent =0;
        Tree[j-1].left =0;
        Tree[j-1].right =0;
    }
    for(int k = n+1;k<=m;++k){
        int s1 = 0;
        int s2 = 0;
        Select(Tree,k,s1,s2);
        Tree[s1].parent = k;
        Tree[s2].parent = k;
        Tree[k].weight = Tree[s1].weight+Tree[s2].weight;
        Tree[k].left = s1;
        Tree[k].right = s2;
    }
    Code = new char*[n+1];
    auto cd = new char[n];
    cd[n-1] = '\0';
    for(int i = 0;i<n;++i){
        int start = n-1;
        int c = i;
        int f = Tree[i].parent;
        for(;f!=0;c=f,f=Tree[f].parent){
            if(Tree[f].left==c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        //remember to make block request for elements of array;
        Code[i] = new char[n];
        strcpy(Code[i],&cd[start]);
    }
}

HC TestTree() {
    int CountN = 10;
    auto mytree = new Treenode;
    auto mycode = new char*;
    Huffcode(mytree,mycode,CountN);
    return  mycode;
}
