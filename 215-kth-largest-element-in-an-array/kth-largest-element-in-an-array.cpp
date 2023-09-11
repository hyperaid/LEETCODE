class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> abhi;
        for(int i=0;i<nums.size();i++){
            abhi.push(nums[i]);
            if(abhi.size()>k){
                abhi.pop();
            }
        }
        return abhi.top();

    }
};