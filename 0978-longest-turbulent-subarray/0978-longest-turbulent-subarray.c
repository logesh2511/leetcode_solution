int max(int a, int b, int c) {
    if (a > b) {
        return a > c ? a : c;
    } else {
        return b > c ? b : c;
    }
}
int maxTurbulenceSize(int* arr, int arrSize) {
    if (arrSize == 0) return 0;
    int ans = 1, f = 1, g = 1;
    for (int i = 1; i < arrSize; ++i) {
        int ff = arr[i - 1] < arr[i] ? g + 1 : 1;
        int gg = arr[i - 1] > arr[i] ? f + 1 : 1;
        f = ff;
        g = gg;
        ans = max(ans, f, g);
    }
    return ans;
}

