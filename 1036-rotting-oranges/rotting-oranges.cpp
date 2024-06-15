class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
         if (grid.empty() || grid[0].empty()) {
            return 0;  
        }
        queue<pair<int, int>> p;
        int n = grid.size();
        int m = grid[0].size();
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    p.push({i, j});
                    // vis[i][j]=1;
                }
            }
        }
        // cout<<p.size();
        int count = 0;
        while (!p.empty()) {
            int z=p.size();
            for (int i = 0; i < z; i++) {
                auto a = p.front();
                int row = a.first;
                int col = a.second;
                p.pop();
                int nrow[4] = {0, 0, 1, -1};
                int ncol[4] = {1, -1, 0, 0};
                for (int j = 0; j < 4; j++) {
                    int nerow = row + nrow[j];
                    int necol = col + ncol[j];
                     if (nerow < n && nerow >= 0 && necol >= 0 && necol < m &&
                        grid[nerow][necol] == 1) {
 
                        grid[nerow][necol] = 2;
                        p.push({nerow, necol});
                    }
                }
            }
            cout << p.size() << "  ";

            if (p.size() > 0)
                count++;
        }
        // cout<<count;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }
};