// Program written by Adam Brieger on 27/03/2021
 
#include <stdio.h>

#include "Graph.h"

int main(void) {
    Graph g = newGraph(5);
    Edge e1 = createEdge(1,2);
    Edge e2 = createEdge(2,3);
    Edge e3 = createEdge(2,3);

    // Insertion will succeed:
    if (insertEdge(g, e1)) {
        printf("Successfully inserted: ");
    } else {
        printf("Failed to insert: ");
    }
    showEdge(e1);

    // Insertion will succeed:
    if (insertEdge(g, e2)) {
        printf("Successfully inserted: ");
    } else {
        printf("Failed to insert: ");
    }
    showEdge(e2);

    // Insertion will fail since duplicate:
    if (insertEdge(g, e3)) {
        printf("Successfully inserted: ");
    } else {
        printf("Failed to insert: ");
    }
    showEdge(e3);

    printf("Graph edges now include: \n");
    printEdges(g); // Output: "2 - 3" "2 - 3"

    // Deletion will succeed:
    if (removeEdge(g, e2)) {
        printf("Successfully removed: ");
    } else {
        printf("Failed to remove: ");
    }
    showEdge(e2);

    printf("Graph edges now include: \n");
    printEdges(g); // Output: "2 - 3"

    freeGraph(g);
    return 0;
}
