#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumPushes(char* word) {
    int cnt[26] = {0};
    for (int i = 0; word[i]; i++) {
        cnt[word[i] - 'a']++;
    }
    
    // Sort the count array in descending order
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25 - i; j++) {
            if (cnt[j] < cnt[j + 1]) {
                int temp = cnt[j];
                cnt[j] = cnt[j + 1];
                cnt[j + 1] = temp;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += (i / 8 + 1) * cnt[i];
    }
    
    return ans;
}
