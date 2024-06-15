class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]== 0) {
                    q.push({{i, j}, 0});
                    // dist[i][j]=0;
                }
            }
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int qs = q.size();

            for (int i = 0; i < qs; i++) {
                auto a = q.front();
                int r = a.first.first;
                int c=a.first.second;
                int steps=a.second;
                dist[r][c]=steps;
                q.pop();
                for(int j=0;j<4;j++){
                    int row=r+dx[j];
                    int col=c+dy[j];
                    if(row>=0 &&row<n  && col>=0 && col<m  &&vis[row][col]==0 && mat[row][col]==1){
                        q.push({{row,col},steps+1});
                        vis[row][col]=1;
                    }
                }

            }
        }
        return dist;
    }
};