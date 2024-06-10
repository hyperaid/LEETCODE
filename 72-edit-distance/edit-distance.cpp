class Solution {
public:
 
    int solve(string a,string b, int n,int m, vector<vector<int>>&dp ){
        if(n==0 || m==0){
            if(n==0) return dp[n][m]=m;
            if(m==0) return dp[n][m]=n;
        }
        if(dp[n][m]!=-1) return dp[n][m];
         if(a[n-1]==b[m-1]) return dp[n][m]=solve(a,b,n-1,m-1,dp);
   
        int insertion= solve(a,b,n,m-1,dp);
        int delete1= solve(a,b,n-1,m,dp);
        int replace= solve(a,b,n-1,m-1,dp);    
        return dp[n][m]=1+min({insertion,delete1,replace});
        
 
        
    }
    int minDistance(string a, string b) {
        int n=a.size();
        int m=b.size();
        if(n==0 ||m==0){
            return max(n,m);
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return  solve(a,b,n,m,dp);
    }
};