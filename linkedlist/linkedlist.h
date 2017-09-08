//
// Created by angus on 17-8-23.
//
/*
 * readme:revise the datatype and visit function to modify.
 * to solve arguments problem, try va_list.
 */
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#define MAXSIZE 100
typedef int datatype;
struct node{
    datatype data;
    datatype power;
    node* pre;
    node* next;
};
int length(node* list);
node* createlist();
node* createpowerlist();
node* multi(node* list1,node* list2);
node* reserve(node* list);
node* powerplus(node* list1,node* list2);
bool add(datatype e,int index,node* list);
bool isempty(node* list);
void travel(node* list,void visit(datatype e));
void powertravel(node* list,void visit(datatype e,datatype ee));
void powerprint(datatype e,datatype ee);
void print(datatype e);
datatype del(int index,node* list);
#endif //LINKEDLIST_LINKEDLIST_H
