class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int ans = 0, j = 0, n = arr2.size();
        for(int i : arr1) {
            while(j < n && arr2[j] < i - d) j++;
            if(j == n || arr2[j] > i + d) ans++;
        }
        return ans;
    }
};