int max(int a, int b) {
    return (a > b) ? a : b;
}
int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize, n = *matrixColSize;
    int** result = (int**)malloc(sizeof(int*) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i) {
        result[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    for (int j = 0; j < n; ++j) {
        int mx = -1;
        for (int i = 0; i < m; ++i) {
            mx = max(mx, matrix[i][j]);
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][j] == -1) {
                result[i][j] = mx;
            } else {
                result[i][j] = matrix[i][j];
            }
        }
    }
    *returnSize = m;
    return result;
}
