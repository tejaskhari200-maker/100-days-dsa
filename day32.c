#include <stdio.h>

int main() {
    int n, m;
    int stack[100];
    int top = -1;

    // number of elements to push
    scanf("%d", &n);

    // push elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }

    // number of pops
    scanf("%d", &m);

    // pop elements
    for(int i = 0; i < m; i++) {
        if(top != -1)
            top--;
    }

    // print stack from top to bottom
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}