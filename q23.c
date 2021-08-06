#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph{

    int v;
    int **adjMatrix;

}graph;

graph* createGraph(int v){
    graph* g=(graph*)malloc(sizeof(graph));
    g->v=v;
    g->adjMatrix=(int**)malloc(g->v*g->v*sizeof(int));

    for (int i = 0; i <g->v; i++)
    {
       for(int j=0; j< g->v; j++){
           g->adjMatrix[i][j]=0;
       }
    }

    return g;
    
}

void addEdge(graph* g,int src ,int dest, bool bidirected){ 
    g->adjMatrix[src][dest]=1;

    if(bidirected){
        g->adjMatrix[dest][src]=1;
    }
}

void printGraph(graph* g){
    printf("\nGraph: \n");
    for (int i = 0; i < g->v; i++)
    {
        for(int j=0; j<g->v ; j++){
            printf("%d ",g->adjMatrix[i][j]);
        }

        printf("\n");
    }
    
    printf("\n");
}
void main(){
    graph* g= createGraph(5); 

    addEdge(g,3,4,true);
    addEdge(g,2,3,true);
    addEdge(g,1,4,true);
    addEdge(g,1,3,true);
    addEdge(g,1,2,true);
    addEdge(g,0,4,true);
    addEdge(g,0,1,true);

    printGraph(g);

}