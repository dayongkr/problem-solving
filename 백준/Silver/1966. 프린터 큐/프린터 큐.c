#include <stdio.h>
#include <stdlib.h>


typedef struct node *nodePt;

typedef struct node {
    int index;
    int value;
    nodePt next;
} node;

int n, a, b, prior;
nodePt queue = NULL;

nodePt new(int index, int value) {
    nodePt t = (nodePt) malloc(sizeof(node));;
    t->index = index;
    t->value = value;
    t->next = NULL;
    return t;
}

void enqueue(int j, int p) {
    if (queue == NULL) queue = new(j, p);
    else {
        nodePt temp = queue;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new(j, p);
    }
}

nodePt dequeue() {
    if (queue == NULL) return NULL;
    nodePt temp = queue;
    queue = queue->next;
    return temp;
}

int check(nodePt target) {
    nodePt temp = queue;
    while (temp != NULL) {
        if (temp->value > target->value) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        queue = NULL;
        scanf("%d %d", &a, &b);
        for (int j = 0; j < a; j++) {
            scanf("%d", &prior);
            enqueue(j, prior);
        }
        int count = 0;
        while (1) {
            nodePt temp = dequeue();
            if (check(temp)) {
                enqueue(temp->index, temp->value);
            } else if (temp->index == b) {
                count++;
                printf("%d\n", count);
                break;
            } else
                count++;

        }
    }
    return 0;
}
