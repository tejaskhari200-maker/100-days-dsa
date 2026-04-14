#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;

        if (freq[s[i] - 'a'] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}