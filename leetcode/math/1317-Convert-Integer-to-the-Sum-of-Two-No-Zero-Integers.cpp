class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int temp1 = i, temp2 = j;
                bool flag1 = true, flag2 = true;
                while(temp1 > 0) {
                    int digit = temp1 % 10;
                    temp1 /= 10;
                    if(digit == 0) {
                        flag1 = false;
                        break;
                    }
                }
                while(temp2 > 0) {
                    int digit = temp2 % 10;
                    temp2 /= 10;
                    if(digit == 0) {
                        flag2 = false;
                        break;
                    }
                }
                if(i + j == n && flag1 && flag2) return {i, j};
            }
        }
        return {-1, -1};
    }
};