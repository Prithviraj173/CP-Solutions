class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        multiset<int, greater<int>> s;
        for(auto num : arr) mp[num]++;
        for(auto const& [val , freq] : mp) s.insert(freq);
        for(int deleted{}, ans{}; auto freq : s) {
            deleted += freq;
            ans++;
            if(deleted >= n / 2) return ans;
        }
        return -1;
    }
};