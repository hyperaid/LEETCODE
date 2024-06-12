class Solution {
public:
    int solve(int i, string s ,map<string,int>mpp,vector<int>&dp){
        if(i==s.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        string t="";

        for(int k=i;k<s.length();k++){
            t+=s[k];
            if(mpp.find(t)!=mpp.end()){
               if(solve(k+1,s,mpp,dp)) return dp[k]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mpp;
        for(auto it:wordDict) mpp[it]++;
        vector<int>dp(305,-1);
        return solve(0,s,mpp,dp);
    }
};