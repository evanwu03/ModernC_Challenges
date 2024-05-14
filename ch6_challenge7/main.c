

/* 
    This is a program written for Challenge 7 in the Modern C book by Jens Gudstedt. In
    this challenge Gudstedt wants us to peform a Breadth First Search (BFS) on a graph 
    represented as an adjacency matrix. 

    Since this is C and not C++, there is no standard library for queue which is needed for BFS,
    so I had to define my own. The queue is a basic structure with an array of size N and 
    and a front/back pointer to keep track of position in queue. This queue is only problematic in the sense
    that it is single use, so when the queue is filled it is no longer usable. Since we are only inputting at most
    N vertices anyways and only performing BFS once this is not a large concern. Implementing a queue as a linked list 
    or circular queue would probably be optimable of course. 



*/
#include <stdio.h>
#include <stdbool.h>
#define N 4

typedef struct
{
    int arr[N];
    int front;
    int back;

} Queue;

void initializeQueue(Queue *q)
{

    q->front = -1;
    q->back = 0;
}

bool isEmpty(Queue *q) { return (q->front == q->back - 1); }
bool isFull(Queue *q) { return(q->back == N); }

void enqueue(Queue*q, int v) { 

    if (isFull(q)) { 
        printf("Queue is full!\n");
        return;
    }

    q->arr[q->back] = v; 
    (q->back)++;
}

void dequeue(Queue*q)  {

    if (isEmpty(q)) { 
        printf("Queue is empty!\n");
        return;
    }
    q->front++;
}

int peek(Queue*q) { 

    if (isEmpty(q)) { 
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front + 1];
}

void printQueue(Queue*q) { 

    if (isEmpty(q)) { 
        printf("Queue is empty!\n");
        return;
    }

    for (size_t i = q->front+1; i < q->back; i++) { 
        printf("%d ", q->arr[i]);
    }
}


void insertEdge(bool adjMatrix[][N], const int a, const int b);
void bfs(const bool adjMatrix[][N], const int v);

int main(void)
{

    bool adjMatrix[N][N] = {false};
    insertEdge(adjMatrix, 0, 1);
    insertEdge(adjMatrix, 1, 2);
    insertEdge(adjMatrix, 2, 1);
    insertEdge(adjMatrix, 3, 0);
    insertEdge(adjMatrix, 2, 3);
    bfs(adjMatrix, 2);
}

// Graph is assumed to be directed
void insertEdge(bool adjMatrix[][N], const int a, const int b)
{
    adjMatrix[a][b] = true;
}

void bfs(const bool adjMatrix[][N], const int v)
{
    // Mark v as visited
    // Dequeue v

    // While queue is not empty
    // mark current as visited
    // dequeue current
    // For each unknown child of V
    //      Enqueue child

    Queue queue; 
    initializeQueue(&queue);
    bool isVisited[N] = {false};
    enqueue(&queue, v); 

    while(!isEmpty(&queue)) { 
        int current = peek(&queue); 
        isVisited[current] = true;
        dequeue(&queue);
        printf("%d ", current);

        for (size_t i = 0; i < N; i++) { 

            if(adjMatrix[current][i] == true && !isVisited[i]) { 
                enqueue(&queue, i); 
            }
        }
    }
}
