//
// Created by angus on 17-8-26.
//
#include <iostream>
#include "stack.h"
using namespace std;
template <class T>
bool SeqStack<T>::IsFull() const {
    return (top == maxsize-1)?true: false;
}
template <class T>
bool SeqStack<T>::Isempty() const {
    return (top == -1)?true:false;
}
template <class T>
SeqStack<T>::SeqStack(int size):maxsize(size),top(-1) {
    element = new T[maxsize];
}
template <class T>
void SeqStack<T>::Push(T x) {
    if(IsFull())
        overflow();
    else
        element[++top] = x;
}
template <class T>
void SeqStack<T>::overflow() {
    T *t = new T[maxsize+INCREMENT];
    for (int i = 0; i < top ; ++i)
        t[i] = element[i];
    maxsize += INCREMENT;
    delete []element;
    element = t;
}
template <class T>
T SeqStack<T>::GetTop() const {
    if(Isempty())
        return -1;
    else
        return element[top];
}
template <class T>
T SeqStack<T>::Pop() {
    if(Isempty())
        return -1;
    else{
        return element[top--];
    }
}
template <class T>
int SeqStack<T>::GetSize() const {
    if(Isempty())
        return 0;
    else if(IsFull())
        return maxsize;
    else{
        return top+1;
    }
}
template <class T>
void SeqStack<T>::Makempty() {
    top = -1;
}