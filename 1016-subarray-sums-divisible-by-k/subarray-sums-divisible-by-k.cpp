class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int count=0;
        int sum=0;
        mpp[0]=1;
        // cout<<-1%2<<endl;
    
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int a=sum%k;
            if(a<0) a=k+a;
            if(mpp.find(a)!=mpp.end()){
                count+=mpp[a];
            }
            mpp[a]++;
        }
        return count;
    }
};