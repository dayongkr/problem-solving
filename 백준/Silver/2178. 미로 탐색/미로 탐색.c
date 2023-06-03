#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePtr;
typedef struct node {
    int pos[2];
    int cost;
    nodePtr next;
} node;


nodePtr new(int x, int y, int cost) {
    nodePtr temp = (nodePtr) malloc(sizeof(node));
    temp->pos[0] = x;
    temp->pos[1] = y;
    temp->cost = cost;
    temp->next = NULL;
    return temp;
}

nodePtr dequeue(nodePtr *head) {
    if (*head == NULL) return NULL;
    nodePtr temp = *head;
    *head = (*head)->next;
    return temp;
}

void enqueue(nodePtr *head, int x, int y, int cost) {
    nodePtr temp = new(x, y, cost + 1);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    nodePtr cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = temp;
}


int main(void) {
    nodePtr queue = NULL;
    int n, m;
    scanf("%d %d", &n, &m);
    char tempC[m + 1];
    int arr[n][m], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

// 미로 만들기
    for (int i = 0; i < n; i++) {
        scanf("%s", tempC);
        for (int j = 0; j < m; j++)
            arr[i][j] = (int) tempC[j] - 48;

    }

    enqueue(&queue, 0, 0, 0);
    arr[0][0] = 0;
    int min = 10001;
    nodePtr temp = NULL;


    while (temp = dequeue(&queue)) {
        if (temp->pos[0] == n - 1 && temp->pos[1] == m - 1 && temp->cost < min)
            min = temp->cost;
        for (int i = 0; i < 4; i++) {
            int x = temp->pos[0] + dx[i], y = temp->pos[1] + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y]) {
                enqueue(&queue, x, y, temp->cost);
                arr[x][y] = 0;
            }
        }
    }
    printf("%d", min);
    return 0;
}
