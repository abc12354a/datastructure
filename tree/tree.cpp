//
// Created by angus on 17-7-27.
//

#include "tree.h"
//前序创建
bool createtree(bitree& T) {
    datatype input;
    cin>>input;
    if(input == '@')
        T = nullptr;
    else
    {
        T = new bitnode;
        T->data = input;
        createtree(T->lchild);
        createtree(T->rchild);
    }
    return true;
}
//function as argment
int print(datatype data) {
    cout<<data;
    return OK;
}
bool preorderprint(bitnode* T,int(*visit)(datatype data)) {
    if(T)
    {
        //return 1 if printf the data successfully
        if(T->data){
            //cout<<"@root data is     ";
            visit(T->data);
            //cout<<"    @";
            }
            if(T->lchild)
                preorderprint(T->lchild,visit);
            if(T->rchild)
                preorderprint(T->rchild,visit);
    }
    else
        return true;
}
bool inorderprint(bitnode* T,int(*visit)(datatype data)) {
    if(T) {
        if (T->lchild) {
            inorderprint(T->lchild, visit);
            //cout<<"@  in-lchirld "<<T->lchild->data<<"   @";
        }
        visit(T->data);
        if (T->rchild) {
            inorderprint(T->rchild, visit);
            //cout<<"@  in-rchirld "<<T->rchild->data<<"   @";
        }
    }
    else
        return true;
}
bool postorderprint(bitnode* T,int(*visit)(datatype data)) {
    if(T) {
        if (T->lchild)
            postorderprint(T->lchild,visit);
        if (T->rchild)
            postorderprint(T->rchild,visit);
        visit(T->data);
    }
    else
        return true;
}
void initstack(stack& s) {
    s.base = new bitree[STACK_SIZE_INIT];
    if(!s.base)
        std::cout<<"failed"<<std::endl;
    s.top = s.base;
    s.stacksize = STACK_SIZE_INIT;

}
bool push(stack &s, bitree stack_in) {
    if(s.top-s.base >= s.stacksize)
    {
        s.base = (bitree*)realloc(s.base,(s.stacksize+STACK_INCRENCENT)*sizeof(bitree));
        s.top = s.base + s.stacksize;
        s.stacksize += STACK_INCRENCENT;
    }
    *s.top = stack_in;
    s.top += 1;
    return true;
}
bool pop(stack &s, bitree &stack_out) {
    if(s.base == s.top)
        return false;
    else
    {
        s.top -= 1;
        stack_out = *s.top;
        return true;
    }
}
bool isempty(stack& s) {
    if(s.top == s.base)
        return true;
    else
        return false;
}
bitree gettop(stack s) {
    if(s.top == s.base)
        ;//exit(OVERFLOW);
    else
    {
        bitree top;
        return top = *(s.top-1);
    }
}
//travel without recursion
/*
1）输出节点P，然后将其入栈，再看P的左孩子是否为空；
2）若P的左孩子不为空，则置P的左孩子为当前节点，重复1）的操作；
3）若P的左孩子为空，则将栈顶节点出栈，但不输出，并将出栈节点的右孩子置为当前节点，看其是否为空；
4）若不为空，则循环至1）操作；
5）如果为空，则继续出栈，但不输出，同时将出栈节点的右孩子置为当前节点，看其是否为空，重复4）和5）操作；
6）直到当前节点P为NULL并且栈空，遍历结束。
*/
void pre_post(bitnode *T, int (*visit)(datatype)) {
    stack tstack;
    initstack(tstack);
    bitnode* node_pop;
    bitnode* pcur = T;
    while(pcur||!isempty(tstack))
    {
        visit(pcur->data);
        push(tstack,pcur);
        pcur = pcur->lchild;
        while(!pcur&&!isempty(tstack))
        {
            pcur = gettop(tstack);
            pop(tstack,node_pop);
            pcur=pcur->rchild;
        }
    }
}

void initqueue(queue &q) {
    q.front = new bitree[STACK_SIZE_INIT];
    if(!q.front)
        std::cout<<"init failed"<<std::endl;
    q.rear = q.front;
    q.queueszie = STACK_SIZE_INIT;
}
void in_queue(queue &q, bitree queue_in) {
    *q.rear = queue_in;
    q.rear++;
}
void out_queue(queue &q, bitree &queue_out) {
    queue_out = *q.front;
    q.front++;
}
bool isqempty(queue q) {
    if(q.front == q.rear)
        return true;
    else
        return false;
}
bitree getfront(queue q) {
    if(!isqempty(q))
        return *q.front;
    return nullptr;
}
void BFStravel(bitree *T) {
}

