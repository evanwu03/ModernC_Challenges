#include <stdio.h> 
#include <stdint.h> 
#include <stdbool.h>
#include <limits.h>

#define V 7 

void insertEdge(int adjMatrix[][V], const int a, const int b); 


int main(void) { 

    int adjMatrix[V][V] = {0}; 



    return 0; 
}

// Graph is assumed to be directed
void insertEdge(int adjMatrix[][V], const int a, const int b)
{
    adjMatrix[a][b] = 1;
}


void dijkstra(int adjMatrix[][V], const int src)  {

    int dist[V] = {INT_MAX};     // Shortest distance from src to vertex 
    dist[src] = 0;               // Set source to 0 
    bool isVisited[V] = {false}; // Set of known vertices
    isVisited[src] = true;       // Mark src as known

    for (int i = 0;  i < V-1; i++) { 






        
    }
    // for all vertices 
    //      find the mininum distance 
    //      mark vertex as visited
    //      for all unknown vertices 
    //          if dist[u] + graph[u][v] < dist[v] 
    //              dist[v] = dist[u] + graph[u][v] 


}

int minDistance(int dist[V], bool isVisited[]) { 

    int min = INT_MAX; 
    int minIndex = 0; 
    for (size_t v = 0; v < V; v++) { 
        if (dist[v] <= min && !isVisited[V]) { 
            min = dist[v];
            minIndex = v; 
        }
    }
    return minIndex;
}