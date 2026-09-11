class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0}, count = 0;
        for(int d : digits) freq[d]++;
        for(int i = 100; i < 1000; i += 2) {
            int d1 = i / 100, d2 = (i / 10) % 10, d3 = i % 10;
            int need[10] = {0};
            need[d1]++, need[d2]++, need[d3]++;
            if(need[d1] <= freq[d1] && need[d2] <= freq[d2] && need[d3] <= freq[d3]) count++;
        }
        return count;
    }
};