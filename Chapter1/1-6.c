#include <stdio.h>
#include <stdlib.h>


void rotate(int **m, int len) {
    int i, j, k;
    for (i=0; i<len; i++) {
        int tmp;
        for (j=0; j<len-i-1-i; j++) {
            tmp = m[i][j+i];
            m[i][j+i] = m[len-i-j-1][i];
            m[len-i-j-1][i] = m[len-i-1][len-i-j-1];
            m[len-i-1][len-i-j-1] = m[i+j][len-i-1];
            m[i+j][len-i-1] = tmp;
        }
    }
}

int main() {
    int i, j;
    int **m;
    m = (int **)malloc(sizeof(int *) *  4);
    for (i=0; i<4; i++) {
        m[i] = (int *)malloc(sizeof(int) * 4);
        for (j=0; j<4; j++) {
            m[i][j] = j + 1;
        }
    }
    for (i=0; i< 4; i++) {
        for (j=0; j<4; j++) {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    rotate(m, 4);
    for (i=0; i< 4; i++) {
        for (j=0; j<4; j++) {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
