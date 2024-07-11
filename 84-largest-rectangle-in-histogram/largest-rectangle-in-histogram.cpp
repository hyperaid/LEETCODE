class Solution {
public:
    void nsr(vector<int>&v1,vector<int>& heights){
        stack<int>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                v1[st.top()]=i;
                st.pop();
            }
            st.push(i);
        
        }
        while(!st.empty()){
            v1[st.top()]=heights.size();
            st.pop();
        }

    }
    void nsl(vector<int>&v1,vector<int>& heights){
        stack<int>st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                v1[st.top()]=i;
                st.pop();
            }
            st.push(i);
        
        }
        while(!st.empty()){
            v1[st.top()]=-1;
            st.pop();
        }

    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>v1(n,-1);
        vector<int>v2(n,-1);
        int ans=INT_MIN;
        nsr(v1,heights);
        nsl(v2,heights);
        for(int i=0;i<n;i++){
            // if(v1[i]==-1 && v)
            int w=v1[i]-v2[i]-1;

            ans=max(ans,w*heights[i]);
        }
        return ans;
    }
};