#include<iostream>
#include <vector>
#define LENGTH(array) ((sizeof(array))/(sizeof(array[0])))
#define SWAP(a,b) (a^=b,b^=a,a^=b)
using namespace std;
#define Max_Size 100
void Select_Sort(int a[],int n){
    int i,j,min;
    for(i = 0;i<n;++i){
        min = i;
        for(j = i+1;j<n;++j){
            if(a[j]<a[min])
                min = j;
        }
        if(min!=i)
            SWAP(a[i],a[min]);
    }
}
int main(){
    int a[] = {2,4,3,1,5,7,9};
    int length = LENGTH(a);
    Select_Sort(a,length);
    for(int i = 0;i<length;++i){
        cout<<a[i]<<" ";
    }
}
/*typedef struct Tree{
    int index;
    Tree* left;
    Tree* right;
    Tree* parent;
}*PointerTree;
PointerTree NodesInList(PointerTree* Node,int index,int N){
    PointerTree None = new Tree;
    None->index = -2;
    for(int i = 0;i<N;++i){
        if(Node[i]->index == index)
            return Node[i];
    }
    return None;
}
void CreateBinaryTree(PointerTree T){
    int N;
    cin>>N;
    PointerTree* Node = new PointerTree[N+1];
    for(int i = 0;i<N;++i){
        Node[i]->index = 0;
    }
    //PointerTree tree = T;
    for(int i = 0;i<N;++i){
        PointerTree tree = new Tree;
        PointerTree left = new Tree;
        PointerTree right = new Tree;
        cin>>tree->index>>left->index>>right->index;
        left->parent = tree;
        right->parent = tree;
        tree->left = left;
        tree->right = right;
        if(tree->index!=-1&&NodesInList(Node,tree->index,N)->index==-2){
            *Node = tree;
        }else if(tree->index!=-1&&NodesInList(Node,tree->index,N)->index!=-2) {
            PointerTree temp = NodesInList(Node, tree->index, N);
            temp = tree;
        }
    }
}
int main(){
    PointerTree T = new Tree;
    CreateBinaryTree(T);
}*/
/*typedef int NodeType;
typedef struct Tree{
    NodeType Data;
    int parent;
    int Size;
}*PointerTree;
PointerTree AddNode(PointerTree T);
void PostTravel(PointerTree T);
PointerTree AddNode() {
    int N;
    cin>>N;
    int count = 3;
    int* root = new int[2*N+1];
    int* left = new int[2*N+1];
    int* right = new int[2*N+1];
    PointerTree tree = new Tree[2*N+1];
    for(int i = 0;i<2*N+1;++i){
        tree[i].Data = 0;
        tree[i].parent = 0;
    }
    cin>>tree[0].Data>>tree[1].Data>>tree[2].Data;
    for(int i = 0;i<N-1;i++){
        cin>>root[i]>>left[i]>>right[i];
        tree[count].Data = left[i];
        tree[count++].parent = root[i];
        tree[count].Data = right[i];
        tree[count++].parent = root[i];
    }
    tree[0].Size = N;
    return tree;
}
void PostTravel(PointerTree T){
    int N = T[0].Size;
    for(int i = 0;i<N;++i){
        int iParent = T[2*N].parent;
        if(T[2*N].Data!=-1){
        cout<<T[2*N].Data<<" ";}
        if(T[2*N-1].Data!=-1){
            cout<<T[2*N-1].Data<<" ";}
        cout<<T[T[2*N].parent].Data;
        N--;
    }
}
int main(){
    auto T = AddNode();
    PostTravel(T);
}
 */
