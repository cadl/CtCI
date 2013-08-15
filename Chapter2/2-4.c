#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};

void sum_list(struct node *a, struct node *b, struct node *res) {
    int flag = 0;
    while (res) {
        int tmp;
        
        if (a) {
            tmp = a->val + b->val;
        }
        else {
            tmp = 0;
        }
        res->val = (flag + tmp) % 10;
        if (flag == 1 && res->val == 0) {
            flag = 1;
        }
        else {
            flag = 0;
        }

        if (tmp >= 10) {
            flag = 1;
        }
        if ((a && a->next != NULL) || flag == 1) {
            res->next = (struct node *)malloc(sizeof(struct node));
        }
        if (a) {
            a = a->next;
            b = b->next;
        }
        res = res->next;
    }
}


int main() {
    struct node a, b, c, d, e, f, res;
    struct node *p;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    d.next = &e;
    e.next = &f;
    f.next = NULL;
    a.val = 9;
    b.val = 9;
    c.val = 9;
    d.val = 1;
    e.val = 0;
    f.val = 0;
    
    sum_list(&a, &d, &res);
    p = &res;
    while (p) {
        printf("%d\n", p->val);
        p = p->next;
    }
   return 0; 
}
