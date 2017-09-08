/*
*using linkedlist to achieve polynomial calculate.
*/
#include <iostream>
#include "poly.h"
int main()
{
	std::cout<<"input two numbers with space--list1\n";
	poly* mypoly1;
	poly* mypoly2;
	creat(mypoly1,3);//creat linkedlist, standard input, argument2 is the total number of objects in list
	std::cout<<"input data of list2\n";
	creat(mypoly2,3);
	std::cout<<"show two list"<<std::endl;
	printpoly(mypoly1);
	printpoly(mypoly2);
	std::cout<<"here add two list and show the result\n";
	poly*a = add(mypoly1,mypoly2);
	printpoly(a);
	printpoly(mypoly1);
	int count = length(mypoly1);
	std::cout<<"length of list "<<count<<std::endl;
	/*auto A = initnode();
	shownode(A);*/
//	system("pause");
	return 0;
}