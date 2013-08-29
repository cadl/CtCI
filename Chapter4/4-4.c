#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};

struct ListNode {
    struct TreeNode *val;
    struct ListNode *next;
};

struct List {
    struct ListNode *head;
    struct ListNode *cur;
};

void list_build(struct List *l) {
    l = (struct List *)malloc(sizeof(struct List));
    l->head = NULL;
    l->cur = NULL;
}

void list_insert(struct List *l, struct TreeNode *tn) {
    struct ListNode *now = (struct ListNode *)malloc(sizeof(struct ListNode));
    now->val = tn;
    if (l->head == NULL) {
        l->head = now;
        l->cur = l->head;
    }
    else {
        l->cur->next = now;
        l->cur = now;
    }
}

void bs_tree_build(struct TreeNode * tree, int vals[], int len) {
    int i;
    struct TreeNode *cur, *new;
    tree->val = vals[0];
    for (i=1; i<len; i++) {
        cur = tree;
        while (cur) {
            if (vals[i] < cur->val) {
                new = cur->left;
                if (!new) {
                    new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                    new->val = vals[i];
                    cur->left = new;
                    break;
                }
                else {
                    cur = new;
                }
            }
            else {
                new = cur->right;
                if (!new) {
                    new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                    new->val = vals[i];
                    cur->right = new;
                    break;
                }
                else {
                    cur = new;
                }
            }
        }
    }
    return;
}

void bs_tree_output(struct TreeNode *tree) {
    if (tree) {
        bs_tree_output(tree->left);
        printf("%d ", tree->val);
        bs_tree_output(tree->right);
    }
    return;
}

struct List ** bs_tree_depth_node(struct TreeNode *tree) {
    struct List **ll = (struct List **)malloc(sizeof(struct List *)*100);
    struct List *l;
    struct List *nextl;
    struct ListNode *now;
    int i;
    int cnt;
    
    ll[0] = (struct List *)malloc(sizeof(struct List));
    l = ll[0];
    cnt = 1;
    list_insert(l, tree);
    

    while (1) {
        now = l->head;
        if (!now) {
            break;
        }
        nextl = (struct List *)malloc(sizeof(struct List));
        ll[cnt] = nextl;
        while (now) {
            if (now->val->left) {
                list_insert(nextl, now->val->left);
            }
            if (now->val->right) {
                list_insert(nextl, now->val->right);
            }
            now = now->next; 
        }
        cnt += 1;
        l = nextl;
    }
    return ll;
}


int main() {
    int i;
    int a[] = {1, 3, 2, 4, 5, 7, 6};
    struct TreeNode *tree;
    struct ListNode *now;
    struct List **ll;
    tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    bs_tree_build(tree, a, 7);
    bs_tree_output(tree);
    printf("\n");
    ll = bs_tree_depth_node(tree);
    for (i=0; ll[i]; i++) {
        now = ll[i]->head;
        printf("\n");
        while (now) {
            printf("%d ", now->val->val);
            now = now->next;
        }
    }
    for (i=0; ll[i]; i++) {
        free(ll[i]);
    }
    free(ll);
    free(tree);
    free(now);
    return 0;
}
