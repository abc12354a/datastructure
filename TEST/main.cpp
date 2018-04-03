#include<iostream>
#include <vector>
#define LENGTH(array) ((sizeof(array))/(sizeof(array[0])))
#define SWAP(a,b) (a^=b,b^=a,a^=b)
#define Max_Size 100
#define Max_Num 99
using namespace std;
class SQList{
public:
    int maxlength;
    int* list;
    int length;
    SQList(int size = 99){
        this->list  = new int[size];
        this->maxlength = size;
        this->length = 0;
    }
};
void Add_To_Tail(SQList &L,int data){
    if(L.length+1 > L.maxlength){
        std::cout<<"out of range, try to get sapce...."<<endl;
        int* TempList = new int[L.length+L.maxlength];
        for (int i = 0; i < L.length; ++i) {
            TempList[i] = L.list[i];
        }
        L.maxlength = L.length + L.maxlength;
        L.list = TempList;
        L.list[L.length] = data;
        L.length += 1;
    }
    else{
        L.list[L.length] = data;
        L.length += 1;
    }
}

void Print_List(SQList L){
    cout<<endl;
    if(L.length>=1)
    for (int i = 0; i < L.length; ++i) {
        std::cout<<L.list[i]<<" ";
    }
}
void Insert_To_List(SQList &L,int loc, int data){
    if(loc>L.length || L.length+1 > L.maxlength){
        cout<<"out of range"<<endl;
    }
    else{
        for (int i = L.length; i >= loc ; --i) {
            L.list[i] = L.list[i-1];
        }
        L.list[loc] = data;
        L.length++;
    }
}
int Del_From_List(SQList &L,int loc){

}
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
class TreeNode{
public:
    int val;
    TreeNode *left,*right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
SQList Sort_SQList(SQList L){
    cout<<"start ";
    if(L.length <= 1){
        std::cout<<"List is too short"<<endl;
        return L;
    }else{
        SQList NL(L.length);
        int max_temp = L.list[0];
        cout<<"length is  "<<L.length<<endl;
        for (int j = 0; j < L.length; ++j) {
            for (int i = 0; i < L.length; ++i) {
                if(max_temp > L.list[i]){
                    max_temp = L.list[i];
                    L.list[i] = Max_Num;
                }
            }
            NL.list[j] = max_temp;
            NL.length ++;
            max_temp = Max_Num;
        }
        cout<<" over";
        return NL;
    }
}
void Del_Min(SQList &L){
    if(L.length >= 1) {
        int temp = L.list[0];
        int loc = 0;
        for (int i = 0; i < L.length; ++i) {
            if (temp > L.list[i]) {
                temp = L.list[i];
                loc = i;
            }
        }
        L.list[loc] = L.list[L.length - 1];
        L.length--;
    }
    else{
        std::cout<<"List is empty"<<endl;
    }

}
SQList MergeList_InOrder(SQList &L1, SQList &L2){
    if (L1.length <1){
        return L2;
    }
    else if(L2.length <1){
        return L1;
    }
    else{
        for (int i = 0; i < L1.length; ++i) {

        }
    }
}
vector <int> temp;
vector <int> midarray;
void preOrderTravel(TreeNode* root){
    if(root!=NULL){
        //a.push_back(root->val);
        cout<<root->val<<"  ";
        preOrderTravel(root->left);
        preOrderTravel(root->right);
    }
}
int findmid(vector <int> a,int low, int high){
    return a[low+(high-low)/2];
}
int main(){
    SQList list;
    Add_To_Tail(list,22);
    Add_To_Tail(list,8);
    Add_To_Tail(list,6);
    Add_To_Tail(list,10);
    Insert_To_List(list,2,12);
    Print_List(list);
    cout<<endl;
    Print_List(Sort_SQList(list));
    Del_Min(list);
    cout<<endl;
    Print_List(list);
}
    /*int a[] = {2,4,3,1,5,7,9};
    int length = LENGTH(a);
    Select_Sort(a,length);
    for(int i = 0;i<length;++i){
        cout<<a[i]<<" ";
    }*/
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
