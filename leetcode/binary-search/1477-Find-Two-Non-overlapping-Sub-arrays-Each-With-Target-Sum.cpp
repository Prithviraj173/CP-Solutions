class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        int n = arr.size(), ans = INT_MAX, sum = 0, mini = INT_MAX;
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(mp.count(sum - target)) {
                int j = mp[sum - target];
                int diff = i - j;
                if(j != -1 && arr[j] != INT_MAX) ans = min(ans,diff + arr[j]);
                mini = min(mini, diff);
            }
            arr[i] = mini;
            mp[sum] = i;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};