int countCompleteSubstrings(char* word, int k) {
     int uniqueLetters = 0;
    int ans = 0;
    int wordLength = strlen(word);
    bool charSet[26] = {false};
    for (int i = 0; i < wordLength; ++i) {
        if (!charSet[word[i] - 'a']) {
            charSet[word[i] - 'a'] = true;
            uniqueLetters++;
        }
    }
    for (int windowSize = k; windowSize <= k * uniqueLetters && windowSize <= wordLength; windowSize += k) {
        ans += countCompleteStrings(word, k, windowSize);
    }    return ans;
}
int countCompleteStrings(const char* word, int k, int windowSize) {
    int res = 0;
    int countLetters = 0;  
    int count[26] = {0};
    int wordLength = strlen(word);
    for (int i = 0; i < wordLength; ++i) {
        count[word[i] - 'a']++;
        countLetters++;
        if (i > 0 && abs(word[i] - word[i - 1]) > 2) {
            memset(count, 0, sizeof(count));
            count[word[i] - 'a']++;
            countLetters = 1;
        }
        if (countLetters == windowSize + 1) {
            count[word[i - windowSize] - 'a']--;
            countLetters--;
        }
        if (countLetters == windowSize) {
            bool isComplete = true;
            for (int j = 0; j < 26; ++j) {
                if (count[j] != 0 && count[j] != k) {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete) {
                res++;
            }
        }
    }
    return res;
}
