// ADT for graph
// Written by Adam Brieger on 27/03/2021

#ifndef GRAPH_H
#define GRAPH_H

#define MAX_EDGES 100

typedef struct graph *Graph;
typedef int Vertex;
typedef struct edge {
    Vertex v;
    Vertex w;   
} Edge;

// Creates new graph with space for V vertices
Graph newGraph(int V);

// Shows the specified edge
void showEdge(Edge e);

// Inserts new edge into the graph
int insertEdge(Graph g, Edge e);

// Remove an edge from the graph
int removeEdge(Graph g, Edge e);

// Print the edges
void printEdges(Graph g);

// Free the memory allocated to the graph
void freeGraph(Graph g);

#endif