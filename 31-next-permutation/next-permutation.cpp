class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        int j=n-1;
        if(n==1) return ;
        while(i>=0&&j>0){
            // if(i==0)
            // if(i==0){
            //     if(nums[i]<nums[j] ){
            //         int k=nums.size();
            //         while(--k){
            //             if(nums[i]<nums[k]){
            //                 break;
            //             }
            //         }
            //         swap(nums[i],nums[k]);
            //         reverse(nums.begin()+1,nums.end());
            //         return;
            //     }

            // }
            if(nums[i]<nums[j]){
                int k=nums.size()-1;
                while(k){
                    if(nums[i]<nums[k]){
                        break;
                    }
                    k--;
                }
                cout<<k<<endl;
                swap(nums[i],nums[k]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
            i--;
            j--;
        }
        reverse(nums.begin(),nums.end());


    }
};