//
// Created by angus on 17-8-30.
//
#ifndef LESSON01_TREE_H
#define LESSON01_TREE_H
struct treenode;
typedef struct treenode *position;
typedef struct treenode *searchtree;
typedef char datatype;
searchtree Create();
searchtree MakeEmpty(searchtree T);
searchtree Insert(datatype x,searchtree T);
searchtree Delete(datatype x,searchtree T);
position Find(datatype x,searchtree T);
position FindMax(searchtree T);
position FindMin(searchtree T);
datatype Retrieve(position P);
void Travel_Pre(searchtree T);
void InTreading(searchtree T);
void Thread_Travel_Inoder(searchtree T);
#endif //LESSON01_TREE_H
