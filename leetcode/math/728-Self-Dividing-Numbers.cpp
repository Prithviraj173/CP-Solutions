class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            int temp = i;
            vector<int> res;
            while(temp > 0) {
                int digit = temp % 10;
                temp /= 10;
                res.push_back(digit);
            }
            bool flag = true;
            for(int j = 0; j < res.size(); j++) {
                if(res[j] == 0 || i % res[j] != 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};