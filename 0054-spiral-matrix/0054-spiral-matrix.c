int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = *matrixColSize;
    int dirs[5] = {0, 1, 0, -1, 0};
    int i = 0, j = 0, k = 0;
    int* ans = (int*)malloc(m * n * sizeof(int));
    bool vis[m][n];
    memset(vis, false, sizeof(vis));
    *returnSize = 0;
    for (int h = m * n; h; --h) {
        ans[(*returnSize)++] = matrix[i][j];
        vis[i][j] = true;
        int x = i + dirs[k], y = j + dirs[k + 1];
        if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
            k = (k + 1) % 4;
        }
        i += dirs[k];
        j += dirs[k + 1];
    }
    return ans;
}
