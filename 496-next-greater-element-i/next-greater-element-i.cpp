class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> mpp;
        for (int i = 0; i < nums2.size(); i++) {
           if (!st.empty() && nums2[st.top()] < nums2[i]) {
                while (!st.empty() && nums2[st.top()] < nums2[i]) {
                    mpp[nums2[st.top()]] = nums2[i];
                    cout<<st.top()<<endl;
                    st.pop();
                }
           }
           st.push(i);
        }
        // cout<<st.size();
        while (!st.empty()) {
            mpp[nums2[st.top()]] = -1;
            st.pop();
        }
        vector<int> ans;
        for (auto it : nums1) {
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};