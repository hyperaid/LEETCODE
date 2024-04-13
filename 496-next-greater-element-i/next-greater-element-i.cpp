class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mpp;
       stack<int>st;
       for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty()&& st.top()<nums2[i]) st.pop();
            if(!st.empty()) mpp[nums2[i]]=st.top();
            else{
                mpp[nums2[i]]=-1;
            }
                st.push(nums2[i]);


       }
       vector<int>ans(nums1.size());
       int i=0;
       for(auto it:nums1){
        ans[i]=mpp[it];
        i++;
       }
       return ans;
        
    }
};