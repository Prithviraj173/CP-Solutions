class Solution {
public:
    int reverseDegree(string s) {
        long long sum = 0;
        for(int i = 0; i < s.length(); i++) {
            sum += 1LL * ('z' - s[i] + 1) * (i + 1);
        }
        return sum;
    }
};