class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1);
        vector<vector<int>> ans;
        for(int c : nums) {
            if(freq[c] >= ans.size()) ans.push_back({});
            ans[freq[c]].push_back(c);
            freq[c]++;
        }
        return ans;
    }
};