class Solution {
public:
// int solve(string a,string b,int a1,int b1,vector<vector<int>>&dp){
//     if(a1<0 || b1<0) return 0;
//     if(dp[a1][b1]!=-1) return dp[a1][b1];
//     if(a[a1]==b[b1]) return dp[a1][b1]=1+solve(a,b,a1-1,b1-1,dp);
//     int atake =solve(a,b,a1-1,b1,dp);
//     int btake =solve(a,b,a1,b1-1,dp);
//     return dp[a1][b1]=max(atake,btake);

// }
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return solve(a,b,n-1,m-1,dp);
        // vector<vecto
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};