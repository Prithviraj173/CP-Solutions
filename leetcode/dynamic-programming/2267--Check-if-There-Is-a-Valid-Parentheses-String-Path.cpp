class Solution {
private:
    int dp[101][101][201];
    bool solve(int i, int j, int k, vector<vector<char>>& grid) {
        if(i >= grid.size() || j >= grid[0].size() || (k += (grid[i][j] == '(') * 2 - 1) < 0) return 0;
        if(i == grid.size() - 1 && j == grid[0].size() - 1) return !k;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        return dp[i][j][k] = solve(i + 1, j, k, grid) || solve(i, j + 1, k, grid);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, grid);
    }
};