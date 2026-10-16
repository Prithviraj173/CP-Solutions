class Solution {
    static const int MOD = 1e9 + 7;
    struct Node {
        long long sum1 = 0;
        long long sum2 = 0;
        long long lazy = 0;
    };
    vector<Node> tree;
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        tree[node].sum2 = (tree[node].sum2 + 2 * val % MOD * tree[node].sum1 + len * val % MOD * val) % MOD;
        tree[node].sum1 = (tree[node].sum1 + len * val) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }
    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, l, mid, tree[node].lazy);
            apply(2 * node + 1, mid + 1, r, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }
    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            update(2 * node, l, mid, ql, qr, val);
        }
        if (qr > mid) {
            update(2 * node + 1, mid + 1, r, ql, qr, val);
        }
        tree[node].sum1 = (tree[2 * node].sum1 + tree[2 * node + 1].sum1) % MOD;
        tree[node].sum2 = (tree[2 * node].sum2 + tree[2 * node + 1].sum2) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 1, Node());
        vector<int> last(100001, -1);
        long long total_ans = 0;

        for (int j = 0; j < n; ++j) {
            int x = nums[j];
            int prev_idx = last[x];
            update(1, 0, n - 1, prev_idx + 1, j, 1);
            total_ans = (total_ans + tree[1].sum2) % MOD;

            last[x] = j;
        }
        return total_ans;
    }
};