#include <stdio.h>
#include <string.h>


int is_anagrams(char *a, char *b){
    int i;
    int cnt[26];
    
    for (i=0; i<26; i++) {
        cnt[i] = 0;
    }

    for (i=0; a[i]; i++) {
        cnt[a[i]-'a'] += 1;
    }
    
    for (i=0; b[i]; i++) {
        cnt[b[i]-'a'] -= 1;
    }
    
    for (i=0; i<26; i++) {
        if (cnt[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("%d\n", is_anagrams("abc", "cba"));
    printf("%d\n", is_anagrams("aaabbc", "cbabaa"));
    printf("%d\n", is_anagrams("a", "b"));
}
