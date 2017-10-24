//
// Created by angus on 17-9-29.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#define MAX_Vex 100
#define INIFINITY -1
typedef int VexType;
typedef int EdgeType;
typedef struct Graph{
    VexType vex[MAX_Vex];
    EdgeType arc[MAX_Vex][MAX_Vex];
    int numVex,numEdge;
}MGraph;
void CreateGraph(MGraph *G);
void TraveGraph(MGraph *G);
void TestFun();
/***************************************/
typedef struct EdgeNode{
    int Adjvex;
    EdgeType Weight;
    struct EdgeNode *Next;
}EdgeNode;
typedef struct VexNode{
    VexType Data;
    EdgeNode* FirstNode;
}VexNode,AdjList[MAX_Vex];
typedef struct GraphAdjList{
    AdjList adjList;
    int numVex,numEdge;
}GraphAdjList;
void CreateAdjGraph(GraphAdjList* G);
void TraveAdjGraph(GraphAdjList* G);
void TestAdjGraph();
#endif //GRAPH_GRAPH_H
