class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) adj[edge[0]].emplace_back(edge[1], edge[2]);
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        vector<int> min_c(n, k + 1);
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][1] = 0;
        pq.emplace(0, 0, 1);
        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();
            if (u == n - 1) return d;
            if (d > dist[u][cur] || cur >= min_c[u]) continue;
            min_c[u] = cur;
            for (const auto& [v, w] : adj[u]) {
                int nxt = (labels[v] == labels[u]) ? cur + 1 : 1;
                int nd = d + w;
                if (nxt < min_c[v] && nd < dist[v][nxt]) {
                    dist[v][nxt] = nd;
                    pq.emplace(nd, v, nxt);
                }
            }
        }

        return -1;
    }
};