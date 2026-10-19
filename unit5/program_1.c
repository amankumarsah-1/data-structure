
#include <stdio.h>

#define MAX 20

int main() {
    int graph[MAX][MAX], visited[MAX] = {0};
    int queue[MAX], n, start;
    int front = 0, rear = 0;
    int i, j, current;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (n <= 0 || n > MAX || start < 0 || start >= n) {
        printf("Invalid input\n");
        return 1;
    }

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] != 0 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
    return 0;
}
