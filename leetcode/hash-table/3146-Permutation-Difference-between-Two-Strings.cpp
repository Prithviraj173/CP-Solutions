class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int diff = 0;
        for(int i = 0; i < s.length(); i++) {
            int j = t.find(s[i]);
            diff += abs(i - j);
        }
        return diff;
    }
};