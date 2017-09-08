#include <iostream>
#include "linkedlist.h"
int main() {
    auto list1 = createpowerlist();
//    auto list2 = createpowerlist();
    powertravel(list1,powerprint);
//    powertravel(list2,powerprint);
    auto plus_list = powerplus(list1,list1);
    powertravel(plus_list,powerprint);
    return 0;
}