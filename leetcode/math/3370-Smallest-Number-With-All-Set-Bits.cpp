class Solution {
public:
    int smallestNumber(int n) {
        int temp = n, count = -1;
        while(temp > 0) {
            count++;
            temp /= 2;
        }
        return pow(2, count + 1) - 1;
    }
};