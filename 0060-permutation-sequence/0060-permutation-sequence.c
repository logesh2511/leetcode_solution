#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getPermutation(int n, int k) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    char *result = (char *)malloc((n + 1) * sizeof(char));
    int index, number;
    int nums[n];

    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    k--;

    for (int i = 0; i < n; i++) {
        factorial /= (n - i);
        index = k / factorial;
        number = nums[index];

        for (int j = index; j < n - i - 1; j++) {
            nums[j] = nums[j + 1];
        }

        result[i] = number + '0';
        k %= factorial;
    }

    result[n] = '\0';
    return result;
}
