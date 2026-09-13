class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> a, b;
        int n = img1.size(), res = 0;
        for(int i = 0; i < n * n; i++) {
            if(img1[i / n][i % n]) a.push_back(i/n * 100 + i % n);
            if(img2[i / n][i % n]) b.push_back(i/n * 100 + i % n);
        }
        unordered_map<int, int> mp;
        for(int i : a) {
            for(int j : b) {
                res = max(res, ++mp[i - j]);
            }
        }
        return res;
    }
};