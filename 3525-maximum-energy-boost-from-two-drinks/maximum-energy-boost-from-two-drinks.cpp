class Solution {
public:
    long long solve(long long i,long long j, vector<int>& A, vector<int>& B,vector<vector<long long>>&dp){
        if(i==A.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long take=INT_MIN;
        if(j==0) take=A[i]+solve(i+1,0,A,B,dp);
        if(j==1) take=B[i]+solve(i+1,1,A,B,dp);
        long long ntake=INT_MIN;
        if(j==0 && (i+2)<A.size()){
            ntake=A[i] +solve(i+2,1,A,B,dp);
        }
        if(j==1 && (i+2)<A.size()){
            ntake=B[i] +solve(i+2,0,A,B,dp);
        }
        // cout<<take<<" "<<ntake<<endl;
        return dp[i][j]=max(take,ntake);
        
    }
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {

        int n=A.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return max(solve(0,0,A,B,dp),solve(0,1 ,A,B,dp));
    }
};