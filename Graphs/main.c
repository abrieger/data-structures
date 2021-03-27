// Program written by Adam Brieger on 27/03/2021
// Menu driver for the Graph ADT
 
#include <stdio.h>

#include "Graph.h"

#define MAX_VERTICES 10

int main(void) {
    Graph g = newGraph(MAX_VERTICES);
    Edge e;

    printf("Menu\n");
    printf("1. Insert edge\n");
    printf("2. Remove edge\n");
    printf("3. Display edges in graph\n");
    printf("4. Exit\n");

    printf("Enter choice: \n");
    int ch;
    scanf("%d", &ch);
    while (ch < 4) {
        switch(ch) {
            case 1: printf("Enter edge vertices: ");
                scanf("%d %d", &(e.v), &(e.w));
                if (insertEdge(g, e)) {
                    printf("Successfully inserted: ");
                } else {
                    printf("Failed to insert: ");
                }            
                showEdge(e);
                break;
            case 2: printf("Enter edge vertices: ");
                scanf("%d %d", &(e.v), &(e.w));
                if (removeEdge(g, e)) {
                    printf("Successfully removed: ");
                } else {
                    printf("Failed to remove: ");
                }            
                showEdge(e);
                break;
            case 3: printf("Graph edges now include: \n");
                printEdges(g);
                break;
        } 
        printf("Enter choice: \n");
        scanf("%d", &ch);
    }

    freeGraph(g);
    return 0;
}
