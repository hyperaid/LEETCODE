class Solution {
public:
    void solve(vector<bool>&vis,vector<int>&small,vector<vector<int>>&ans,vector<int>&nums){
            if(small.size()==nums.size()){
                ans.push_back(small);
                return ;
            }
            for(int i=0;i<nums.size();i++){
                if(vis[i]==false){
                    vis[i]=1;
                    small.push_back(nums[i]);
                    solve(vis,small,ans,nums);
                    vis[i]=0;
                    small.pop_back();

                }
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>small;
        int n=nums.size();
        vector<bool> vis(n,false);
        vector<vector<int>>ans;
        solve(vis,small,ans,nums);
        return ans;
    }
};