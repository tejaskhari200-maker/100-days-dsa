#include <stdio.h>

int main() {
    int n, m;
    
    // Read number of elements
    scanf("%d", &n);
    
    int queue[n];
    
    // Read queue elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    
    // Read number of dequeue operations
    scanf("%d", &m);
    
    int front = 0;

    // Perform dequeue operations
    front = (front + m) % n;

    // Print queue from new front to rear
    for(int i = 0; i < n; i++) {
        printf("%d ", queue[(front + i) % n]);
    }

    return 0;
}