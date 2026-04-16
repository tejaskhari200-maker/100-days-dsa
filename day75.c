#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hash map using arrays (since constraints are small)
int hash[2 * MAX + 1];  // to handle negative sums

int maxLen(int arr[], int n) {
    int prefix_sum = 0, max_length = 0;

    // Initialize hash with -1
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -2;  // means not visited

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: sum becomes 0
        if (prefix_sum == 0) {
            max_length = i + 1;
        }

        // Map index (shift to avoid negative index)
        int index = prefix_sum + MAX;

        // Case 2: seen before
        if (hash[index] != -2) {
            int length = i - hash[index];
            if (length > max_length)
                max_length = length;
        } else {
            // store first occurrence
            hash[index] = i;
        }
    }

    return max_length;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLen(arr, n);
    printf("Length of longest subarray with sum 0 = %d\n", result);

    return 0;
}