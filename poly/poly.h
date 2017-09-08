//
// Created by angus on 17-7-23.
//

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
typedef int datatype;
typedef struct poly
{
    struct poly* next;
    int c;
    int e;
}*linkedlist;
struct node
{
    node* next;
    datatype e;
};
void creat(linkedlist& P,int m);
bool destroy(linkedlist& P);
void printpoly(const linkedlist P);
int length(const linkedlist P);
linkedlist add(linkedlist& A,linkedlist& B);
bool sub(linkedlist& A,linkedlist& B);
bool multiply(linkedlist& A,linkedlist& B);


node* initnode();
void  shownode(node* A);
bool inverse(node *&A);
#endif