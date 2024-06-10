class Solution {
public: 
    int maxi;
    int solve(vector<int>&a,int ind,int sum,vector<vector<int>>&dp){
        if(ind>=a.size()){
             return 0;
        }
        // if(sum)
        if(sum>=maxi) return 0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int ntake=solve(a,ind+1,sum,dp);
        int take=0;
        if( sum<a[ind]){
            take=a[ind]+solve(a,ind+1,sum+a[ind],dp);
        }
        return dp[ind][sum]=max(take,ntake);
    }
    int maxTotalReward(vector<int>& a) {
        int ans=0;
        int sum=0;
         maxi = *max_element(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(maxi+1,-1));

        sort(a.begin(),a.end());
        return  solve(a,0,0,dp);
    }
};