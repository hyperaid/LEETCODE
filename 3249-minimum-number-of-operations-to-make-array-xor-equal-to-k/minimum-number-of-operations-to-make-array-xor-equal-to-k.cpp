class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a=0;
        for(int i:nums){
            a^=i;
        }
        int c=a^k;
        int d=0;
        while(c!=0){
            d+=c&1;
            c>>=1;
        }
        return d;
    }
};