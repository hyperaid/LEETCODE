class Solution {
public:
    bool ispalindrome(int i,int j,string& s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int start,string &s,vector<int>&dp){
        if(start==s.length()){
            return 0;
        }
        if(dp[start]!=-1) return dp[start];
        int mini=1e9;
        // string t="";
        for(int i=start;i<s.length();i++){
            // t+=s[i];
            if(ispalindrome(start,i,s)){
                int cost=1+solve(i+1,s,dp);
                mini=min(mini,cost);
            }

        }
        return dp[start]=mini;
    }
    int minCut(string s) {
        vector<int>dp(s.length(),-1);
        return solve(0,s,dp)-1;//as it will do a partioon at the end also so to get rid from that i adde
        //it here 

    }
};