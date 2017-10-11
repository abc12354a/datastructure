//
// Created by angus on 17-10-9.
//

#ifndef BINARYSEARCH_BSTREE_H
#define BINARYSEARCH_BSTREE_H
typedef int Data;
typedef struct BsNode{
    Data value;
    BsNode* left;
    BsNode* right;
    BsNode* parent;
}*BsTree,Node;
Node* CreateNode(Node* parent,Node* left,Node* right,Data value);
void Pre_Order_Travel(BsTree Tree);
void In_Order_Travel(BsTree Tree);
void Post_Order_Travel(BsTree Tree);
BsTree Insert_Node(BsTree Tree,Node* node);
BsTree Insert_Value(BsTree Tree,Data value);
BsTree Del_Node(BsTree Tree,Node* node);
BsTree Del_Value(BsTree Tree,Data value);
Node* BsTree_Search(BsTree Tree,Data value);
Node* BsTree_Max(BsTree Tree);
Node* BsTree_Mini(BsTree Tree);
Node* BsTree_Search(BsTree Tree,Data value);
void print_bstree(BsTree tree, Data key, int direction);
Node* Predecer_BsTree(Node* node);
Node* Postdecer_BsTree(Node* node);
#endif //BINARYSEARCH_BSTREE_H
