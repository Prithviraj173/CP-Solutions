class Solution {
private:
    long long M = 1e9 + 7;
    vector<vector<long long>> pascal;
    long long dfs(const vector<int>& nums) {
        int m = nums.size();
        if (m < 3) return 1;
        vector<int> lt, rt;
        for (int i = 1; i < m; i++) {
            if (nums[i] < nums[0]) lt.push_back(nums[i]);
            else rt.push_back(nums[i]); 
        }
        long long lt_way = dfs(lt), rt_way = dfs(rt);
        long long ways = pascal[m - 1][lt.size()];
        long long res = (ways * lt_way) % M;
        res = (res * rt_way) % M;
        return res;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascal.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            pascal[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % M;
            }
        }
        return (dfs(nums) - 1 + M) % M;
    }
};