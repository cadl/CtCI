#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};

int stack_peek(struct node **top) {
    return (*top)->val;
}

int stack_is_empty(struct node **top) {
    if (*top) {
        return 0;
    }
    else {
        return 1;
    }
}

void stack_push(struct node **top, int val) {
    struct node *a;
    a = (struct node *)malloc(sizeof(struct node));
    a->val = val;
    a->next = *top;
    *top = a;
}

int stack_pop(struct node **top) {
    struct node *tmp;
    int a;
    a = (*top)->val;
    tmp = *top;
    *top = (*top)->next;
    free(tmp);
    return a;
}

void sort(struct node **top) {
    int tmp;
    int a;
    struct node **top_b;
    top_b = (struct node **)malloc(sizeof(struct node *));
    *top_b = NULL;

    while (!stack_is_empty(top)) {
        a = stack_pop(top);
        while ((!stack_is_empty(top_b)) && stack_peek(top_b) < a) {
            stack_push(top, stack_pop(top_b));
        }
        stack_push(top_b, a);
    }
    while (!stack_is_empty(top_b)) {
        stack_push(top, stack_pop(top_b));
    }
}


int main() {
    struct node **top;
    top = (struct node **)malloc(sizeof(struct node *));
    (*top) = NULL;
    stack_push(top, 1);
    stack_push(top, 2);
    stack_push(top, 0);
    stack_push(top, 3);
    stack_push(top, -1);
    sort(top);
    while (!stack_is_empty(top)) {
        printf("%d\n", stack_pop(top));
    }
    return 0;
}
