class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) a++;
            if(nums[i]==1) b++;
            if(nums[i]==2) c++;
        }
        if(a>b && a>c){

        }
        for(int i=0;i<a;i++){
            nums[i]=0;

        }
        for(int i=a;i<b+a;i++){
            nums[i]=1;
               
        }for(int i=b+a;i<b+a+c;i++){
            nums[i]=2;
               
        }
    }
};