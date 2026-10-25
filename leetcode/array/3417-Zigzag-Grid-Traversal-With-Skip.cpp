class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> res;
        bool take = true;
        for(int i = 0; i < n; i++) {
            if(!(i & 1)) {
                for(int j = 0; j < m; j++) {
                    if(take) res.push_back(grid[i][j]);
                    take = !take;
                }
            } else {
                for(int j = m - 1; j >= 0; j--) {
                    if(take) res.push_back(grid[i][j]);
                    take = !take;
                }
            }
        }
        return res;
    }
};