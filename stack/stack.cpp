//
// Created by angus on 17-8-26.
//
#include <iostream>
#include "stack.h"
using namespace std;

//function:Init a Stack and set Top Value as 0;
void InitStack(LinkStack *mStack) {
    NodePtr mElement = (NodePtr) malloc(sizeof(StackNode));
    mStack = (LinkStack *) malloc(sizeof(LinkStack));
    mElement->Next = nullptr;
    mElement->Value = 0;
    mStack->Count = 0;
    mStack->Top = mElement;
}

bool PushStack(LinkStack *mStack, DataType e) {
    NodePtr mElement = (NodePtr) malloc(sizeof(StackNode));
    if (mElement == nullptr)
        return false;
    mElement->Value = e;
    mElement->Next = mStack->Top;
    mStack->Top = mElement;
    mStack->Count++;
    return true;
}

bool PopStack(LinkStack *mStack, DataType *e) {
    NodePtr mElement;
    if (IsEmpty(*mStack))
        return false;
    *e = mStack->Top->Value;
    mElement = mStack->Top;
    mStack->Top = mStack->Top->Next;
    free(mElement);
    mStack->Count--;
    return true;
}

bool IsEmpty(LinkStack mStack) {
    if (mStack.Count == 0)
        return true;
    return false;
}

void TestStackFun() {
    LinkStack *Stack;
    InitStack(Stack);
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        PushStack(Stack, a[i]);
    }
    for (int i = 0; i < 10; ++i) {
        int *k = (int*)malloc(sizeof(int));
        if(!PopStack(Stack,k))
            std::cout<<"error"<<i;
        else
            std::cout<<*k<<" ";
    }
}
