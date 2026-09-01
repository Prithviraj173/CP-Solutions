class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = 0, sc = 0, count = 0;
        int dp[20][20];
        memset(dp, -1, size(dp));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if(classroom[i][j] == 'L') dp[i][j] = count++;
            }
        }
        if(count == 0) return 0;
        int target = (1 << count) - 1;
        int best[20][20][1 << 10];
        memset(best, -1, sizeof(best));
        queue<vector<int>> q;
        q.push({sr, sc, 0, energy, 0});
        best[sr][sc][0] = energy;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur[0], c = cur[1], mask = cur[2], e = cur[3], moves = cur[4];
            if(mask == target) return moves;
            if(e == 0) continue;
            for(auto &d : dir) {
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') continue;
                int ne = e - 1;
                if(classroom[nr][nc] == 'R') ne = energy;
                int maski = mask;
                if(classroom[nr][nc] == 'L') maski |= (1 << dp[nr][nc]);
                if(ne > best[nr][nc][maski]) {
                    best[nr][nc][maski] = ne;
                    q.push({nr, nc, maski, ne, moves + 1});
                }
            }
        }
        return -1;
    }
};