class Solution {
    int m, n;
private:
    int solve(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        if(grid[i][j]) return true;
        grid[i][j] = 1;
        return solve(grid, i + 1, j) & solve(grid, i - 1, j) & solve(grid, i, j + 1) & solve(grid, i, j - 1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) {
                    if(solve(grid, i, j)) count++;
                }
            }
        }
        return count;
    }
};