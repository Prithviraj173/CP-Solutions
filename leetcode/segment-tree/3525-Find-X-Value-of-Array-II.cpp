class Solution {
    struct Node {
        int prod = 1;
        int count[5] = {0};
    };
    vector<Node> tree;
    int mod;
    Node merge(const Node& a, const Node& b) {
        Node result;
        result.prod = (1LL * a.prod * b.prod) % mod;
        for (int i = 0; i < mod; ++i) {
            result.count[i] += a.count[i];
        }
        for (int i = 0; i < mod; ++i) {
            int new_rem = (1LL * a.prod * i) % mod;
            result.count[new_rem] += b.count[i];
        }

        return result;
    }
    Node makeLeaf(int val) {
        Node node;
        node.prod = val % mod;
        node.count[val % mod] = 1;
        return node;
    }
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        mod = k;
        int n = nums.size();
        tree.assign(2 * n, Node());
        for (int i = 0; i < n; ++i) {
            tree[n + i] = makeLeaf(nums[i]);
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
        vector<int> answers;
        answers.reserve(queries.size());
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int target_x = q[3];
            int pos = n + idx;
            tree[pos] = makeLeaf(val);
            for (pos /= 2; pos > 0; pos /= 2) {
                tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
            }
            Node left_accum;
            Node right_accum;
            int l = n + start;
            int r = 2 * n;
            while (l < r) {
                if (l % 2 == 1) {
                    left_accum = merge(left_accum, tree[l]);
                    l++;
                }
                if (r % 2 == 1) {
                    r--;
                    right_accum = merge(tree[r], right_accum);
                }
                l /= 2;
                r /= 2;
            }
            Node range_result = merge(left_accum, right_accum);
            answers.push_back(range_result.count[target_x]);
        }
        return answers;
    }
};