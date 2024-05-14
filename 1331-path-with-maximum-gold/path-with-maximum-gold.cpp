class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,int sum,int &ans,vector<vector<int>>&vis){
        int nrow[]= {-1, 1, 0, 0};
        int ncol[]= {0, 0, -1, 1};
        int n=grid.size();
        int m=grid[0].size();
        sum+=grid[row][col];
        ans=max(ans,sum);

        for(int i=0;i<4;i++){
            int ro=row+nrow[i];
            int co=col+ncol[i];
            if(ro>=0 && ro<n && co>=0 && co<m && grid[ro][co]!=0 &&vis[ro][co]!=1){
                vis[ro][co]=1;
                dfs(grid,ro,co,sum,ans,vis);
                vis[ro][co] = 0;
            }
             
        }

    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
   
        int sum=0;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                     vis[i][j]=1;
                    dfs(grid,i,j,sum,ans,vis);
                    vis[i][j]=0;
                    
                }
            
            }
        }
        return ans;
    }
};