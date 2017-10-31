//
// Created by angus on 17-9-29.
//

#include "graph.h"
#include <iostream>

using namespace std;

//生成无向图;
//矩阵
void CreateGraph(MGraph *G) {
    cout << "input vexs and edges(max number)" << endl;
    cin >> G->numVex >> G->numEdge;
    for (int i = 0; i < G->numVex; ++i) {
        cout << "input vex's value" << endl;
        cin >> G->vex[i];
    }
    for (int i = 0; i < G->numVex; ++i) {
        for (int j = 0; j < G->numVex; ++j) {
            G->arc[i][j] = INIFINITY;
        }
    }
    for (int i = 0; i < G->numEdge; ++i) {
        int x, y;
        cout << "input arcs" << endl;
        cin >> x >> y;
        G->arc[x][y] = 1;
        G->arc[y][x] = 1;
    }
}

void TraveGraph(MGraph *G) {
    cout<<"  ";
    for(int i = 0;i<G->numVex;++i){
        cout<<G->vex[i]<<"  ";
    }
    cout<<endl;
    for (int i = 0; i < G->numVex; ++i) {
        cout<<G->vex[i]<<" ";
        for (int j = 0; j < G->numVex; ++j) {
            cout << G->arc[i][j] << "  ";
        }
        cout << endl;
    }
}

void TestFun() {
    MGraph *Graph = (MGraph *) malloc(sizeof(MGraph));
    //CreateGraph(Graph);
    CreateMGraph_Auto(Graph);
    //TraveGraph(Graph);
    MatrixDFS(*Graph);
}

void CreateAdjGraph(GraphAdjList *G) {
    EdgeNode *e;
    cout << "input vexs and edges" << endl;
    cin >> G->numVex >> G->numEdge;
    for (int i = 0; i < G->numVex; ++i) {
        //cout<<"input data of vex"<<endl;
        G->adjList[i].FirstNode = nullptr;
    }
    for (int i = 0; i < G->numEdge; ++i) {
        int x, y;
        cout << "input the Edge vi/vj's vex index" << endl;
        cin >> x >> y;
        e = (EdgeNode *) malloc(sizeof(EdgeNode));
        e->Adjvex = y;
        e->Next = G->adjList[x].FirstNode;
        G->adjList[x].FirstNode = e;
        e = (EdgeNode *) malloc(sizeof(EdgeNode));
        e->Adjvex = x;
        e->Next = G->adjList[y].FirstNode;
        G->adjList[y].FirstNode = e;
    }
}

void TraveAdjGraph(GraphAdjList *G) {
    for (int i = 0; i < G->numVex; ++i) {
        cout << i << " ";
        EdgeNode *e = (EdgeNode *) malloc(sizeof(EdgeNode));
        e = G->adjList[i].FirstNode;
        while (e != nullptr) {
            cout << " " << e->Adjvex;
            e = e->Next;
        }
        cout << endl;
    }
}

void TestAdjGraph() {
    GraphAdjList *G = (GraphAdjList *) malloc(sizeof(GraphAdjList));
    CreateAdjGraph(G);
    TraveAdjGraph(G);
}

void MatrixDFS(MGraph G) {
    int visited[G.numVex+1] = {0};
    for(int i = 0;i<G.numVex;++i){
        if(!visited[i])
            DFS_Internal_MG(G,visited,i);
    }
}

void CreateMGraph_Auto(MGraph *G) {
    int numVex = 8;
    int numEdge = 6;
    cout<<"the num of Vex and Edge is "<<numVex<<" and"<<numEdge<<endl;
    G->numVex = numVex;
    G->numEdge = numEdge;
    char VexNode[numVex] = {'a','b','c','d','e','f','g','h'};
    int EdgeG[numEdge][2] = {
            {0,2},{0,3},{0,5},{1,2},{2,3},{6,7}
    };
    for(int i = 0;i<numVex;++i){
        G->vex[i] = VexNode[i];
    }
    for(int i = 0;i<numVex;++i){
        for(int j = 0;j<numVex;++j){
            G->arc[i][j] = INIFINITY;
        }
    }
    for(int i = 0;i<numEdge;++i){
        int p1 = EdgeG[i][0];
        int p2 = EdgeG[i][1];
        G->arc[p1][p2] = 1;
        G->arc[p2][p1] = 1;
        //无向图
    }
}
//return the next node of v to w;
int Next_Vex(MGraph G, int v, int w) {
    if(v<0||(v>G.numVex-1)||w<0||w>(G.numVex)){
        return -1;
    }
    for(int i = w+1;i<G.numVex;++i){
        if(G.arc[v][i] > 0)
            return i;
    }
    return -1;
}
int First_Vex(MGraph G, int v) {
    if(v<0||(v>G.numVex-1)){
        return -1;
    }
    for(int i = 0;i<G.numVex;++i){
        if(G.arc[v][i] > 0)
            return i;
    }
    return -1;
}

void DFS_Internal_MG(MGraph G,int *visited,int i) {
    visited[i] = 1;
    cout<<G.vex[i]<<" ";
    for(int w = First_Vex(G,i);w>0;w = Next_Vex(G,i,w)){
        if(!visited[w])
            DFS_Internal_MG(G,visited,w);
    }
}
