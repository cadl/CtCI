#include <stdio.h>
#include <stdlib.h>


struct node{
    int value;
    struct node *next;
};

struct node * last_n_element(struct node * nd, int n, int * pos) {
    struct node * tmp;
    if (nd->next == NULL) {
        *pos = 1;
    }
    else {
        tmp = last_n_element(nd->next, n, pos);
        *pos += 1;
    }
    if (*pos == n) {
        return nd;
    }
    else {
        return tmp;
    }
}

void build_list(struct node *pa, int n) {
    struct node * next;
    int i;
    for (i=0; i<n; i++) {
        next = (struct node *)malloc(sizeof(struct node));
        next->value = i+1;
        pa->next = next;
        pa = pa->next;
    }
    return;
}

void show_list(struct node *pa) {
    int i;
    while (pa->next != NULL) {
        pa = pa->next;
        printf("%d\n", pa->value);
    }
    return;
}


int main() {
    struct node pa;
    struct node * ans;
    int cur = 0;
    build_list(&pa, 5);
    show_list(&pa);
    ans = last_n_element(&pa, 3, &cur);
    printf("%d\n", ans->value);
    return 0;
}
