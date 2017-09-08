//
// Created by angus on 17-7-27.
//
#ifndef TREE_TREE_H
#define TREE_TREE_H
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define MAX_TREE_SIZE 100
#define STACK_SIZE_INIT 100
#define STACK_INCRENCENT 10
#define OK 1
#define T_ERROR 0
typedef char datatype;

typedef struct bitnode
{
    datatype data;
    bitnode *lchild,*rchild;
}*bitree;
struct stack
{
    bitree* base;
    bitree* top;
    int stacksize;
};
int print(datatype data);
bool createtree(bitree& T);
bool preorderprint(bitnode* T,int(*visit)(datatype data));
bool inorderprint(bitnode* T,int(*visit)(datatype data));
bool postorderprint(bitnode* T,int(*visit)(datatype data));
void initstack(stack& s);
bool push(stack& s,bitree stack_in);
bool pop(stack& s,bitree& stack_out);
bool isempty(stack& s);
void pre_post(bitnode* T,int(*visit)(datatype data));
bitree gettop(stack s);
#endif //TREE_TREE_H
