#include <stdio.h> 
#include <stdint.h> 
#include <stdbool.h>
#include <limits.h>

#define V 4

void insertEdge(int adjMatrix[][V], const int a, const int b, const int dist); 
void dijkstra(int adjMatrix[][V], const int src);
int minDistance(int dist[V], bool isVisited[]);
void printSolution(int dist[]);

int main(void) { 

    int adjMatrix[V][V] = { { 0, 4, 0, 0 }, 
                            { 1, 0, 3, 4 }, 
                            { 2, 5, 0, 8 },
                            { 0, 0, 4, 0 } }; 

    dijkstra(adjMatrix, 2);
    return 0; 
}

// Graph is assumed to be directed
void insertEdge(int adjMatrix[][V], const int a, const int b, const int dist)
{
    adjMatrix[a][b] = 1;
}


void dijkstra(int adjMatrix[][V], const int src)  {

    int dist[V];                         // Shortest distance from src to vertex 
    for (size_t i = 0; i < V; i++) {     // Initialize starting distances to INT_MAX 
        dist[i] = INT_MAX;
    }

    dist[src] = 0;                       // Set source to 0 
    bool isVisited[V] = {false};         // Set of known vertices

    for (int i = 0;  i < V; i++) { 

        int u = minDistance(dist, isVisited); // Mark current vertex as known
        isVisited[u] = true; 
        for (int v = 0; v < V; v++) { 
            if (adjMatrix[u][v] > 0 && dist[u] + adjMatrix[u][v] < dist[v] && !isVisited[v]) { 
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }

    }

    printSolution(dist);

}

int minDistance(int dist[V], bool isVisited[]) { 

    int min = INT_MAX; 
    int minIndex = 0; 
    for (size_t v = 0; v < V; v++) { 
        if (dist[v] < min && !isVisited[v]) { 
            min = dist[v];
            minIndex = v; 
        }
    }
    return minIndex;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (size_t i = 0; i < V; i++)
        printf("%u \t\t\t\t %d\n", i, dist[i]);
}