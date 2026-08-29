class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        if(n == 0) return {};
        vector<pair<int, int>> sorted;
        for(int i = 0; i < n; i++) sorted.emplace_back(nums[i], i);
        sort(sorted.begin(), sorted.end());
        vector<int> res(n);
        int st = 0;
        for(int i = 0; i < n; i++) {
            if(i == n - 1 || sorted[i + 1].first - sorted[i].first > limit) {
                vector<int> idx;
                for(int j = st; j <= i; j++) idx.push_back(sorted[j].second);
                sort(idx.begin(), idx.end());
                for(int j = 0; j < idx.size(); j++) res[idx[j]] = sorted[st + j].first;
                st = i + 1;
            }
        }
        return res;
    }
};