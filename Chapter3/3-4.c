#include <stdio.h>
#include <stdlib.h>


struct node {
    int val;
    struct node * next;
};

void stack_push(struct node **top, int val) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->val = val;
    n->next = *top;
    *top = n;
}

int stack_pop(struct node **top) {
    int tmp;
    struct node *t;
    t = *top;
    if (*top == NULL) {
        return -1;
    }
    tmp = (*top)->val;
    *top = (*top)->next;
    free(t);
    return tmp;
}

int hanoi(int level) {
    struct node **top;
    top = (struct node **)malloc(sizeof(struct node *));
    int cur;
    int total = 0;
    stack_push(top, level);
    cur = stack_pop(top);

    while (cur != -1) {
        if (cur == 1) {
            total += 1;
        }
        else {
            total += 1;
            stack_push(top, cur - 1);
            stack_push(top, cur - 1);
        }
        cur = stack_pop(top);
    }
    free(top);
    return total;
}

int main() {
    int res;
    res = hanoi(5);
    printf("%d\n", res);
    return 0;
}
