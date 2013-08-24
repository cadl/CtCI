#include <stdio.h>
#include <stdlib.h>


struct node {
    int val;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void queue_push(struct queue *q, int val) {
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->val = val;
    n->next = NULL;
    if (q->tail) {
        q->tail->next = n;
    }
    if (queue_empty(q)) {
        q->head = n;
    }
    q->tail = n;
}

int queue_pop(struct queue *q) {
    struct node *n;
    int tmp;
    n = q->head;
    tmp = n->val;
    q->head = q->head->next;
    free(n);
    return tmp;
}

int queue_empty(struct queue *q) {
    if (q->head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int route(struct queue * q, int src, int dst, int (*graph)[5], int n) {
    int visited[100];
    int v, i;
    for (i=0; i<100; i++) {
        visited[i] = 0;
    }
    queue_push(q, src);
    while (!queue_empty(q)) {
        v = queue_pop(q);
        if (v == dst) {
            while (!queue_empty(q)) {
                queue_pop(q);
            }
            return 1;
        }
        for (i=0; i<n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue_push(q, i);
            }
        }
    }
    return 0;
}


int main() {
    int graph[5][5];
    int i, j;
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[2][0] = 1;
    printf("%d %d %d\n", 0, 1, route(q, 0, 1, graph, 5));
    printf("%d %d %d\n", 0, 2, route(q, 0, 2, graph, 5));
    printf("%d %d %d\n", 1, 4, route(q, 1, 4, graph, 5));
    printf("%d %d %d\n", 1, 2, route(q, 1, 2, graph, 5));
    free(q);
    return 0;
}
