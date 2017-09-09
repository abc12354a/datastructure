//
// Created by angus on 17-9-9.
//

#include "huffman.h"
#include <iostream>
#include <cstring>
void Select(HTree Tree, int n, int &s1, int &s2) {
    for(int i = 1;i<=n;++i){
        s1 = 1;
        if(Tree[i].weight<Tree[s1].weight)
            s1 = i;
    }
    for(int i = 1;i<=n;++i){
        s2 = (s1+1)%n;
        if((Tree[i].weight<Tree[s1].weight)&&i!=s1)
            s1 = i;
    }
}

void Huffcode(HTree &Tree, HC &Code, int *w, int n) {
    if(n<1)
        return;
    auto m = 2*n-1;
    Tree = new Treenode[m+1];
    auto p = Tree;
    for(int i = 1;i<=n;++i,++p,++w)
        *p = {*w,0,0,0};
    for(int j = n;j<=m;++j,++p)
        *p = {0,0,0,0};
    for(int k = n+1;k<=m;++k){
        int s1 = 0;
        int s2 = 0;
        Select(p,k-1,s1,s2);
        Tree[s1].parent = k;
        Tree[s2].parent = k;
        Tree[k].weight = Tree[s1].weight+Tree[s2].weight;
        Tree[k].left = s1;
        Tree[k].right = s2;
    }
    Code = new char[n+1];
    auto cd = new char[n];
    cd[n-1] = '\0';
    for(int i = 1;i<=n;++i){
        auto start = n-1;
        auto c = i;
        auto f = Tree[i].parent;
        for(;f!=0;c=f,f=Tree[f].parent){
            if(Tree[f].left==c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        strcpy(&Code[i],&cd[start]);
    }
}
