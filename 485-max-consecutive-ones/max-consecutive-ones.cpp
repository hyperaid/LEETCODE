class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int n=nums.size();
        int ans=0;
        //  if(n==1){
        //     if(nums[0]==1) return 1;
        //     return 0;
        // }
        // bool a=false;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                while(i<n  && nums[i]==1  ){
                    count++;
                    i++;
                }
                ans=max(ans,count);
                count=0;
            }
            else{
                count=0;
            }
        }
        // if(a== false) return 0;
        return ans;
    }
};