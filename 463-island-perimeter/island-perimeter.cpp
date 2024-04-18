class Solution {
public:
    int check(vector<vector<int>>& grid,int nrow[],int ncol[],int i ,int j){
        int n=grid.size();
        int m=grid[0].size();
        int count=4;
        for(int k=0;k<4;k++){
            int nr=i+nrow[k];
            int nc=j+ncol[k];
            if(nr>=0 &&nr<n &&nc>=0 && nc<m && grid[nr][nc]==1){
                count--;
            }
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count+=check(grid,nrow,ncol,i,j);
                
            }
        }
        return count;
    }
};