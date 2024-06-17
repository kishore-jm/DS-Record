#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* m[MAX];
    bool v[MAX];
};

struct Node* create_node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* create_g() {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX; ++i) {
        g->m[i] = NULL;
        g->v[i] = false;
    }
    return g;
}

void add_edge(struct Graph* g, int s, int d, bool id) {
    struct Node* newNode = create_node(d);
    newNode->next = g->m[s];
    g->m[s] = newNode;

    if (!id) {
        newNode = create_node(s);
        newNode->next = g->m[d];
        g->m[d] = newNode;
    }
}

void sort_adjacent_nodes(struct Node* head, int* arr, int* size) {
    struct Node* temp = head;
    int idx = 0;

    while (temp) {
        arr[idx++] = temp->data;
        temp = temp->next;
    }

    // Sort the array
    for (int i = 0; i < idx - 1; ++i) {
        for (int j = i + 1; j < idx; ++j) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    *size = idx;
}

void bfs(struct Graph* g, int sv) {
    bool v[MAX] = { false };
    int q[MAX];
    int front = 0, rear = 0;

    q[rear++] = sv;
    v[sv] = true;

    while (front < rear) {
        int current = q[front++];
        printf("%d ", current);

        int tempArr[MAX];
        int idx = 0;
        sort_adjacent_nodes(g->m[current], tempArr, &idx);

        for (int i = 0; i < idx; ++i) {
            int adj_vertex = tempArr[i];
            if (!v[adj_vertex]) {
                q[rear++] = adj_vertex;
                v[adj_vertex] = true;
            }
        }
    }
}

void bfs_char(struct Graph* g, char sv) {
    bool v[MAX] = { false };
    int q[MAX];
    int front = 0, rear = 0;

    q[rear++] = sv - 'A';
    v[sv - 'A'] = true;

    while (front < rear) {
        int current = q[front++];
        printf("%c ", current + 'A');

        int tempArr[MAX];
        int idx = 0;
        sort_adjacent_nodes(g->m[current], tempArr, &idx);

        for (int i = 0; i < idx; ++i) {
            int adj_vertex = tempArr[i];
            if (!v[adj_vertex]) {
                q[rear++] = adj_vertex;
                v[adj_vertex] = true;
            }
        }
    }
}

void dfs_i(struct Graph* g, int vertex) {
    g->v[vertex] = true;
    printf("%d ", vertex);

    int tempArr[MAX];
    int idx = 0;
    sort_adjacent_nodes(g->m[vertex], tempArr, &idx);

    for (int i = 0; i < idx; ++i) {
        int adj_vertex = tempArr[i];
        if (!g->v[adj_vertex]) {
            dfs_i(g, adj_vertex);
        }
    }
}

void dfs_chare(struct Graph* g, int vertex) {
    g->v[vertex] = true;
    printf("%c ", vertex + 'A');

    int tempArr[MAX];
    int idx = 0;
    sort_adjacent_nodes(g->m[vertex], tempArr, &idx);

    for (int i = 0; i < idx; ++i) {
        int adj_vertex = tempArr[i];
        if (!g->v[adj_vertex]) {
            dfs_chare(g, adj_vertex);
        }
    }
}

void dfs(struct Graph* g, int sv) {
    for (int i = 0; i < MAX; ++i) {
        g->v[i] = false;
    }
    dfs_i(g, sv);
}

void dfs_char(struct Graph* g, char sv) {
    for (int i = 0; i < MAX; ++i) {
        g->v[i] = false;
    }
    dfs_chare(g, sv - 'A');
}

int main() {
    int vert, edge;
    char verty;
    bool id;
    char dc;

    printf("Enter the type of vertices (i for integer, c for character): ");
    scanf(" %c", &verty);

    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Is the graph directed? (y/n): ");
    scanf(" %c", &dc);
    id = (dc == 'y' || dc == 'Y');

    struct Graph* g = create_g();

    printf("Enter the number of edges: ");
    scanf("%d", &edge);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edge; ++i) {
        if (verty == 'i') {
            int s, d;
            scanf("%d %d", &s, &d);
            add_edge(g, s, d, id);
        } else if (verty == 'c') {
            char s, d;
            scanf(" %c %c", &s, &d);
            add_edge(g, s - 'A', d - 'A', id);
        }
    }

    if (verty == 'i') {
        int sv;
        printf("Enter the starting vertex for BFS and DFS: ");
        scanf("%d", &sv);

        printf("BFS starting from vertex %d:\n", sv);
        bfs(g, sv);
        printf("\nDFS starting from vertex %d:\n", sv);
        dfs(g, sv);
    } else if (verty == 'c') {
        char sv;
        printf("Enter the starting vertex for BFS and DFS: ");
        scanf(" %c", &sv);

        printf("BFS starting from vertex %c:\n", sv);
        bfs_char(g, sv);
        printf("\nDFS starting from vertex %c:\n", sv);
        dfs_char(g, sv);
    }

    return 0;
}
output:
Enter the type of vertices (i for integer, c for character): c
Enter the number of vertices: 5
Is the graph directed? (y/n): n
Enter the number of edges: 6
Enter the edges (source destination):
d b
d c
d a
b a
a e
c e
Enter the starting vertex for BFS and DFS: d
BFS starting from vertex d:
d a b c e 
DFS starting from vertex d:
d a b e c 

=== Code Execution Successful ===
