#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hash array for prefix sums (simple implementation)
    int hash[2 * MAX + 1] = {0};
    int offset = MAX;   // To handle negative prefix sums

    int prefixSum = 0;
    int count = 0;

    // Base case: prefix sum 0 seen once
    hash[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If prefixSum seen before, add its frequency
        count += hash[prefixSum + offset];

        // Increase frequency
        hash[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
