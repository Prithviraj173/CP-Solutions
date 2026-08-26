class Solution {
public:
    int balancedStringSplit(string s) {
        int count_r = 0 , count_l = 0, n = s.length(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') count_l++;
            else count_r++;
            if(count_l == count_r) ans++;
        }
        return ans;
    }
};