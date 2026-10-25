class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        double sum = 0;
        for(int num : nums) sum += num;
        double res = sum / 2;
        int count = 0;
        while(sum > res) {
            double t = pq.top();
            pq.pop();
            double s = t / 2;
            sum += (s - t);
            pq.push(s);
            count++;
        }
        return count;
    }
};