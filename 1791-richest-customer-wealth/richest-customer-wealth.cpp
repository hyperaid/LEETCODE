class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<accounts.size();i++){
            for(int j=0;j<accounts[0].size();j++){
                sum+=accounts[i][j];
            }
            maxi=max(sum,maxi);
            sum=0;
        }
        return maxi;
    }
};