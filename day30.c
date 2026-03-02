#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insert(struct Node** head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print polynomial in standard form
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->coeff);

        if (temp->exp != 0) {
            printf("x");
            if (temp->exp != 1)
                printf("^%d", temp->exp);
        }

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}