class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<int>ans;
        for(auto it:mpp){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};