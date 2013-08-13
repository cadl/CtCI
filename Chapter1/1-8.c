#include <stdio.h>
#include <string.h>

int isSubstring(char a[], char b[]) {
    int i, j;
    int len_a, len_b;
    len_a = strlen(a);
    len_b = strlen(b);
    for (i=0; i<len_a; i++) {
        if (a[i] == b[0]) {
            for (j=1; j<len_b; j++) {
                if (a[i+j] != b[j]) {
                    break;
                }
            }
            if (j==len_b) {
                return 1;
            }
        }
    }
    return 0;
}

int isRotation(char a[], char b[]) {
    strcat(a, a);
    return isSubstring(a, b) && (strlen(a) == strlen(b) * 2);
}

int main() {
    char a[] = "abcdef";
    char b[] = "defabc";
    char c[] = "abcdef";
    char d[] = "abcd";

    printf("%s %s %d\n", a, b, isRotation(a, b));
    printf("%s %s %d\n", c, d, isRotation(c, d));

    return 0;
}
