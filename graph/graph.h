//
// Created by angus on 17-9-29.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#define MAX_SIZE 100
typedef int datatype;
struct Graph{
    datatype Vex;
    datatype (*rails)[2];
    datatype R[2];
};
void pinrttest(Graph G);
void CreateGraph();
#endif //GRAPH_GRAPH_H
