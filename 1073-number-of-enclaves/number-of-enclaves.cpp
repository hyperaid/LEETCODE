class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {
        vis[i][j] = 1;
        int n=grid.size();
        int m=grid[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int k=0;k<4;k++){
            int row=i+dx[k];
            int col=j+dy[k];
            if(row>=0 && row<n && col>=0  && col<m && vis[row][col]==0 && grid[row][col]==1){
                dfs(row,col,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, vis, grid);
            }
            if (grid[n - i - 1][m - 1]) {
                dfs(n - i - 1, m-1, vis, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                dfs(0, i, vis, grid);
            }
            if (grid[n - 1][m-i-1] == 1) {
                dfs(n - 1, m-i-1, vis, grid);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j]== 0) {
                    count++;
                }
            }
        }
        return count;
    }
};