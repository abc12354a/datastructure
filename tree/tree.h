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
struct queue{
    int front;
    int rear;
    bitree* base;
    int queueszie;
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
void initqueue(queue &q);
void in_queue(queue& q,bitree queue_in);
void out_queue(queue& q,bitree &queue_out);
bool isqempty(queue q);
bitree getfront(queue q);
void BFStravel(bitnode* T);
void TestQueue(bitnode* T);
#endif //TREE_TREE_H
