char* substr(const char* src, int start, int len) {
    char* dest = (char*)malloc((len + 1) * sizeof(char));
    if (dest == NULL) {
        return NULL; 
    }
    strncpy(dest, src + start, len);
    dest[len] = '\0';
    return dest;
}
char* minWindow(char* s, char* t) {
    int need[128] = {0};
    int window[128] = {0};
    int m = strlen(s), n = strlen(t);
    for (int i = 0; i < n; ++i) {
        ++need[t[i]];
    }
    int cnt = 0, j = 0, k = -1, mi = INT_MAX;
    for (int i = 0; i < m; ++i) {
        ++window[s[i]];
        if (need[s[i]] >= window[s[i]]) {
            ++cnt;
        }
        while (cnt == n) {
            if (i - j + 1 < mi) {
                mi = i - j + 1;
                k = j;
            }
            if (need[s[j]] >= window[s[j]]) {
                --cnt;
            }
            --window[s[j++]];
        }
    }
    if (k < 0) {
        return strdup("");
    } else {
        return substr(s, k, mi);
    }
}
