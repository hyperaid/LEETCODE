class Solution {
public:
    void NSL(vector<int>&v1,stack<pair<int,int>>&s1,vector<int>& heights){
        for(int i=0;i<heights.size();i++){
            if(s1.size()==0) v1.push_back(-1);
            else if(s1.size()>0 && s1.top().first<heights[i]) v1.push_back(s1.top().second);
            else if(s1.size()>0 && s1.top().first>=heights[i]){
                while(s1.size()>0 && s1.top().first>=heights[i] ){
                    s1.pop();
                }
                if(s1.size()==0) v1.push_back(-1);
                else v1.push_back(s1.top().second);

            }
            s1.push({heights[i],i});
        }
    }
    void NSR(vector<int>&v2,stack<pair<int,int>>&s2,vector<int>& heights){
        for(int i=heights.size()-1;i>=0;i--){
            if(s2.size()==0) v2.push_back(heights.size());
            else if(s2.size()>0 && s2.top().first<heights[i]) v2.push_back(s2.top().second);
            else {
                while(s2.size()>0 && s2.top().first>=heights[i] ){
                    s2.pop();
                }
                if(s2.size()==0) v2.push_back(heights.size());
                else v2.push_back(s2.top().second);

            }
            s2.push({heights[i],i});
        }
        reverse(v2.begin(), v2.end());

    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> v1;
        vector<int>v2;
        stack<pair<int,int>>s1;
        stack<pair<int,int>>s2;
        
        NSL(v1,s1,heights);
        NSR(v2,s2,heights);
        vector<int>width(v1.size());
        // width.push_back(-10);
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" "<<v2[i]<<endl;
            width[i]=v2[i]-v1[i]-1;
            width[i]=width[i]*heights[i];
        }
        return *max_element(width.begin(), width.end());
        // return -1;

    }
};