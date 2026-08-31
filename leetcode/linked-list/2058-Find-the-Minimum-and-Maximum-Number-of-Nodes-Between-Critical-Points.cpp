/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res;
        ListNode* temp = head;
        while(temp != NULL) {
            res.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = res.size();
        if(res.size() < 3) return {-1, -1};
        vector<int> ans;
        for(int i = 1; i < n - 1; i++) {
            if((res[i - 1] < res[i] && res[i] > res[i + 1]) || (res[i - 1] > res[i] && res[i] < res[i + 1])) ans.push_back(i);
        }
        int m = ans.size();
        if(m < 2) return {-1, -1};
        int maxi = ans.back() - ans.front(), mini = INT_MAX;
        for(int i = 0; i < m - 1; i++) {
            int diff = ans[i + 1] - ans[i];
            if(diff < mini) mini = diff;
        }
        return {mini, maxi};
    }
};