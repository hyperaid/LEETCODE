#define  ll  long long
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        __int128 pre=1;
        __int128 ans=INT_MIN;
        __int128 suf=1;
        __int128 n=nums.size();
        for(int i=0;i<n;i++){
             if(pre==0) pre=1;
             if(suf==0) suf=1;
             pre*=nums[i];
             suf*=nums[n-i-1];
             ans=max({ans,pre,suf});
        }
        return (int)ans;
    }
};