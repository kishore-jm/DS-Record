#include <stdio.h>
#include <stdlib.h>
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};
struct AdjList {
    struct AdjListNode *head;
};
struct Graph {
    int V;
    struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
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
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int* in_degree = (int*) calloc(V, sizeof(int));
    int* queue = (int*) malloc(V * sizeof(int));
    int front = 0, rear = 0;
    for (int u = 0; u < V; u++) {
        struct AdjListNode* node = graph->array[u].head;
        while (node) {
            in_degree[node->dest]++;
            node = node->next;
        }
    }
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0)
            queue[rear++] = i;
    }
    int count = 0;
    int* top_order = (int*) malloc(V * sizeof(int));
    while (front < rear) {
        int u = queue[front++];
        top_order[count++] = u;
        struct AdjListNode* node = graph->array[u].head;
        while (node) {
            if (--in_degree[node->dest] == 0)
                queue[rear++] = node->dest;
            node = node->next;
        }
    }
    if (count != V) {
        printf("There exists a cycle in the graph\n");
    } else {
        for (int i = 0; i < count; i++)
            printf("%d ", top_order[i]);
        printf("\n");
    }
    free(in_degree);
    free(queue);
    free(top_order);
}
int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V);
    printf("Enter the edges (source destination) one by one:\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printf("Following is a Topological Sort of the given graph:\n");
    topologicalSort(graph);
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
Enter the number of vertices: 6
Enter the number of edges: 6
Enter the edges (source destination) one by one:
5 2
2 3
3 1
5 0
4 0
4 1
Following is a Topological Sort of the given graph:
4 5 0 2 3 1 


=== Code Execution Successful ===
