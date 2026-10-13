class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        set<int> ans, res;
        for(int num : nums1) {
            if(!(st2.count(num))) ans.insert(num);
        }
        for(int num : nums2) {
            if(!(st1.count(num))) res.insert(num);
        }
        vector<int> cur, temp;
        for(int num : ans) cur.push_back(num);
        for(int num : res) temp.push_back(num);
        return {cur, temp};
    }
};