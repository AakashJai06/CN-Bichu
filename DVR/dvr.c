#include <stdio.h>

#define INFINITY 9999
#define MAX 10

int cost[MAX][MAX], dist[MAX][MAX], next_hop[MAX][MAX];
int nodes;


void updateRoutes() {
    int updated;
    do {
        updated = 0;
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                for (int k = 0; k < nodes; k++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_hop[i][j] = next_hop[i][k];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);
}

void display() {
    for (int i = 0; i < nodes; i++) {
        printf("\nRouting table for Router %d:\n", i + 1);
        printf("Destination\tCost\tNext Hop\n");
        for (int j = 0; j < nodes; j++) {
            printf("%d\t\t%d\t%d\n", j + 1, dist[i][j], next_hop[i][j] + 1);
        }
    }
}

int main() {
    printf("Enter the number of routers: ");
    scanf("%d", &nodes);

    printf("Enter the cost matrix (use %d for no direct link):\n", INFINITY);
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
            next_hop[i][j] = j;
        }
        cost[i][i] = 0;
        dist[i][i] = 0;
        next_hop[i][i] = i;
    }

    updateRoutes();
    display();

    return 0;
}
