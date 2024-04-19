class Solution {
private:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        int x=grid.size();
        int y=grid[0].size();
        q.push({row,col});
        while(!q.empty()){
            int n=q.front().first;
            int m=q.front().second;
            q.pop();
            // for(int nrow=-1;nrow<=1;nrow++){
            //     for(int ncol=-1;ncol<=1;ncol++){
            //         int a=nrow+n;
            //         int b=ncol+m;
                    
            //         if(a>=0 && a<x && b>=0 && b<y && grid[a][b]=='1' && !vis[a][b]){
            //             vis[a][b]=1;
            //             q.push({a,b});
            //         }
            //     }

            // }
            for(int nrow=-1;nrow<=1;nrow++){
                int a=n+nrow;
                int b=m;
                if(a>=0 && a<x && b>=0 && b<y && grid[a][b]=='1' && !vis[a][b]){
                    vis[a][b]=1;
                    q.push({a,b});
                }   
            }
            for(int ncol=-1;ncol<=1;ncol++){
                int a=n;
                int b=ncol+m;
                if(a>=0 && a<x && b>=0 && b<y && grid[a][b]=='1' && !vis[a][b]){
                    vis[a][b]=1;
                    q.push({a,b});
                }

            }

            
        }
    }
public:

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] &&grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};