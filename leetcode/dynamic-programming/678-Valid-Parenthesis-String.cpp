class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length(), maxi = 0, mini = 0;
        for(int i = 0; i < n; i++) {
            maxi += (s[i] == '(') - (s[i] == ')') + (s[i] == '*');
            mini += (s[i] == '(') - (s[i] == ')') - (s[i] == '*');
            if(maxi < 0) return false;
            mini = max(mini, 0);
        }
        return mini == 0;
    }
};