class Solution {
public:
    int solve(int sticks,int sticke,int cutss,int cutse,vector<int>&cuts,vector<vector<int>>&dp){
        if(cutss>cutse){
            return 0;
        }
        if(dp[cutss][cutse]!=-1) return dp[cutss][cutse]; 
        int mini=1e9;//for minimiztion dont make it global
        for(int i=cutss;i<=cutse;i++){
            int cost=sticke-sticks+
                            solve(sticks,cuts[i],cutss,i-1,cuts,dp)+//for left porion 
                            solve(cuts[i],sticke,i+1,cutse,cuts,dp);//for right porion 
            mini=min(mini,cost);
        }
        return dp[cutss][cutse]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return solve(0,n,0,cuts.size()-1,cuts,dp);
    }
};