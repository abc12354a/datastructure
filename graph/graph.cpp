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
    for (int i = 0; i < G->numVex; ++i) {
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
    TraveGraph(Graph);
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

void MatrixDFS(MGraph *G, int i) {

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
