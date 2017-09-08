//
// Created by angus on 17-7-21.
//
#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#define MAXSIZE 125
#define MAXRC 25
typedef int datatype;
typedef int ElemType;
using std::cout;
using std::endl;
typedef struct _NODE_
{
    int i,j;//行和列下标
    ElemType e;//元素值

    struct _NODE_ *pRight;
    struct _NODE_ *pDown;
}Node,*pNode;
typedef struct _CROSSLIST_
{
    pNode *RowHead,*ColHead;//行和列链表头指针向量
    int iRow,iCol,nodeCount;//矩阵行数，列数，非零元个数
}CrossList,*pCrossList;
struct triple
{
    int i,j;//行,列
    datatype e;
//    triple* down,* right;
};
typedef struct Onode
{
    int i,j;//行,列
    datatype e;
    Onode *down, *right;
}*Olink;
struct Tmatrix
{
    triple data[MAXSIZE+1];
    int rpos[MAXRC+1];
    int tu,mu,nu;//非零,行,列
};
struct crosslist
{
    Olink *Rhead, * Chead;
    int mu,nu,tu;
};
Tmatrix normult(Tmatrix A,Tmatrix B);
int value(Tmatrix A,int i,int j);
int createcross(crosslist *A);
void CreateCrossList(pCrossList pCrossListTemp);//创建十字链表
void PrintCrossList(pCrossList pCrossListTemp);//打印十字链表
//------------------------------------------------
#endif //MATRIX_MATRIX_H
