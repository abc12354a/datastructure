//
// Created by angus on 17-8-26.
// Updated by angus on 17-10-17.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
//链式栈
//C99标准没有引用
typedef int DataType;
typedef struct StackNode{
    DataType Value;
    struct StackNode* Next;
}*NodePtr,StackNode;
typedef struct LinkStack{
    NodePtr Top;
    int Count;
}LinkStack;
void InitStack(LinkStack* mStack);
bool PushStack(LinkStack* mStack,DataType e);
bool PopStack(LinkStack* mStack,DataType *e);
bool IsEmpty(LinkStack mStack);
void TestStackFun();
#endif //STACK_STACK_H
