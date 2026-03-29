#include <stdio.h>

#define MAX 100

int main() {
    int n, arr[MAX];
    
    // Input
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int queue[MAX];
    int front = 0, rear = 0;

    // Start with root index
    queue[rear++] = 0;

    int leftToRight = 1;

    while(front < rear) {
        int size = rear - front;
        int level[MAX];
        int k = 0;

        // Process current level
        for(int i = 0; i < size; i++) {
            int index = queue[front++];
            level[k++] = arr[index];

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if(left < n) queue[rear++] = left;
            if(right < n) queue[rear++] = right;
        }

        // Print level
        if(leftToRight) {
            for(int i = 0; i < k; i++) {
                printf("%d ", level[i]);
            }
        } else {
            for(int i = k - 1; i >= 0; i--) {
                printf("%d ", level[i]);
            }
        }

        // Toggle direction
        leftToRight = !leftToRight;
    }

    return 0;
}