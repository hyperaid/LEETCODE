class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        // for()
        vector<int>ans(n);
       for(int i=2*nums2.size()-1;i>=0;i--){
            while(!st.empty()&& st.top()<=nums2[i%n]) st.pop();

            if(i<n){
                if(!st.empty()) ans[i]=st.top();
                else{
                    ans[i]=-1;
                }
            }
            
            st.push(nums2[i%n]);


       }
       return ans;
    }
};