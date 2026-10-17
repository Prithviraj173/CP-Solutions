class Solution {
private:
    int sum(int n) {
        int res;
        while(n) {
            int digit = n % 10;
            res += digit;
            n /= 10;
        }
        return res;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), count = 0;
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++) arr.push_back({sum(nums[i]), nums[i]});
        vector<int> res(n);
        iota(res.begin(), res.end(), 0);
        sort(res.begin(), res.end(), [&](int i, int j){
            return arr[i] < arr[j];
        });
        for(int i = 0; i < n; i++) {
            while(res[i] != i) {
                swap(res[i], res[res[i]]);
                count++;
            }
        }
        return count;
    }
};