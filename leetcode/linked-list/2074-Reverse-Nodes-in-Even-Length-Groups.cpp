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
        vector<int> res;
        ListNode* temp = head;
        while(temp) {
            res.push_back(temp -> val);
            temp = temp -> next;
        }
        size_t start = 0, k = 1;
        while(start < res.size()) {
            size_t len = min(k, res.size() - start);
            if(!(len & 1)) reverse(res.begin() + start, res.begin() + start + len);
            start += len;
            k++;
        }
        if(res.size() == 0) return NULL;
        temp = head;
        for(int num : res) {
            temp -> val = num;
            temp = temp -> next;
        }
        return head;
    }
};