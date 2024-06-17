class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

        q.push({1, {0, 0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        // vector<vector<int>> vis(n, vector<int>(m, -1));
        // int n=mat.size();
        if (grid[0][0] == 1)
            return -1;
        if (n == 1)
            return 1;
        dist[0][0] = 1;
        while (!q.empty()) {
            auto a = q.top();
            int i = a.second.first;
            int j = a.second.second;
            int distance = a.first;
            q.pop();
            for (int k = 0; k < 8; k++) {
                int nrow = i + dx[k];
                int ncol = j + dy[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (grid[nrow][ncol] == 0 &&
                        1 + distance < dist[nrow][ncol]) {
                        dist[nrow][ncol] = 1 + distance;

                        q.push({1 + distance, {nrow, ncol}});

                        // 1+distance<dist[nrow][ncol]
                    }
                    if (nrow == n - 1 && ncol == n - 1 && grid[nrow][ncol]==0)
                        return 1 + distance;
                }
            }
        }
        return -1;
    }
};