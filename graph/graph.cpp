//
// Created by angus on 17-9-29.
//

#include "graph.h"
#include <iostream>
using namespace std;
void pinrttest(Graph G) {
    G.Vex = 10;
    auto Trails = G.rails;
    for(int i = 0;i<G.Vex;++i){
        G.R[0] = i;
        G.rails = &G.R;
        G.rails++;
    }
    for(int i = 0;i<G.Vex;++i){
        cout<<*Trails[0]<<" "<<*Trails[1]<<endl;
        Trails++;
    }
}
