#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    char temp;
    int i;
    int len = strlen(str);
    for (i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main() {
    char a[] = "abcdef";
    char b[] = "a";
    char c[] = "abc";
    reverse(a);
    reverse(b);
    reverse(c);
    printf("%s\n%s\n%s\n", a, b, c);
    return 0;
}
