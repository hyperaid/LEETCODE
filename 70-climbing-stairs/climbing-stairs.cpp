class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        int for1=solve(n-1,dp)  ;
        int for2=solve(n-2,dp);
        return dp[n]=for1+for2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};