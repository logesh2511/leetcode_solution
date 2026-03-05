#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** answer = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; ++i) {
        int num = i + 1;
        if (num % 3 == 0 && num % 5 == 0) {
            answer[i] = strdup("FizzBuzz");
        } else if (num % 3 == 0) {
            answer[i] = strdup("Fizz");
        } else if (num % 5 == 0) {
            answer[i] = strdup("Buzz");
        } else {
            char buffer[20];
            sprintf(buffer, "%d", num);
            answer[i] = strdup(buffer);
        }
    }
    return answer;
}
