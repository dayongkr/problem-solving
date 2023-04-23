typedef struct node {
    int value;
    struct node *next;
} node;

int findTheWinner(int n, int k) {
    int count = 0;
    node *head = (node *) malloc(sizeof(node));
    node *tail = head;
    head->value = 1;
    head->next = NULL;
    for (int i = 2; i <= n; i++) {
        tail->next = (node *) malloc(sizeof(node));
        tail = tail->next;
        tail->value = i;
        tail->next = NULL;
    }
    while (head->next != NULL) {
        for (int i = 0; i < k; i++) {
            tail->next = head;
            head = head->next;
            if (i == k - 1) {
                count++;
                tail->next = NULL;
                break;
            }
            tail = tail->next;
        }
    }
    return head->value;
}