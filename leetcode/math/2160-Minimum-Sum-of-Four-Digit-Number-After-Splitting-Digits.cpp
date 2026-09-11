class Solution {
public:
    int minimumSum(int num) {
        vector<int> digit;
        while(num) {
            digit.push_back(num % 10);
            num /= 10;
        }
        sort(digit.begin(), digit.end());
        return 10 * (digit[0] + digit[1]) + (digit[2] + digit[3]);
    }
};