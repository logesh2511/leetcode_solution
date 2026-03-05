#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) return "";
    
    int prefixLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (strs[0][j] && strs[i][j] && strs[0][j] == strs[i][j]) {
            j++;
        }
        prefixLen = j < prefixLen ? j : prefixLen;
    }
    
    char *result = (char *)malloc((prefixLen + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    strncpy(result, strs[0], prefixLen);
    result[prefixLen] = '\0';
    
    return result;
}
