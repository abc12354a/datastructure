//
// Created by angus on 17-7-21.
//
#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;
using std::cin;
Tmatrix normult(Tmatrix A, Tmatrix B)
{
    Tmatrix C;
    int i,j,k,l,p,s;
    C.mu = A.mu;
    C.nu = B.nu;
    C.tu = 0;
    if(A.tu*B.tu != 0)
    {
        p = 0;
        for(i = 1;i<A.mu;++i)
        {
            for(j = 1;j<=B.nu;++j)
            {
                s = 0;
                for(k = 1;k<=A.nu;++k)
                {
                    s += value(A,i,k)*value(B,k,j);
                }
                if(s != 0){
                    C.data[p].i= i;
                    C.data[p].j= j;
                    C.data[p++].e= s;
                }
            }
        }
        C.tu = p;
    }
    return C;
}

int value(Tmatrix A, int i, int j) {
    int k = 0;
    while(k<A.tu&&A.data[k].i<=i)
    {
        if(A.data[k].i == i&& A.data[k].j == j)
        {
            return A.data[k].e;
        }
        k++;
    }
    return 0;
}

int createcross(crosslist *A) {
    int i, j, k, m, n, t;
    int flag;
    datatype e;
    Onode *q, *p;
    if (A->Rhead)
        return -1;
    do {
        flag = 1;
        cout << "input row, col, tu";
        cin >> m >> n >> t;
        if (m < 0 || n < 0 || t < 0 || t > m * n)
            flag = 0;

    } while (!flag);
    A->mu = m;
    A->tu = t;
    A->nu = n;
    A->Rhead = new Olink[m+1];
    A->Chead = new Olink[n+1];
    for (k = 1; k < m; ++k) {
        A->Rhead[k] = NULL;
    }
    for (k = 1; k < n; ++k) {
        A->Chead[k] = NULL;
    }
    for (k = 1; k <= t; ++k)
    {
        do {
            flag = 1;
            cout << "输入第" << k<<"个节点的行列和value"<<endl;
            cin>>i>>j>>e;
            if(i<=0||j<=0)
            flag = 0;
            } while (!flag);
        p = new Onode;
        p->i = i;
        p->j = j;
        p->e = e;
        if(A->Rhead[i]->j > j||A->Rhead == NULL)
        {
            p->right = A->Rhead[i];
            A->Rhead[i] = p;
        }
        else
        {
            for(q = A->Rhead[i];q->right != NULL&& q->right->j<j;q= q->right);
            p->right=q->right;
            q->right = p;
        }
        if(A->Chead[i] ==NULL||A->Chead[j]->i>i)
        {
            p->down = A->Chead[j];
            A->Chead[j] = p;
        }
        else
        {
            for(q=A->Chead[j]; q->down && q->down->i < i; q=q->down);
            p->down = q->down;
            q->down = p;
        }

    }
    return 1;
}



void CreateCrossList(pCrossList pCrossListTemp)
{
    //1.输入行数列数以及非零元个数
    cout<<"输入矩阵几行，几列，几个非零元素:\n";
    cin>>pCrossListTemp->iRow;
    cin>>pCrossListTemp->iCol;
    cin>>pCrossListTemp->nodeCount;
    if(pCrossListTemp->nodeCount > pCrossListTemp->iRow*pCrossListTemp->iCol)
    {
        return;
    }
    //2.动态申请行和列指针数组
    pCrossListTemp->RowHead = (pNode *)malloc(sizeof(pNode)*pCrossListTemp->iRow);
    if(pCrossListTemp->RowHead == NULL)
    {
        return;
    }
    pCrossListTemp->ColHead = (pNode *)malloc(sizeof(pNode)*pCrossListTemp->iCol);
    if(pCrossListTemp->ColHead == NULL)
    {
        free(pCrossListTemp->RowHead);
        return;
    }
    //3.初始化这两个数组
    int i,j;
    for(i = 0; i < pCrossListTemp->iRow; i++)
    {
        pCrossListTemp->RowHead[i] = NULL;
    }
    for(j = 0; j < pCrossListTemp->iCol; j++)
    {
        pCrossListTemp->ColHead[j] = NULL;
    }
    //4.创建节点并连接到十字链表上
    for(i = 0; i < pCrossListTemp->nodeCount; i++)
    {
        //4.1创建节点
        pNode pNodeTemp = (pNode)malloc(sizeof(Node));
        if(pNodeTemp == NULL)
        {
            return;
        }
        cout<<"输入 行 列 元素"<<endl;
        cin>>pNodeTemp->i;
        cin>>pNodeTemp->j;
        cin>>pNodeTemp->e;
        pNodeTemp->pDown = NULL;
        pNodeTemp->pRight = NULL;
        //4.2连接
        //连接行
        //如果该行并没有连接任何节点（NULL）或者该行连接的第一个节点的列值大于当前待连接的节点则直接将当前节点连接到该行第一个节点的位置
        if(pCrossListTemp->RowHead[pNodeTemp->i] == NULL || pCrossListTemp->RowHead[pNodeTemp->i]->j>pNodeTemp->j)
        {
            pNodeTemp->pRight = pCrossListTemp->RowHead[pNodeTemp->i];
            pCrossListTemp->RowHead[pNodeTemp->i] = pNodeTemp;
        }else//否则遍历该行找到合适的位置插入
        {
            pNode pNodeTravel = pCrossListTemp->RowHead[pNodeTemp->i];//指向第一个节点，从第一个节点开始遍历
            while(pNodeTravel->pRight != NULL && pNodeTravel->pRight->j < pNodeTemp->j)//遍历到前一个节点
            {
                pNodeTravel = pNodeTravel->pRight;
            }
            //连接
            pNodeTemp->pRight = pNodeTravel->pRight;
            pNodeTravel->pRight = pNodeTemp;
        }
        //连接列，逻辑跟连接行一致
        if(pCrossListTemp->ColHead[pNodeTemp->j]==NULL || pCrossListTemp->ColHead[pNodeTemp->j]->i>pNodeTemp->i)
        {
            pNodeTemp->pDown = pCrossListTemp->ColHead[pNodeTemp->j];
            pCrossListTemp->ColHead[pNodeTemp->j] = pNodeTemp;
        }else
        {
            pNode pNodeTravel = pCrossListTemp->ColHead[pNodeTemp->j];
            while(pNodeTravel->pDown != NULL && pNodeTravel->pDown->i < pNodeTemp->i)
            {
                pNodeTravel = pNodeTravel->pDown;
            }
            pNodeTemp->pDown = pNodeTravel->pDown;
            pNodeTravel->pDown = pNodeTemp;
        }
    }
}
void PrintCrossList(pCrossList pCrossListTemp)
{
    int i,j;
    pNode pTemp;
    for(i = 0; i < pCrossListTemp->iRow; i++)
    {
        pTemp = pCrossListTemp->RowHead[i];
        for(j = 0; j < pCrossListTemp->iCol; j++)
        {
            if(pTemp != NULL && pTemp->j == j)
            {
                cout<<pTemp->e<<" ";
                pTemp = pTemp->pRight;
            }else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

