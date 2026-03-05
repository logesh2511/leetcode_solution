#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, 0));
        int maxLength = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxLength = max(maxLength, dfs(matrix, memo, i, j));
            }
        }
        
        return maxLength;
    }

private:
    vector<int> dirs = {0, 1, 0, -1, 0};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int row, int col) {
        if (memo[row][col] != 0) return memo[row][col];
        
        int maxLength = 1; // At least the path includes the cell itself
        for (int k = 0; k < 4; ++k) {
            int newRow = row + dirs[k];
            int newCol = col + dirs[k + 1];
            if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() && matrix[newRow][newCol] > matrix[row][col]) {
                int length = 1 + dfs(matrix, memo, newRow, newCol);
                maxLength = max(maxLength, length);
            }
        }
        
        memo[row][col] = maxLength;
        return maxLength;
    }
};
