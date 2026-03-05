#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    
    if (needleLen == 0) {
        return 0; // Empty needle matches at index 0
    }
    
    if (haystackLen < needleLen) {
        return -1; // Needle is longer than haystack
    }
    
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j;
        for (j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleLen) {
            return i; // Found the needle at index i
        }
    }
    
    return -1; // Needle not found
}
