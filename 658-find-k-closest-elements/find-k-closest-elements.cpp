class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> abhi;//sabse top pe sabse bada 
        for(int i=0;i<arr.size();i++){
            abhi.push({abs(arr[i]-x),arr[i]});
            if(abhi.size()>k){
                abhi.pop();
            }
        }
        vector<int> ans;
        while(!abhi.empty()){
            ans.push_back(abhi.top().second);
            abhi.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};