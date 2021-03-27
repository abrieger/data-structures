// Graph data structure implementation using array of edges
// Note: the graph is undirected
// Written by Adam Brieger on 27/03/2021, based on UNSW COMP2521 algorithms

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
    Edge *edges; // Array of edges
    int maxE; // Size of array
};

struct edge {
    Vertex v;
    Vertex w;
};

// *****************************************************************************
// Helper function prototypes:

static int doesEdgeExist(Edge e1, Edge e2);

// *****************************************************************************

// Creates graph with memory for V vertices
// Time complexity: O(1)
Graph newGraph(int V) {
    Graph g = malloc(sizeof(struct graph));
    if (g == NULL) {
        fprintf(stderr, "error: unable to allocate memory\n");
    }
    g->nV = V;
    g->nE = 0;
    g->edges = malloc(sizeof(struct edge) * MAX_EDGES);
    return g;
}

// Creates edge struct
Edge createEdge(int new_v, int new_w) {
    Edge e = malloc(sizeof(struct edge));
    e->v = new_v;
    e->w = new_w;
    return e;
} 

// Prints the edge
void showEdge(Edge e) {
    printf("%d - %d\n", e->v, e->w);
}

// Checks whether edge already exists
static int doesEdgeExist(Edge e1, Edge e2) {
    if (e1->v == e2->v && e1->w == e2->w) return true; // Duplicate
    if (e1->v == e2->w && e1->w == e2->v) return true; // Duplicate

    // Unique
    return false;
}

// Inserts edge in graph
// Time complexity: O(v) (must iterate through all edges in array)
int insertEdge(Graph g, Edge e) {
    assert(g != NULL); // Graph does not exist

    int res = false; // true if insertion succeeds
    int i;
    for (i = 0; i < g->nE; i ++) {
        if (doesEdgeExist(e, g->edges[i])) break; // Duplicate edge exists
    }

    if (i == g->nE) {
        // Reached end of array without breaking, so no duplicate exists
        g->edges[i] = e; // Insert edge
        g->nE += 1;  // Increment edge count
        res = true; 
    }
    return res;
}

// Removes edge from graph
// Time complexity: O(v) (must iterate through all edges in array)
int removeEdge(Graph g, Edge e) {
    assert(g != NULL); // Graph does not exist

    int res = false; // true if removal succeeds
    int i;
    for (i = 0; i < g->nE; i ++) {
        if (doesEdgeExist(e, g->edges[i])) break; // Edge exists
    }

    if (i < g->nE) {
        // Broke before end of array, so edge must exist
        g->edges[i] = g->edges[g->nE - 1]; // Replace with last edge in array
        g->nE -= 1; // Decrement edge count
        res = true;
    }    
    return res;
}

// Prints all edges in graph
// Time complexity: O(E) (must iterate through all edges in array)
void printEdges(Graph g) {
    assert(g != NULL); // Graph does not exist

    for (int i = 0; i < g->nE; i++) {
        Edge curr_e = g->edges[i];
        printf("%d - %d\n", curr_e->v, curr_e->w);
    }
}

// Frees all edges in graph
void freeGraph(Graph g) {
    if (g == NULL) return; // Graph does not exist
    free(g->edges);
    free(g);
}
