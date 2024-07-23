class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>>v;
         if(nums.size()==1) 
            return nums;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) 
        {
            mp[nums[i]]++;
        }
        for(auto it:mp){
           v.push_back(it);
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
           if (a.second == b.second) 
                return a.first > b.first; 
            return a.second < b.second;
        });
        vector<int>ans;
               for(auto i: v) {
            ans.insert(ans.end(), i.second, i.first);
        }
        return ans;
    }
};