class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> res(n);
        for(int i = 1; i < n; i++) res[parent[i]].push_back(i);
        vector<int> ans(n, 1), last(26, -1);
        auto dfs = [&](auto&& self, int i) -> void {
            int c = s[i] - 'a', prev = last[c];
            last[c] = i;
            for(int j : res[i]) self(self, j);
            last[c] = prev;
            if(int k = prev < 0 ? parent[i] : prev; k >= 0) ans[k] += ans[i];
        };
        dfs(dfs, 0);
        return ans;
    }
};