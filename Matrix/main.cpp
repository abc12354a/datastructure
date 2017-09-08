#include <iostream>
#include "matrix.h"
int main()
{
    CrossList c;
    CreateCrossList(&c);
    cout<<"================分割线========="<<endl;
    PrintCrossList(&c);
    return 0;
}