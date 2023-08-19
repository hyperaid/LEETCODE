// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<string> s;
//         int n=nums.size();

//         int temp=nums[0];
//         int count=1;

//         for(int i=0;i<n-1;i++){
//             if(nums[i]==nums[i+1]+1){
//                 count++;
//             }
//             else {
//                 if(count==1){
//                     s.push_back((to_stringtemp));
//                     temp=nums[i+1];
                    
//                 }
//                 else{
//                     s.push_back(temp+nums[i]);
//                     count=1;
//                     temp=nums[i+1];
//                 }
                
//             }
            
//         }
//         if((nums[n-1]-nums[n-2])==1){
//             return s;
//         }
//         else {
//             s.push_back(to_string(nums[n-1]));
//             return s;
//         }
//     }
// };
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<string> s;
        int n = nums.size();

        if (n == 0)
            return s;

        int start = nums[0];
        int end = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                if (start == end) {
                    s.push_back(to_string(start));
                } else {
                    s.push_back(to_string(start) + "->" + to_string(end));
                }
                start = end = nums[i];
            }
        }

        if (start == end) {
            s.push_back(to_string(start));
        } else {
            s.push_back(to_string(start) + "->" + to_string(end));
        }

        return s;
    }
};
