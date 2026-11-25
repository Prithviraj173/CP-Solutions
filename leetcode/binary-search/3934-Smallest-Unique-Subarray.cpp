class Solution {
    struct State {
        int len = 0;
        int link = -1;
        int cnt = 0;
        map<int, int> next;
    };
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<State> st;
        st.reserve(2 * n + 1);
        st.push_back(State());
        int last = 0;
        for (int x : nums) {
            int cur = st.size();
            st.push_back(State());
            st[cur].len = st[last].len + 1;
            st[cur].cnt = 1;

            int p = last;
            while (p != -1 && st[p].next.find(x) == st[p].next.end()) {
                st[p].next[x] = cur;
                p = st[p].link;
            }
            if (p == -1) {
                st[cur].link = 0;
            } else {
                int q = st[p].next[x];
                if (st[p].len + 1 == st[q].len) {
                    st[cur].link = q;
                } else {
                    int clone = st.size();
                    State clone_state = st[q];
                    clone_state.len = st[p].len + 1;
                    clone_state.cnt = 0;
                    st.push_back(std::move(clone_state));
                    while (p != -1) {
                        auto it = st[p].next.find(x);
                        if (it == st[p].next.end() || it->second != q) break;
                        it->second = clone;
                        p = st[p].link;
                    }
                    st[q].link = st[cur].link = clone;
                }
            }
            last = cur;
        }
        int sz = st.size();
        vector<int> bucket(n + 1, 0);
        for (int i = 0; i < sz; ++i) {
            bucket[st[i].len]++;
        }
        for (int i = 1; i <= n; ++i) {
            bucket[i] += bucket[i - 1];
        }
        vector<int> order(sz);
        for (int i = sz - 1; i >= 0; --i) {
            order[--bucket[st[i].len]] = i;
        }
        int ans = n;
        for (int i = sz - 1; i >= 1; --i) {
            int u = order[i];
            st[st[u].link].cnt += st[u].cnt;
            if (st[u].cnt == 1) {
                ans = min(ans, st[st[u].link].len + 1);
            }
        }
        return ans;
    }
};