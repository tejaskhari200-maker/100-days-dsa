#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    
    // Input names
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char unique[MAX][LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    // Count votes manually
    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(names[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[LEN];

    for(int i = 0; i < uniqueCount; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if(count[i] == maxVotes) {
            // lexicographically smaller
            if(strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}