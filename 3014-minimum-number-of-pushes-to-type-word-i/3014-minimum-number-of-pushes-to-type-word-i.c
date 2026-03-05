int minimumPushes(char* word) {
    int len = strlen(word);
    if (len <= 8) return len;
    else if (len <= 16) return 2 * len - 8;
    else if (len <= 24) return 3 * len - 24;
    return 4 * len - 48;
}