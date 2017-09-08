//
// Created by angus on 17-7-23.
//
#include "list.h"
#include <iostream>
//-------------------------------------------------
//hanoi problem
void hanoi(int n, char x, char y, char z) {
    if(n == 1)
    {
        move(x,z,n);

    }
    else
    {
        hanoi(n-1,x,z,y);
        move(x,z,n);
        hanoi(n-1,y,x,z);
    }
}
void move(char s, char d,int n) {
    cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
 /* cout<<"  | |"<<"      | |"<<"       | |"<<endl;
    cout<<"  ###"<<"      | |"<<"       | |"<<endl;
    cout<<" #####"<<"     | |"<<"       | |"<<endl;
    cout<<"#######"<<"    | |"<<"       | |"<<endl;*/
}
//-------------------------------------------------


//求深度
int GListdepth(GList L) {
    if(!L)
        return 1;//node return 1
    if(L->tag == _DATA_)//data return 0
        return 0;
    GList pp;
    int max;
    for(max=0,pp=L;pp!=NULL;pp=pp->ptr.tp)
    {
        int dep = GListdepth(pp->ptr.hp);
        if(dep>max)
            max = dep;
    }
    return max+1;
}

GList* GListcreate() {

}

int GListcopy(GList L, GList &newL) {
    if(!L)
        newL = NULL;
    else
    {
        newL = new GLnode;
        newL->tag = L->tag;
        if(L->tag == _DATA_)
            newL->atom = L->atom;
        else
        {
            GListcopy(L->ptr.hp,newL->ptr.hp);
            GListcopy(L->ptr.tp,newL->ptr.tp);
        }
    }

    return true;
}

