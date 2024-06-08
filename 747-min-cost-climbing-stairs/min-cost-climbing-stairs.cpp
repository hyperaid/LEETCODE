class Solution {
public:
    int solve(int n,vector<int>&dp,vector<int>&cost){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        if(dp[n]!=-1) return dp[n];
        int for1=cost[n]+solve(n-1,dp,cost);
        int for2=cost[n]+solve(n-2,dp,cost);
        return dp[n]=min(for1,for2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);

        return min(solve(n-1,dp,cost),solve(n-2,dp,cost));

    }
};