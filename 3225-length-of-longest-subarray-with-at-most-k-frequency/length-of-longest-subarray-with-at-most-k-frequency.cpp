class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        while(i<n &&j<n){
            mpp[nums[j]]++;
            if(mpp[nums[j]]<=k){
                count=max(count,j-i+1);
                j++;
            }
            else{
                while(mpp[nums[j]]>k &&i<n){
                    mpp[nums[i]]--;
                    i++;
                }
                j++;
            }
        }
        return count;
    }
};