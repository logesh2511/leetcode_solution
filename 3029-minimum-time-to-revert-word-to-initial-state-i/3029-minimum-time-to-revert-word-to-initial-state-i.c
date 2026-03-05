#include <stdio.h>
#include <string.h>

int minimumTimeToInitialState(char *word, int k) {
    int n = strlen(word);
    for (int i = k; i < n; i += k) {
        if (strncmp(word + i, word, n - i) == 0) {
            return i / k;
        }
    }
    return (n + k - 1) / k;
}

