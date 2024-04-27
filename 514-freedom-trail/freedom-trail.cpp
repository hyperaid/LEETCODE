class Solution {
public:
    int dp[101][101];
    int helper(string& ring,string& key,int idx1,int idx2,map<char,vector<int>>& mp){
        int n = ring.size();
        if(idx2==key.size()){
            return 0;
        }
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(ring[idx1]==key[idx2]){
            return 1+helper(ring,key,idx1,idx2+1,mp);
        }
        int ans = INT_MAX;
        char tofind = key[idx2];
        vector<int> allIdx = mp[tofind];
        
        for(auto it : allIdx){
            int mindist = min(abs(it-idx1),n-abs(it-idx1));
            int tempans = helper(ring,key,it,idx2,mp);
            if(tempans!=INT_MAX)
            ans = min(ans,mindist+tempans);
        }
        return dp[idx1][idx2] = ans;
    }

    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        map<char,vector<int>> mp;
        for(int i = 0;i<ring.size();i++){
            mp[ring[i]].push_back(i);
        }
        return helper(ring,key,0,0,mp);
    }
};