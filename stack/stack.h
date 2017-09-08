//
// Created by angus on 17-8-26.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#define MAX_SIZE 50
#define INCREMENT 20
template <class T>
class SeqStack {
    SeqStack(int size = MAX_SIZE);
    void Push(T x);
    void Makempty();
    bool Isempty()const;
    bool IsFull()const;
    int GetSize()const;
    T Pop();
    T GetTop()const;
    ~SeqStack(){delete []element;};
private:
    int maxsize;
    int top;
    T *element;
    void overflow();
};
#endif //STACK_STACK_H
