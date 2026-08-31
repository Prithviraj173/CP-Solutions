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
    ListNode* doubleIt(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp != NULL) {
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = ans.size(), val = 0;
        vector<int> cur;
        for(int i = n - 1; i >= 0; i--) {
            int prod = ans[i] * 2 + val;
            cur.push_back(prod % 10);
            val = prod / 10;
        }
        if(val > 0) cur.push_back(val);
        int m = cur.size();
        reverse(cur.begin(), cur.end());
        ListNode* dummy = new ListNode(0);
        temp = dummy;
        for(int i = 0; i < m; i++) {
            ListNode* here = new ListNode(cur[i]);
            temp -> next = here;
            temp = here;
        }
        return dummy -> next;
    }
};