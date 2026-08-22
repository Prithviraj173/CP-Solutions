class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int temp1 = n, temp2 = n;
        while(temp1 > 0) {
            int digit = temp1 % 10;
            sum += digit;
            temp1 /= 10;
        }
        while(temp2 > 0) {
            int digit = temp2 % 10;
            prod *= digit;
            temp2 /= 10;
        }
        return !(n % (sum + prod));
    }
};