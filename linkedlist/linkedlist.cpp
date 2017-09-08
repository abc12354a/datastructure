//
// Created by angus on 17-8-23.
//

#include "linkedlist.h"
#include <iostream>
using namespace std;
node *createlist() {
    int count;
    cout<<"input the length of list"<<endl;
    cin>>count;
    node* head = new node;
    node* temphead = head;
    head->pre = nullptr;
    cout<<"input data plz"<<endl;
    cin>>temphead->data;
    for (int i = 0; i < count-1; ++i) {
        cout<<"input data plz"<<endl;
        datatype tempdata;
        cin>>tempdata;
//没有new的变量不存在于内存中,next找不到.
//        temphead->data = tempdata;
//        temphead->next->pre = temphead;
//        temphead = temphead->next;
        node *node1 = new node;
        node1->data = tempdata;
        node1->pre = temphead;
        temphead->next = node1;
        temphead = temphead->next;
    }
    temphead->next = nullptr;
    return head;
}
void travel(node *list, void (*visit)(datatype)) {
    node* temphead = list;
    int count = length(temphead);
    for (int i = 0; i < count; ++i) {
        visit(temphead->data);
        if(temphead->next == nullptr)
            break;
        temphead = temphead->next;
    }
    cout<<"\n";
}
int length(node *list) {
    int count = 0;
    auto temphead = list;
    for(;temphead!=NULL;temphead = temphead->next)
        count++;
    return count;
}
void print(datatype e){
    cout<<" "<<e;
}
bool isempty(node *list) {
    if(list->next == NULL)
        return true;
    else{
        return false;
    }
}
bool add(datatype e, int index, node *list) {
    //not allowed to add at the head of list.
    if(index-1 > length(list)&&index == 1)
        return false;
    else{
        index -= 1;
        node* temphead = list;
        for(;index>1;temphead=temphead->next,index-=1);
        node* node1 = new node;
        node1->data = e;
        node1->pre = temphead;
        temphead->next->pre=node1;
        node1->next = temphead->next;
        temphead->next = node1;
        return true;
    }
}
node *reserve(node *list) {
    auto temphead = list;
    node* reservedlist = new node;
    for (int i = 0; i < length(list)-1 ; ++i) {
        temphead = temphead->next;
    }
    auto tempreserved = reservedlist;
    reservedlist->pre = NULL;
    reservedlist->data = temphead->data;
    temphead = temphead->pre;
    for (int j = 0; j < length(list)-1; ++j) {
        node* node1 = new node;
        node1->data = temphead->data;
        node1->pre = reservedlist;
        reservedlist->next = node1;
        reservedlist = reservedlist->next;
        temphead = temphead->pre;
    }
    reservedlist->next = NULL;
    return tempreserved;
}
datatype del(int index, node *list) {
    if(index-1 > length(list)&&index == 1)
        return 0;
    else {
        index -= 1;
        node* temphead = list;
        for(;index>1;temphead=temphead->next,index-=1);
        //current node is the previous node of the del one.
        //return temphead->data;
        datatype datatype1 = temphead->next->data;
        auto delnode = temphead->next;
        temphead->next->next->pre = temphead;
        temphead->next = temphead->next->next;
        delete delnode;
        return datatype1;
    }
}
node *createpowerlist() {
    int count;
    cout<<"input the size of list"<<endl;
    cin>>count;
    node* head = new node;
    node* temphead = head;
    head->pre = nullptr;
    cout<<"input data and power plz with space"<<endl;
    cin>>temphead->data>>temphead->power;
    for (int i = 0; i < count-1; ++i) {
        cout<<"input data and power plz with space"<<endl;
        datatype data,power;
        cin>>data>>power;
        node* node1 = new node;
        node1->data = data;
        node1->power = power;
        node1->pre = temphead;
        temphead->next = node1;
        temphead = temphead->next;
    }
    temphead->next = nullptr;
    return head;
}
void powertravel(node *list, void (*visit)(datatype, datatype)) {
    node* temphead = list;
    int count = length(list);
    for (int i = 0; i < count; ++i) {
        visit(temphead->data,temphead->power);
        if(temphead->next == nullptr)
            break;
        temphead = temphead->next;
    }
    cout<<"\n";
}
void powerprint(datatype e, datatype ee) {
    cout<<"   "<<e<<" "<<ee;
}
node *multi(node *list1, node *list2) {

    return nullptr;
}
node *powerplus(node *list1, node *list2) {
    int counthigh = length(list1)>=length(list2)?length(list1):length(list2);
    int countlow = length(list1)>=length(list2)?length(list2):length(list1);
    auto templist1 = list1;
    auto templist2 = list2;
    auto plus_head = new node;
    auto tempplushead = plus_head;
    for (int i = 0; i < counthigh; ++i) {
        cout<<"  in for 1  ";
        for (int j = 0; j < countlow; ++j) {
            cout<<"   in for 2  ";
            if(templist2->power == templist1->power){
                cout<<"  if 21  ";
                auto node1 = new node;
                node1->power = templist1->power;
                node1->data = templist1->data+templist2->data;
                templist1->pre->next = templist1->next;
                templist1->next->pre = templist1->pre;
                delete templist1;
                templist1 = nullptr;
                templist2->pre->next = templist2->next;
                templist2->next->pre = templist2->pre;
                delete templist2;
                templist2 = nullptr;
                tempplushead->next = node1;
                node1->pre = tempplushead;
                tempplushead = tempplushead->next;
            }
            if(templist2 != nullptr){
                cout<<" if 22";
                auto node1 = new node;
                node1->power = templist2->power;
                node1->data = templist2->data;
                node1->pre = tempplushead;
                tempplushead->next = node1;
                tempplushead = tempplushead->next;
                delete templist2;
                templist2 = nullptr;
            }
            templist2 = templist2->next;
        }
        if(templist1 != nullptr){
            cout<<"  if 11  ";
            auto node1 = new node;
            node1->power = templist1->power;
            node1->data = templist1->data;
            node1->pre = tempplushead;
            tempplushead->next = node1;
            tempplushead = tempplushead->next;
            delete templist1;
            templist1 = nullptr;
        }
        templist1 = templist1->next;
    }
    return plus_head;
}
