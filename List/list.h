//
// Created by angus on 17-7-23.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
#define _LIST_ 1
#define _DATA_ 0
#include <cstdarg>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
typedef int atomtype;
typedef struct GLnode
{
    int tag;//tag=1 or tag=0;
    //can't exist at the same time;
    union {
        atomtype atom;
        struct {
            GLnode *hp, *tp;
        }ptr;
        //union里不能含有non-static data.非静态数据.
    };
}*GList;
//---------------------------------------------
void hanoi(int n,char x,char y,char z);
void move(char s,char d,int n);
//---------------------------------------------
int GListdepth(GList L);
GList* GListcreate();
int GListcopy(GList L,GList& newL);
#endif //LIST_LIST_H
