class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        const int INF = INT_MAX;

        vector<vector<int>> best(rows, vector<int>(cols, INF));
        using State = pair<int, int>; // {effort, flattened cell id}
        priority_queue<State, vector<State>, greater<State>> pq;

        best[0][0] = 0;
        pq.push({0, 0});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [effort, id] = pq.top();
            pq.pop();

            int r = id / cols;
            int c = id % cols;

            // Ignore an outdated queue entry.
            if (effort != best[r][c]) continue;

            // The smallest-effort state is now finalized.
            if (r == rows - 1 && c == cols - 1) return effort;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                int stepDifference = abs(heights[r][c] - heights[nr][nc]);
                int candidate = max(effort, stepDifference);

                if (candidate < best[nr][nc]) {
                    best[nr][nc] = candidate;
                    int nextId = nr * cols + nc;
                    pq.push({candidate, nextId});
                }
            }
        }

        return 0; // destination is reachable in a rectangular grid
    }
};