class Solution {
public:
    int maxVowels(string s, int k) {
        int len = 0, cur = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            if(i >= k && (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u')) cur--;
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cur++;
            len = max(len , cur);
        }
        return len;
    }
};