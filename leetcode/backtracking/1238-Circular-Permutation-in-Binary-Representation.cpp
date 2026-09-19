class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        int peak = pow(2, n), idx = -1;
        for(int i = 0; i < peak; i++) {
            int gray = i ^ (i >> 1);
            if(gray == start) idx = i;
            ans.push_back(gray);
        }
        n = ans.size();
        int ptr1 = 0, ptr2 = idx;
        while(ptr1 < ptr2) {
            swap(ans[ptr1], ans[ptr2]);
            ptr1++, ptr2--;
        }
        ptr1 = idx + 1, ptr2 = n - 1;
        while(ptr1 < ptr2) {
            swap(ans[ptr1], ans[ptr2]);
            ptr1++, ptr2--;
        }
        return ans;
    }
};