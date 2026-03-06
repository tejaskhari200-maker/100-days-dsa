#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push
void push(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// Pop
int pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    int val = top->data;
    struct node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char exp[]){
    int i = 0;
    while(exp[i] != '\0'){
        
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }
        
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            
            int b = pop();
            int a = pop();
            int result;

            switch(exp[i]){
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
        
        i++;
    }

    return pop();
}

int main(){
    char exp[] = "231*+9-";
    
    printf("Result = %d", evaluate(exp));

    return 0;
}