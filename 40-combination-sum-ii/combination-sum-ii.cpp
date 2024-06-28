 
class Solution {
private:
void combisum(int i,vector<vector<int>> &big,vector<int>candidates, int target,vector<int>ans){
    if(i==candidates.size()){
        if(target==0){
            big.push_back(ans);
            // return;
        }
        return;
    }
    if(candidates[i]<=target){
            ans.push_back(candidates[i]);
            combisum(i+1,big,candidates,target-candidates[i], ans);
            ans.pop_back();
    }

    while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;

    combisum(i+1,big,candidates,target, ans);
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> big;
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        int i=0;
        combisum(i,big,candidates,target, ans);
        return big;

    }
};