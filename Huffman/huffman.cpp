//
// Created by angus on 17-9-9.
//

#include "huffman.h"
#include <iostream>
#include <cstring>
//select function remand to fix;
void Select(HTree Tree, int n, int &s1, int &s2) {
    int m1 = MAXWEIGHT;
    int m2 = MAXWEIGHT;
    s1 = s2 = 0;
    for(int j = 0;j<n;++j){
        if(Tree[j].weight<m1&&Tree[j].parent == 0){
            m2 = m1;
            s2 = s1;
            m1 = Tree[j].weight;
            s1 = j;
        }
        else if(Tree[j].weight<m2&&Tree[j].parent == 0){
            m2 = Tree[j].weight;
            s2 = j;
        }
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
    for(int i = 0;i<n;++i)
    {
        int Tweight = 0;
        std::cout<<"plz input weight"<<std::endl;
        std::cin>>Tweight;
        Tree[i].weight =Tweight;
        Tree[i].parent =0;
        Tree[i].left =0;
        Tree[i].right =0;
    }
    for(int j = n;j<=m;++j)
    {
        Tree[j].weight = 0;
        Tree[j].parent = 0;
        Tree[j].left = 0;
        Tree[j].right = 0;
    }
    for(int k = n;k<m;++k){
        int s1 = 0;
        int s2 = 0;
        Select(Tree,k,s1,s2);
        //std::cout<<"第"<<k-n<<"次"<<s1<<" "<<s2<<"  ";
        Tree[s1].parent = k;
        Tree[s2].parent = k;
        Tree[k].weight = Tree[s1].weight+Tree[s2].weight;
        Tree[k].left = s1;
        Tree[k].right = s2;
    }
    //std::cout<<std::endl;
    for(int i = 0;i<=m;i++){
       // std::cout<<"第"<<i<<"个"<<Tree[i].weight<<" "<<Tree[i].parent<<"   ";
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
    std::cout<<"plz input size of data"<<std::endl;
    int CountN = 0;
    std::cin>>CountN;
    auto mytree = new Treenode;
    auto mycode = new char*;
    Huffcode(mytree,mycode,CountN);
    return  mycode;
}
