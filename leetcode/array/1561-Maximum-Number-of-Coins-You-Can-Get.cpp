class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        deque<int> queue;
        for(int num : piles) queue.push_back(num);
        while(!queue.empty()) {
            queue.pop_back();
            ans += queue.back();
            queue.pop_back();
            queue.pop_front();
        }
        return ans;
    }
};