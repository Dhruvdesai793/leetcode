class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int valid_islands = 0;
        vector<pair<int, int>> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}}; 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long island_sum = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({i, j});
                    island_sum += grid[i][j];
                    grid[i][j] = 0; 

                    while (!q.empty()) {
                        auto [curr_y, curr_x] = q.front();
                        q.pop();

                        for (auto [dx, dy] : dir) {
                            int nx = curr_x + dx;
                            int ny = curr_y + dy;

                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[ny][nx] > 0) {
                                island_sum += grid[ny][nx];
                                q.push({ny, nx});
                                grid[ny][nx] = 0; 
                            }
                        }
                    }

                    if (island_sum % k == 0) {
                        valid_islands++;
                    }
                }
            }
        }
        return valid_islands;
    }
};