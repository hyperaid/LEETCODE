class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& small) {

        if (i == nums.size()) {
            ans.push_back(small);
            return;
        }
        small.push_back(nums[i]);
        solve(i + 1, nums, ans, small);
        small.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        solve(i + 1, nums, ans, small);
    }
 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> small;
        solve(0, nums, ans,small);
        return ans;
    }
};