#include <stdio.h>


int path(int m, int n) {
    if (m==1 || n==1) {
        return 1;
    }
    return path(m-1, n) + path(m, n-1);
}


int main () {
    printf("%d\n", path(5, 5));
    return 0;
}
