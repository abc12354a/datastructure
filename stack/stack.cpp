//
// Created by angus on 17-8-26.
//
#include <iostream>
#include "stack.h"
using namespace std;

//function:Init a Stack and set Top Value as 0;
void InitStack(LinkStack *mStack) {
    mStack = (LinkStack *) malloc(sizeof(LinkStack));
    mStack->Count = 0;
}
//some bugs remind to be fixed.
bool PushStack(LinkStack *mStack, DataType e) {
    NodePtr mElement = (NodePtr) malloc(sizeof(StackNode));
    if (mElement == nullptr)
        return false;
    mElement->Value = e;
    mElement->Next = mStack->Top;
    mStack->Top = mElement;
    mStack->Count++;
    //std::cout<<mStack->Top->Value<<" ";
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
//    LinkStack *Stack;
//    InitStack(Stack);
    LinkStack* Stack = (LinkStack*)malloc(sizeof(LinkStack));
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //std::cout<<"Pushing in";
    for (int i = 0; i < 10; i++) {
        //int *j = (int*)malloc(sizeof(int));
        PushStack(Stack, a[i]);
        //std::cout<<" i"<<a[i]<<" ";
        //GetTop(Stack,j);
        //std::cout<<*j<<" ";
        //free(j);
    }
    //std::cout<<"\n";
    for (int i = 0; i < 10; ++i) {
        int *k = (int*)malloc(sizeof(int));
        if(!PopStack(Stack,k))
            std::cout<<"error"<<i;
        else
            std::cout<<*k<<" ";
        free(k);
    }
}

bool GetTop(LinkStack *mStack, DataType *e) {
    if(IsEmpty(*mStack))
        return false;
    *e = mStack->Top->Value;
    return true;
}

void ClearStack(LinkStack *mStack) {
    DataType * Temp = (DataType*)malloc(sizeof(DataType));
    for(int i = 0;i<mStack->Count;++i){
        PopStack(mStack,Temp);
    }
}
