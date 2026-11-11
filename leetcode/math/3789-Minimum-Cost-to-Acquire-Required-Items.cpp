class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        return min(cost1 + cost2, costBoth) * min(need1, need2)+ (need1 - min(need1, need2)) * min(cost1, costBoth) + (need2 - min(need1, need2)) * min(cost2, costBoth);
    }
};