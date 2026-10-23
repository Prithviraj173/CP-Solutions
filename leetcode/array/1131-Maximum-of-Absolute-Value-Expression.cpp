class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), ans = 0;
        const int st[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(const auto &s : st) {
            int s1 = s[0], s2 = s[1], mini = INT_MAX, maxi = INT_MIN;
            for(int i = 0; i < n; i++) {
                int cur = s1 * arr1[i] + s2 * arr2[i] + i;
                mini = min(mini, cur);
                maxi = max(maxi, cur);
            }
            ans = max(ans, maxi - mini);
        }
        return ans;
    }
};