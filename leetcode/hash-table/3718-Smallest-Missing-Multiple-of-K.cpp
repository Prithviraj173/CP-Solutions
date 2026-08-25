class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;
        int ans = k;
        for(auto const& [val, freq] : mp) {
            if(mp.find(ans) != mp.end()) ans += k;
        }
        return ans;
    }
};