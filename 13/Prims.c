#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode *head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int V, struct Graph* graph) {
    printf("Edge \tWeight\n");
    int sum = 0;
    for (int i = 1; i < V; i++) {
        struct AdjListNode* node = graph->array[i].head;
        while (node != NULL) {
            if (node->dest == parent[i]) {
                printf("%d - %d \t%d \n", parent[i], i, node->weight);
                sum += node->weight;
                break;
            }
            node = node->next;
        }
    }
    printf("Total Weight: %d\n", sum);
}

void primMST(struct Graph* graph) {
    int V = graph->V;
    int* parent = (int*) malloc(V * sizeof(int));
    int* key = (int*) malloc(V * sizeof(int));
    int* mstSet = (int*) malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        struct AdjListNode* node = graph->array[u].head;
        while (node != NULL) {
            int v = node->dest;
            if (mstSet[v] == 0 && node->weight < key[v])
                parent[v] = u, key[v] = node->weight;
            node = node->next;
        }
    }

    printMST(parent, V, graph);

    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    int V, E, isDirected;
    printf("Enter 0 for undirected graph or 1 for directed graph: ");
    scanf("%d", &isDirected);
    if (isDirected) {
        printf("Prim's algorithm is not applicable for directed graphs.\n");
        return 0;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V);

    printf("Enter the edges (source destination weight) one by one:\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    printf("Following is the Minimum Spanning Tree (MST) of the given graph:\n");
    primMST(graph);

    for (int i = 0; i < V; i++) {
        struct AdjListNode* node = graph->array[i].head;
        while (node) {
            struct AdjListNode* temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(graph->array);
    free(graph);

    return 0;
}
output:
Enter 0 for undirected graph or 1 for directed graph: 0
Enter the number of vertices: 9
Enter the number of edges: 14
Enter the edges (source destination weight) one by one:
0 1 4
0 7 8
1 7 11
1 2 8
2 8 2
7 8 7
7 6 1
8 6 6
2 5 4
6 5 2
2 3 7
3 4 9
3 5 14
5 4 10
Following is the Minimum Spanning Tree (MST) of the given graph:
Edge 	Weight
0 - 1 	4 
1 - 2 	8 
2 - 3 	7 
3 - 4 	9 
2 - 5 	4 
5 - 6 	2 
6 - 7 	1 
2 - 8 	2 
Total Weight : 37

=== Code Execution Successful ===
