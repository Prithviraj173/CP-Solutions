class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr, brr;
        arr.push_back(nums[0]), brr.push_back(nums[1]);
        for(int i = 2; i < n; i++) {
            if(arr.back() > brr.back()) arr.push_back(nums[i]);
            else brr.push_back(nums[i]);
        }
        arr.insert(arr.end(), brr.begin(), brr.end());
        return arr;
    }
};