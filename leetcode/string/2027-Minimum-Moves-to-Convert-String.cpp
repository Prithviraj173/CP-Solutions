class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, count = 0, n = s.length();
        while(i < n) {
            if(s[i] == 'X') {
                i += 3;
                count++;
            } else i++;
        }
        return count;
    }
};