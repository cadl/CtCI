#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    int min;
    struct node * next;
};

void stack_push(struct node ** top, int val) {
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    n->val = val;
    n->min = val < (*top)->min? val : (*top)->min;
    n->next = *top;
    *top = n;
    return; 
}

int stack_pop(struct node **top) {
    int tmp;
    struct node * t;
    t = *top;
    tmp = (*top)->val;
    *top = (*top)->next;
    free(t);
    return tmp;
}

int stack_min(struct node **top) {
    return (*top)->min;
}

int main() {
    struct node * top;
    top = (struct node *)malloc(sizeof(struct node));
    top->val = 1;
    top->min = 1;
    printf("%d\n", stack_min(&top));
    stack_push(&top, 2);
    stack_push(&top, 0);
    printf("%d\n", stack_min(&top));
    stack_pop(&top);
    printf("%d\n", stack_min(&top));
    stack_pop(&top);
    printf("%d\n", stack_min(&top));
    return 0;
}
