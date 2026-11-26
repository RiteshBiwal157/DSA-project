
#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[50], phone[20], issue[100];
} Customer;

typedef struct {
    Customer data[MAX];
    int front, rear, count;
} Queue;

void initialize(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int isFull(Queue *q) {
    return q->count == MAX;
}

void enqueue(Queue *q) {
    if (isFull(q)) {
        printf("\nQueue is Full!\n");
        return;
    }

    Customer c;

    printf("\nEnter Customer ID: ");
    scanf("%d", &c.id);
    getchar();

    printf("Enter Name: ");
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(c.phone, 20, stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter Issue: ");
    fgets(c.issue, 100, stdin);
    c.issue[strcspn(c.issue, "\n")] = '\0';

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = c;
    q->count++;

    printf("\nCustomer Added Successfully!\n");
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue is Empty!\n");
        return;
    }

    Customer c = q->data[q->front];

    printf("\nCustomer Being Served:\n");
    printf("ID: %d\n", c.id);
    printf("Name: %s\n", c.name);
    printf("Phone: %s\n", c.phone);
    printf("Issue: %s\n", c.issue);

    q->front = (q->front + 1) % MAX;
    q->count--;

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = -1;
    }

    printf("\nCall Served Successfully!\n");
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("\nNo Waiting Customers!\n");
        return;
    }

    printf("\n--- WAITING CUSTOMERS ---\n");

    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAX;

        printf("\nID: %d", q->data[index].id);
        printf("\nName: %s", q->data[index].name);
        printf("\nPhone: %s", q->data[index].phone);
        printf("\nIssue: %s\n", q->data[index].issue);
    }

    printf("\nTotal Waiting Calls: %d\n", q->count);
}

void searchCustomer(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue is Empty!\n");
        return;
    }

    int id, found = 0;

    printf("\nEnter Customer ID: ");
    scanf("%d", &id);

    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAX;

        if (q->data[index].id == id) {
            printf("\nCustomer Found!\n");
            printf("Name: %s\n", q->data[index].name);
            printf("Phone: %s\n", q->data[index].phone);
            printf("Issue: %s\n", q->data[index].issue);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nCustomer Not Found!\n");
}

void queueStatus(Queue *q) {
    printf("\n--- QUEUE STATUS ---\n");
    printf("Capacity: %d\n", MAX);
    printf("Waiting Calls: %d\n", q->count);
    printf("Available Space: %d\n", MAX - q->count);

    if (isEmpty(q))
        printf("Status: EMPTY\n");
    else if (isFull(q))
        printf("Status: FULL\n");
    else
        printf("Status: AVAILABLE\n");
}

int main() {
    Queue q;
    int choice;

    initialize(&q);

    printf("\n====================================\n");
    printf(" CALL CENTER CUSTOMER MANAGEMENT\n");
    printf("====================================\n");

    do {
        printf("\n1. Add Customer Call");
        printf("\n2. Serve Customer Call");
        printf("\n3. Display Customers");
        printf("\n4. Search Customer");
        printf("\n5. Queue Status");
        printf("\n6. Exit");

        printf("\n\nEnter Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid Input!\n");
            while (getchar() != '\n');
            continue;
        }

        getchar();

        switch (choice) {
            case 1:
                enqueue(&q);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                searchCustomer(&q);
                break;

            case 5:
                queueStatus(&q);
                break;

            case 6:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}
