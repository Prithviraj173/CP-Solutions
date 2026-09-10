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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        vector<int> res;
        while(temp) {
            res.push_back(temp -> val);
            temp = temp -> next;
        }
        size_t n = res.size(), start = 0, k = 1;
        while(start < n) {
            size_t len = min(k, n - start);
            if(!(len & 1)) reverse(res.begin() + start, res.begin() + start + len);
            start += len;
            k++;
        }
        if(!n) return NULL;
        temp = head;
        for(int num : res) {
            temp -> val = num;
            temp = temp -> next;
        }
        return head;
    }
};