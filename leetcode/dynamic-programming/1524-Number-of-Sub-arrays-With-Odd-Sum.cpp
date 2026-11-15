class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum = 0, n = arr.size(), odd = 0, even = 1, M = 1e9 + 7;;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum & 1) odd++;
            else even++;
        }
        return (even * odd) % M;
    }
};