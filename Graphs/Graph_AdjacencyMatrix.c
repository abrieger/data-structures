// Graph data structure implementation using array of edges
// Note: the graph is undirected
// Written by Adam Brieger on 27/03/2021, based on UNSW COMP2521 algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

// Use <stdbool.h> if included with compiler
#define true 1
#define false 0

struct graph {
    int nV; // Number of vertices
    int nE; // Number of edges
    Vertex **edges; // Two-dimensional array of vertices
    int maxV; // Size of array
};

// *****************************************************************************
// Helper function prototypes:



// *****************************************************************************

// Initialises two-dimensional array filled with zeroes
// Time complexity: O(V) (for two-dimensional array)
Graph newGraph(int V) {
    Graph g = malloc(sizeof(struct graph));
    if (g == NULL) {
        fprintf(stderr, "error: unable to allocate memory for graph\n");
    }
    g->nV = V;
    g->nE = 0;
    g->edges = malloc(g->nV * sizeof(int*)); // Array of integer pointers ...
    if (g->edges == NULL) {
        fprintf(stderr, "error: unable to allocate memory for edges array\n");
    }
    for (int i = 0; i < g->nV; i++) {
        // ... with each pointing to array of integers representing the vertices
        g->edges[i] = calloc(g->nV, sizeof(Vertex));
        if (g->edges[i] == NULL) {
            fprintf(stderr, "error: unable to allocate memory for vertex array");
        }
    }
    return g;
}

// Prints the edge
// Time complexity: O(1)
void showEdge(Edge e) {
    printf("%d - %d\n", e.v, e.w);
}

// Inserts edge in graph
// Time complexity: O(1) (array can be accessed in constant time)
int insertEdge(Graph g, Edge e) {
    assert(g != NULL); // Graph does not exist

    int res = false; // true if insertion succeeds
    if (g->edges[e.v][e.w] == 0) {
        // 1 represents edge between vertices
        g->edges[e.v][e.w] = 1;
        g->edges[e.w][e.v] = 1;
        g->nE++;
        res=true;
    }

    return res;
}

// Removes edge from graph
// Time complexity: O(1) (array can be accessed in constant time)
int removeEdge(Graph g, Edge e) {
    assert(g != NULL); // Graph does not exist

    int res = false; // true if removal succeeds
    if (g->edges[e.v][e.w] == 1) {
        // 1 represents edge between vertices
        g->edges[e.v][e.w] = 0;
        g->edges[e.w][e.v] = 0;
        g->nE--;
        res=true;
    }    

    return res;
}

// Prints all edges in graph
// Time complexity: O(V^2) 
void printEdges(Graph g) {
    assert(g != NULL); // Graph does not exist

    for (int i = 0; i < g->nV; i++) {
        for (int j = i + 1; j < g->nV; j++) {
            if (g->edges[i][j] != 0) printf("%d - %d\n", i, j);
        }
    }

}

// Frees all edges in graph
// Time complexity: O(1)
void freeGraph(Graph g) {
    assert(g != NULL); // Graph does not exist

    for (int i = 0; i < g->nV; i++) free(g->edges[i]); // Free rows of matrix
    free(g->edges); // Free array of pointers to each row
    free(g);
}
