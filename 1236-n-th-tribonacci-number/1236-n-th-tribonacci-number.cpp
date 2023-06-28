class Solution {
private:
    int tig(int n,vector<int>&dp){
         if(n==0){
            return 0;
        }
        else if(n==1) return 1;
        else if(n==2) return 1;
        else if (dp[n]!=-1) return dp[n];
        dp[n]= tig(n-1,dp)+tig(n-2,dp)+tig(n-3,dp);
        return dp[n];
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return tig(n,dp);
       
        // else return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};