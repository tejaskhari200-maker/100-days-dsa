#include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int comparisons = 0;
    int found = -1;

    // Input size
    scanf("%d", &n);

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    scanf("%d", &k);

    // Linear search
    for (int i = 0; i < n; i++) {
        comparisons++;          // one comparison
        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    // Output
    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}