class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int count1 = 1, count2 = 1, maxi1 = 1, maxi2 = 1, n = arr.size();
        for(int i = 0; i < n - 1; i++) {
            if(arr[i + 1] > arr[i]) {
                count1++;
                maxi1 = max(maxi1, count1);
            } else if(arr[i + 1] <= arr[i]) count1 = 1;
            if(arr[i + 1] < arr[i]) {
                count2++;
                maxi2 = max(maxi2, count2);
            } else if(arr[i + 1] >= arr[i]) count2 = 1;
        }
        return max(maxi1, maxi2);
    }
};