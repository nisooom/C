//
// Created by nishu on 04-05-2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MAXVERTICES 5

typedef struct Graph {

    int numNodes;
    bool **edges;

}Graph;

Graph * createGraph(int numNodes){

    Graph *g = malloc(sizeof (Graph));

    if (g == NULL){
        printf("Error");
        return NULL;
    }

    g -> numNodes = numNodes;
    g -> edges = calloc(sizeof (bool*), g->numNodes);

    if (g->edges == NULL){
        free(g);
        return NULL;
    }

    for (int i = 0; i < numNodes; i ++){

        g->edges[i] = calloc(sizeof (bool), g->numNodes);

    }

    return g;
}

void destroyGraph(Graph* g){
    for (int i = 0; i < g->numNodes; i++){
        if (g->edges[i] != NULL){
            free(g->edges[i]);
        }
    }
    free(g -> edges);
    free(g);
}

void printGraph(Graph* g){

    printf("{\n");

    for (int from=0; from < g->numNodes; from++){
        for (int to=0; to < g->numNodes; to++) {
            if (g->edges[from][to]) printf("%d -> %d\n", from, to);
        }
    }

    printf("}\n");
}

bool has_edge(Graph *g, int fromNode, int toNode){

    return g->edges[fromNode][toNode];
}

bool add_edge(Graph *g, int fromNode, int toNode){
    if (has_edge(g, fromNode, toNode)){
        return false;
    }

    g->edges[fromNode][toNode] = 1;
    return true;
}

void BFS(Graph* g, int source){
    bool visited[MAXVERTICES];
    for(int i = 0; i < g->numNodes; i++){
        visited[i] = false;
    }

    int queue[MAXVERTICES];
    int front = 0, rear = 0;

    visited[source] = true;
    queue[rear++] = source;

    while (front != rear) {
        source = queue[front++];
        printf("%d", source);

        for (int adj = 0; adj < g->numNodes; adj++) {
            if (g->edges[source][adj] && !visited[adj]) {
                visited[adj] = true;
                queue[rear++] = adj;
            }
        }
    }
}
//
//void DFS(Graph* g, int source){
//    printf("%d ", source);
//    bool visited[MAXVERTICES];
//
//    for(int i = 0; i < g->numNodes; i++){
//        visited[i] = false;
//    }
//
//    visited[source] = true;
//
//}

int printInstructions(){
    int t;
    printf("\n\tEnter 1 to Add Edges to Graph");
    printf("\n\tEnter 2 to Print BFS");
    printf("\n\tEnter 3 to Print Graph");
    printf("\n\tEnter 0 to Exit");
    printf("\n->");
    scanf("%d", &t);
    return t;
}

int main (){
    int opt = -1, bfsOpt;

    int from, to;

    printf("\nInitializing Empty Graph\n");

    Graph *g = createGraph(MAXVERTICES);

    while (opt!= 0){
        opt = printInstructions();
        switch(opt){
            case 1:

                printf("\nFrom - ");
                scanf("%d", &from);
                if (from > MAXVERTICES){
                    printf("Error");
                    continue;
                }
                printf("\nTo - ");
                scanf("%d", &to);
                if (to > MAXVERTICES){
                    printf("Error");
                    continue;
                }

                add_edge(g, from, to);
                break;

            case 2:
                printf("\nEnter Source to BFS - ");
                scanf("%d", &bfsOpt);
                BFS(g, bfsOpt);
                break;
            case 3:
                printGraph(g);
                break;
            default:
                continue;
        }
    }

    destroyGraph(g);
    return 1;
}