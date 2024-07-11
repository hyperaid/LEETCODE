class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        stack<int> st;
        vector<int> ans(nums2.size());
        int n = nums2.size();
        for (int i = 0; i < (2 * n) ; i++) {
            while (!st.empty() && nums2[st.top()%n]<nums2[i % n]) {
               ans[st.top()%n]=nums2[i%n];
                st.pop();
            }
            // if (!st.empty()) {
            //     nums2[i % n] = nums2[st.top()];
            // }
            st.push(i);
        }
        // cout<<st.size();
        while (!st.empty()) {
            if(st.top()<n){
            ans[st.top()] = -1;

            }
            st.pop();
        }
        return ans;
    }
};