class Solution {
public:
    int solve(vector<int>& coins, int amount, int i,vector<vector<int>>&dp) {
        if (i == 0) {

            if (amount % coins[0] == 0) {
                return amount / coins[0];
            }
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
         int take = INT_MAX;
        if (amount >= coins[i]) {
            take = 1 + solve(coins, amount - coins[i], i,dp);//yaha ba t take ki jagah int take kar diya tha tase 
            //bhai din harab kiya isne
        }

        int notTake = solve(coins, amount, i - 1,dp);
       
        return dp[i][amount]=min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>>dp(n+1,vector<int>(10001,-1));
        int a= solve(coins, amount, n - 1,dp);
        if(a>100000) return -1;
        return a;
    }
};
