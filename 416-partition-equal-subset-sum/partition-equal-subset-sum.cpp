class Solution {
public:
    bool solve(vector<int>& nums,int i,int sum,vector<vector<int >>&dp ){
        if(sum==0) return 1;
        if(i==0){
            if(sum==nums[0]) return 1;
            return 0;
        }
        bool ntake=solve(nums,i-1,sum,dp);

        if(dp[i][sum]!=-1) return dp[i][sum];
        bool  take=false;
        if(sum>=nums[i]){
            take=solve(nums,i-1,sum-nums[i],dp);

        }
        return dp[i][sum]=(take|| ntake);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0) return false;
        vector<vector<int >>dp(n,vector<int >((sum/2)+1,-1));
        bool a=solve(nums,n-1,sum/2,dp);
        if(a){
            return true;

        }
        return false;
    }
};

