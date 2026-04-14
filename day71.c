#include <stdio.h>

#define SIZE 100

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int i = 0;
    int idx;

    while (i < SIZE) {
        idx = (hash(key) + i * i) % SIZE;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int search(int key) {
    int i = 0, idx;

    while (i < SIZE) {
        idx = (hash(key) + i * i) % SIZE;
        if (table[idx] == key)
            return 1;
        if (table[idx] == -1)
            return 0;
        i++;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    init();

    while (n--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key);
        } else if (op[0] == 'S') {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}