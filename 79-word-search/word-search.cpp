class Solution {
public:
    bool dfs(int i,int j,int ind,string word,vector<vector<char>>& board,vector<vector<bool>>&dp){
        int n=board.size();
        int m=board[0].size();
        // cout<<ind<<endl;
        if(ind==word.length()) return true;
        if(i<0 ||j<0 || i>=n ||j>=m || dp[i][j]==1 || word[ind]!=board[i][j]) return false;
        dp[i][j]=1;
        // cout<<i<<"   "<<j<<endl;
        if(dfs(i+1,j,ind+1,word,board,dp) || dfs(i,j+1,ind+1,word,board,dp)
            || dfs(i-1,j,ind+1,word,board,dp)  || dfs(i,j-1,ind+1,word,board,dp)) return true;
        dp[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>dp(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,word,board,dp)) return true;
                    // cout<<dp[0][0];
                }
            }
        }
        return false;
    }
};