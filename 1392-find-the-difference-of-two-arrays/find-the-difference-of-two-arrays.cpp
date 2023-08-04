class Solution {
private:
    vector<int> func1(vector<int>&nums1,vector<int>&nums2){
        unordered_set<int>contain;
        unordered_set<int>contains;
        for(auto it:nums2){
            contain.insert(it);
        }
        for(int x:nums1){
            if(contain.find(x)==contain.end()){
                contains.insert(x);
            }
        }
           
        return vector<int>(contains.begin(),contains.end());
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {func1(nums1,nums2),func1(nums2,nums1)};

    } 
};